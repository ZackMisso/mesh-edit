#pragma once

#include <iostream>

namespace mesh_edit
{

struct Vec3
{
    Vec3()
    {
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }

    Vec3(double x, double y, double z) : x(x), y(y), z(z) { }

    Vec3(const Vec3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    Vec3 operator+(const Vec3& other)
    {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 operator-(const Vec3& other)
    {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    double x;
    double y;
    double z;
}

}
