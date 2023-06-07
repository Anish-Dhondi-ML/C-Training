#include <iostream>

enum class Color {
    RED,
    GREEN,
    BLUE
};

int main() {
    Color c = Color::GREEN;
    int k = (int)c;
    std::cout<<k;
    
    switch (c) {
        case Color::RED:
            std::cout << "The color is red" << std::endl;
            break;
        case Color::GREEN:
            std::cout << "The color is green" << std::endl;
            break;
        case Color::BLUE:
            std::cout << "The color is blue" << std::endl;
            break;
        default:
            std::cout << "Unknown color" << std::endl;
            break;
    }
    
    return 0;
}
