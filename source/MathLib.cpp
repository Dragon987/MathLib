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

    float Lerp(float val, float goal, float amt)
    {
        return (1.0f - amt) * val + amt * goal;
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
        stream << "[" << vec2.x << ", " << vec2.y << ']';
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
    void Vector2::Set(const Vector2 &vec)
    {
        this->x = vec.x;
        this->y = vec.y;
    }

    float Vector2::Mag()
    {
        return sqrtf(x * x + y * y);
    }

    float Vector2::MagSq()
    {
        return x * x + y * y;
    }
        
    float Vector2::Mag(const Vector2 &target)
    {
        return sqrtf(target.x * target.x + target.y * target.y);
    }

    float Vector2::MagSq(const Vector2 &target)
    {
        return target.x * target.x + target.y * target.y;
    }

    void Vector2::SetMag(float max)
    {
        *this *= max / Mag();
    }

    void Vector2::SetMag(Vector2 &target, float max)
    {
        target *= max / target.Mag();
    }


    void Vector2::Limit(float max)
    {
        if (Mag() > max)
        {
            Normalize();
            *this *= max;
        }
    }

    void Vector2::Limit(Vector2 &target, float max)
    {
        if (target.Mag() > max)
        {
            target.Normalize();
            target *= max;
        }
    }

    Vector2 operator+(const Vector2 &first, const Vector2 &second)
    {
        return Vector2(first.x + second.x, first.y + second.y);
    }

    void operator+=(Vector2 &first, const Vector2 &second)
    {
        first = first + second;
    }

    Vector2 operator-(const Vector2 &first, const Vector2 &second)
    {
        return Vector2(first.x - second.x, first.y - second.y);
    }

    void operator-=(Vector2 &first, const Vector2 &second)
    {
        first = first - second;
    }

    Vector2 operator*(const Vector2 &vec, float scalar)
    {
        return Vector2(vec.x * scalar, vec.y * scalar);
    }

    void operator*=(Vector2 &vec, float scalar)
    {
        vec = vec * scalar;
    }

    Vector2 operator/(const Vector2 &vec, float scalar)
    {
        return Vector2(vec.x / scalar, vec.y / scalar);
    }

    void operator/=(Vector2 &vec, float scalar)
    {
        vec = vec / scalar;
    }
    
    void Vector2::Normalize(Vector2 &vec)
    {
        vec /= vec.Mag();
    }
    void Vector2::Normalize()
    {
        *this /= Mag();
    }

    float Vector2::Dist(const Vector2 &other)
    {
        return sqrtf(powf(x - other.x, 2) + powf(y - other.y, 2));
    }

    float Vector2::Dist(const Vector2 &first, const Vector2 &second)
    {
        return sqrtf(powf(first.x - second.x, 2) + powf(first.y - second.y, 2));
    }

    float Vector2::Dot(const Vector2& other)
    {
        return x * other.x + y * other.y;
    }

    float Vector2::Dot(const Vector2& first, const Vector2& second)
    {
        return first.x * second.x + first.y * second.y;
    }

    float Vector2::Heading()
    {
        return -1.0f * (atan2f(-y, x));
    }

    float Vector2::Heading(Vector2 &vec)
    {
        return -1.0f * (atan2f(-vec.y, vec.x));
    }

    void  Vector2::Rotate(float angleRad)
    {
        x = cosf(angleRad) * x - sinf(angleRad) * y;
        y = sinf(angleRad) * x + cosf(angleRad) * y;
    }

    void  Vector2::Rotate(Vector2 &vec, float angleRad)
    {
        vec.x = cosf(angleRad) * vec.x - sinf(angleRad) * vec.y;
        vec.y = sinf(angleRad) * vec.x + cosf(angleRad) * vec.y;
    }

    float * Vector2::Array()
    {
        components[0] = x;
        components[1] = y;
        return components;
    }

    Vector2 Vector2::Lerp(const Vector2& other, float alpha)
    {
        Vector2 rv = *this;
        rv.x = Math::Lerp(x, other.x, alpha);
        rv.y = Math::Lerp(y, other.y, alpha);
        return rv;
    }

    Vector2 Vector2::Lerp(const Vector2& first, const Vector2& second, float alpha)
    {
        return Vector2(Math::Lerp(first.x, second.x, alpha), Math::Lerp(first.y, second.y, alpha));
    }
}