
#ifndef FUTURESHOCK_COLOR_HPP
#define FUTURESHOCK_COLOR_HPP

struct Color {

    float red{0.0};
    float green{0.5f};
    float blue{1.0f};
    float alpha{1.0f};


    Color() = default;

    Color(float red, float green, float blue, float alpha = 1.0f) : red(red), green(green), blue(blue), alpha(alpha) {}
};

#endif //FUTURESHOCK_COLOR_HPP
