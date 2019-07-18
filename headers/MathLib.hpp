#pragma once

#include <iostream>
#include <math.h>

#define PI 3.14159265359
#define TWO_PI  6.28318530718
#define HALF_PI 1.57079632679
#define QUARTER_PI 0.78539816339

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
    
    class Vector2 {
    private:

    private:

    public:
        float x, y;

    public:
        Vector2(); // 0, 0
        Vector2(float x, float y);
 
        inline ~Vector2() {};

        static Vector2 Random();
        static Vector2 FromAngle(float angleRad);
        void Set(float x, float y);

        float Mag();
        float MagSq();
        void Mag(float &result); 
        void MagSq(float &result);
        void SetMag(float mag);

        Vector2 operator+(const Vector2 &other);
        Vector2 operator-(const Vector2 &other);
        Vector2 operator*(const float &scalar);
        Vector2 operator*(float scalar);

        friend std::ostream& operator<<(std::ostream &stream, const Vector2 &vec2);

        static float Dist(const Vector2 &first, const Vector2 &second);
        static void Dist(const Vector2 &first, const Vector2 &second, float &result);

        float Dist(const Vector2 &other);
        void Dist(const Vector2 &first, float &result);

        static Vector2 Dot(const Vector2& first, const Vector2& second);        
        static void Dot(Vector2 &result, const Vector2& first, const Vector2& second);

        Vector2 Dot(const Vector2& other);        
        void Dot(Vector2 &result, const Vector2& other);

        static Vector2 Cross(const Vector2& first, const Vector2& second);        
        static void Cross(Vector2 &result, const Vector2& first, const Vector2& second);

        Vector2 Cross(const Vector2& other);        
        void Cross(Vector2 &result, const Vector2& other);

        static void Normalize(Vector2 &vec);
        void Normalize();

        static void Limit(Vector2 &vec);
        void Limit();

        static float Heading(Vector2 &vec);
        float Heading();

        static void Rotate(Vector2 &vec, float angleRad);
        void Rotate(float angleRad);

        static void Lerp(Vector2 &result, const Vector2& first, const Vector2& second);
        static Vector2 Lerp(const Vector2& first, const Vector2& second);

        void Lerp(Vector2 &result, const Vector2& other);
        Vector2 Lerp(const Vector2& other);

        static float AngleBetween(const Vector2& first, const Vector2& second);
        float AngleBetween(const Vector2& other);

        static float * Array(const Vector2& vec);
        float * Array();
    };

    std::ostream& operator<<(std::ostream &stream, const Vector2 &vec2);

} // namespace Math
