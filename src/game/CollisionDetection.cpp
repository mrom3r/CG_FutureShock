
#include "CollisionDetection.hpp"

//  updated version originally created by Igor Kroitor on 29/12/15.
//-----------------------------------------------------------------------------
// DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//         Version 2, December 2004
//
// Copyright (C) 2016 Igor Kroitor <igor.kroitor@gmail.com>
//
// Everyone is permitted to copy and distribute verbatim or modified
//         copies of this license document, and changing it is allowed as long
//         as the name is changed.
//
// DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//         TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
//
// 0. You just DO WHAT THE FUCK YOU WANT TO.
//-----------------------------------------------------------------------------
// Gilbert-Johnson-Keerthi (GJK) collision detection algorithm in 2D
// http://www.dyn4j.org/2010/04/gjk-gilbert-johnson-keerthi/
// http://mollyrocket.com/849
//-----------------------------------------------------------------------------

struct vec2 {
    float x;
    float y;
};

// Basic vector arithmetic operations

vec2 subtract(vec2 a, vec2 b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

vec2 negate(vec2 v) {
    v.x = -v.x;
    v.y = -v.y;
    return v;
}

vec2 perpendicular(vec2 v) {
    vec2 p = {v.y, -v.x};
    return p;
}

float dotProduct(vec2 a, vec2 b) { return a.x * b.x + a.y * b.y; }

float lengthSquared(vec2 v) { return v.x * v.x + v.y * v.y; }

// Triple product expansion is used to calculate perpendicular normal vectors
// which kinda 'prefer' pointing towards the Origin in Minkowski space
vec2 tripleProduct(vec2 a, vec2 b, vec2 c) {

    vec2 r{};

    float ac = a.x * c.x + a.y * c.y; // perform a.dot(c)
    float bc = b.x * c.x + b.y * c.y; // perform b.dot(c)

    // perform b * a.dot(c) - a * b.dot(c)
    r.x = b.x * ac - a.x * bc;
    r.y = b.y * ac - a.y * bc;
    return r;
}

// This is to compute average center (roughly). It might be different from
// Center of Gravity, especially for bodies with nonuniform density,
// but this is ok as initial direction of simplex search in GJK.
vec2 averagePoint(const vec2 *vertices, size_t count) {
    vec2 avg = {0.f, 0.f};
    for (size_t i = 0; i < count; i++) {
        avg.x += vertices[i].x;
        avg.y += vertices[i].y;
    }
    avg.x /= count;
    avg.y /= count;
    return avg;
}


// Get furthest vertex along a certain direction
size_t indexOfFurthestPoint(const vec2 *vertices, size_t count, vec2 d) {

    float maxProduct = dotProduct(d, vertices[0]);
    size_t index = 0;
    for (size_t i = 1; i < count; i++) {
        float product = dotProduct(d, vertices[i]);
        if (product > maxProduct) {
            maxProduct = product;
            index = i;
        }
    }
    return index;
}

// Minkowski sum support function for GJK
vec2 support(const vec2 *vertices1, size_t count1,
             const vec2 *vertices2, size_t count2, vec2 d) {

    // get furthest point of first body along an arbitrary direction
    size_t i = indexOfFurthestPoint(vertices1, count1, d);

    // get furthest point of second body along the opposite direction
    size_t j = indexOfFurthestPoint(vertices2, count2, negate(d));

    // subtract (Minkowski sum) the two points to see if bodies 'overlap'
    return subtract(vertices1[i], vertices2[j]);
}

// The GJK yes/no test
int iter_count = 0;

int gjk(const vec2 *vertices1, size_t count1,
        const vec2 *vertices2, size_t count2) {

    size_t index = 0; // index of current vertex of simplex
    vec2 a, b, c, d, ao, ab, ac, abperp, acperp, simplex[3];

    vec2 position1 = averagePoint(vertices1, count1); // not a CoG but
    vec2 position2 = averagePoint(vertices2, count2); // it's ok for GJK )

    // initial direction from the center of 1st body to the center of 2nd body
    d = subtract(position1, position2);

    // if initial direction is zero ??? set it to any arbitrary axis (we choose X)
    if ((d.x == 0) && (d.y == 0))
        d.x = 1.f;

    // set the first support as initial point of the new simplex
    a = simplex[0] = support(vertices1, count1, vertices2, count2, d);

    if (dotProduct(a, d) <= 0)
        return 0; // no collision

    d = negate(a); // The next search direction is always towards the origin, so the next search direction is negate(a)

    while (true) {
        iter_count++;

        a = simplex[++index] = support(vertices1, count1, vertices2, count2, d);

        if (dotProduct(a, d) <= 0)
            return 0; // no collision

        ao = negate(a); // from point A to Origin is just negative A

        // simplex has 2 points (a line segment, not a triangle yet)
        if (index < 2) {
            b = simplex[0];
            ab = subtract(b, a); // from point A to B
            d = tripleProduct(ab, ao, ab); // normal to AB towards Origin
            if (lengthSquared(d) == 0)
                d = perpendicular(ab);
            continue; // skip to next iteration
        }

        b = simplex[1];
        c = simplex[0];
        ab = subtract(b, a); // from point A to B
        ac = subtract(c, a); // from point A to C

        acperp = tripleProduct(ab, ac, ac);

        if (dotProduct(acperp, ao) >= 0) {

            d = acperp; // new direction is normal to AC towards Origin

        } else {

            abperp = tripleProduct(ac, ab, ab);

            if (dotProduct(abperp, ao) < 0)
                return 1; // collision

            simplex[0] = simplex[1]; // swap first element (point C)

            d = abperp; // new direction is normal to AB towards Origin
        }

        simplex[1] = simplex[2]; // swap element in the middle (point B)
        --index;
    }
}

bool CollisionDetection::check_collision(const GameObject &first, const GameObject &second) {
    float first_rotation_rad = first.rotation / 180.0f * 3.14159265358979323846f;
    glm::mat2 rotation_matrix_first{std::cos(first_rotation_rad), -std::sin(first_rotation_rad),
                                    std::sin(first_rotation_rad), std::cos(first_rotation_rad)};
    glm::vec2 rotation_first{first.rotation_point.x, first.rotation_point.y};
    glm::vec2 translation_first{first.translation.x, first.translation.y};
    std::vector<glm::vec2> tmp_points_first{};
    for (Position position: first.positions) {
        glm::vec2 tmp_point{glm::vec2{position.x, position.y}};
        tmp_point -= rotation_first;
        tmp_point = rotation_matrix_first * tmp_point + translation_first;
        tmp_point += rotation_first;
        tmp_points_first.emplace_back(tmp_point);
    }
    std::vector<vec2> vertices_first{};
    for (glm::vec2 vector: tmp_points_first) {
        vertices_first.emplace_back(vec2{vector.x, vector.y});
    }

    float rotation_rad_second = second.rotation / 180.0f * 3.14159265358979323846f;
    glm::mat2 rotation_matrix_second{std::cos(rotation_rad_second), -std::sin(rotation_rad_second),
                                     std::sin(rotation_rad_second), std::cos(rotation_rad_second)};
    glm::vec2 rotation_second{second.rotation_point.x, second.rotation_point.y};
    glm::vec2 translation_second{second.translation.x, second.translation.y};
    std::vector<glm::vec2> tmp_points_second{};
    for (Position position: second.positions) {
        glm::vec2 tmp_point{glm::vec2{position.x, position.y}};
        tmp_point -= rotation_second;
        tmp_point = rotation_matrix_second * tmp_point + translation_second;
        tmp_point += rotation_second;
        tmp_points_second.emplace_back(tmp_point);
    }
    std::vector<vec2> vertices_second{};
    for (glm::vec2 vector: tmp_points_second) {
        vertices_second.emplace_back(vec2{vector.x, vector.y});
    }

    return gjk(vertices_first.data(), vertices_first.size(), vertices_second.data(), vertices_second.size());
}
