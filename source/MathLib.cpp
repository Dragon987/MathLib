#include <time.h>
#include <random>

#include "./../headers/MathLib.hpp"


namespace Math
{

    void Init()
    {
        unsigned int seed = static_cast<unsigned int>(time(0));
        srand(seed);
    }

    int Map(int startVal, int startMinVal, int startMaxVal, int newMinVal, int newMaxVal)
    {
        return (startVal - startMinVal) * (newMaxVal - newMinVal) / (startMaxVal - startMinVal) + newMinVal;
    }

    float Map(float startVal, float startMinVal, float startMaxVal, float newMinVal, float newMaxVal)
    {
        return (startVal - startMinVal) * (newMaxVal - newMinVal) / (startMaxVal - startMinVal) + newMinVal;
    }

    int Random(int start, int stop)
    {
        return rand() % (stop - start + 1) + start;
    }

    float Random(float min, float max)
    {
        return  (max - min) * ((((float) rand()) / (float) RAND_MAX)) + min;
    }

    float Radians(float degrees)
    {
        return PI * degrees / 180.0f;
    }

    void Radians(float *angle)
    {
        *angle = PI * (*angle) / 180.0f;
    }

    float Degrees(float radians)
    {
        return 180.0f * radians / PI;
    }

    void Degrees(float *angle)
    {
        *angle = 180.0f * (*angle) / PI;
    }

    float Dist(float x1, float y1, float x2, float y2)
    {
        return sqrtf(powf(x1 - x2, 2) + powf(y1 - y2, 2));
    }

    void Dist(float *result, float x1, float y1, float x2, float y2)
    {
        *result = sqrtf(powf(x1 - x2, 2) + powf(y1 - y2, 2));
    }

    Vector2::Vector2()
        :x(0), y(0) {}
    Vector2::Vector2(float x, float y)
        :x(x), y(y) {}

    std::ostream& operator<<(std::ostream &stream, const Vector2 &vec2)
    {
        stream << "X: " << vec2.x << ", Y: " << vec2.y;
        return stream;
    }

    Vector2 Vector2::Random()
    {
        float x = Math::Random(0.0f, 1.0f), y = Math::Random(0.0f, 1.0f);
        std:: cout << x << ' ' << y << '\n';
        return Vector2(x, y);
    }
    Vector2 Vector2::FromAngle(float angleRad)
    {
        return Vector2(cosf(angleRad), sinf(angleRad));
    }
    void Vector2::Set(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    
}