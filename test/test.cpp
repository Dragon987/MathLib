#include <iostream>

#include "./../headers/MathLib.hpp"

using namespace Math;

int main()
{
    Init();
    Vector2 v = Vector2::FromAngle(3.14);
    std::cout << v << std::endl;
    v.Set(12, 65);
    std::cout << v << std::endl;
}