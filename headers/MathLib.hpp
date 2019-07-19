#pragma once

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <memory.h>

#define PI 3.14159
#define TWO_PI  6.28318
#define HALF_PI 1.57079
#define QUARTER_PI 0.78539

namespace Math
{
    //Use only once if you want to use random function properly
    void Init();

    int Map(int startVal, int startMinVal, int startMaxVal, int newMinVal, int newMaxVal);
    float Map(float startVal, float startMinVal, float startMaxVal, float newMinVal, float newMaxVal);

    int Random(int start, int stop);
    float Random(float start, float stop);

    float Radians(float degrees);
    void Radians(float *angle);

    float Degrees(float radians);
    void Degrees(float *angle);

    float Dist(float x1, float y1, float x2, float y2);
    void Dist(float *result, float x1, float y1, float x2, float y2);

    float Lerp(float val, float goal, float amt);
    
    class Vector2 {
    private:

    private:
        float components[2];

    public:
        float x, y;

    public:
        Vector2(); // 0, 0
        Vector2(float x, float y);
        inline Vector2(const Vector2 &other) { memcpy(this, (void *)&other, sizeof(Vector2)); };
 
        inline ~Vector2() {};
        

        static Vector2 Random();
        static Vector2 FromAngle(float angleRad);
        void Set(float x, float y);
        void Set(const Vector2 &other);

        float Mag();
        float MagSq();

        static float Mag(const Vector2 &vec);
        static float MagSq(const Vector2 &vec);
        
        void SetMag(float mag);
        static void SetMag(Vector2 &vec, float mag);

        void Limit(float max);
        static void Limit(Vector2 &vec, float max);

        friend Vector2 operator+(const Vector2 &first, const Vector2 &second);
        friend void operator+=(Vector2 &first, const Vector2 &second);
        friend Vector2 operator-(const Vector2 &first, const Vector2 &second);
        friend void operator-=(Vector2 &first, const Vector2 &second);
        friend Vector2 operator*(const Vector2 &vec, float scalar);
        friend void operator*=(Vector2 &vec, float scalar);
        friend Vector2 operator/(const Vector2 &vec, float scalar);
        friend void operator/=(Vector2 &vec, float scalar);
        friend std::ostream& operator<<(std::ostream &stream, const Vector2 &vec2);

        float Dist(const Vector2 &other);
        static float Dist(const Vector2 &first, const Vector2 &second);

        float Dot(const Vector2& other);
        static float Dot(const Vector2& first, const Vector2& second);

        static void Normalize(Vector2 &vec);
        void Normalize();

        float Heading();
        static float Heading(Vector2 &vec);

        void Rotate(float angleRad);
        static void Rotate(Vector2 &vec, float angleRad);

        Vector2 Lerp(const Vector2& other, float amt);
        static Vector2 Lerp(const Vector2& first, const Vector2& second, float amt);

        inline float AngleBetween(Vector2& other) { return acosf(Dot(*this, other) / 
                                                                        (this->Mag() * other.Mag())); };
        inline static float AngleBetween(Vector2& first, Vector2& second) { return acosf(Dot(first, second) / 
                                                                        (first.Mag() * second.Mag())); };

        float * Array();
    };

    std::ostream& operator<<(std::ostream &stream, const Vector2 &vec2);
    Vector2 operator+(const Vector2 &first, const Vector2 &second);
    void operator+=(Vector2 &first, const Vector2 &second);
    Vector2 operator-(const Vector2 &first, const Vector2 &second);
    void operator-=(Vector2 &first, const Vector2 &second);
    Vector2 operator*(const Vector2 &vec, float scalar);
    void operator*=(Vector2 &vec, float scalar);
    Vector2 operator/(const Vector2 &vec, float scalar);

} // namespace Math
