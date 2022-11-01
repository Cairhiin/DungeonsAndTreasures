#include "Vector2D.h"

namespace DungeonCats {
    Vector2D::Vector2D()
        : x(0.0f), y(0.0f) {}
    Vector2D::Vector2D(float xpos, float ypos)
        : x(xpos), y(ypos) {}

    Vector2D& Vector2D::Add(const Vector2D& vector) {
        x += vector.x;
        y += vector.y;
        return *this;
    }
    Vector2D& Vector2D::Subtract(const Vector2D& vector) {
        x -= vector.x;
        y -= vector.y;
        return *this;
    }
    Vector2D& Vector2D::Multiply(const Vector2D& vector) {
        x *= vector.x;
        y *= vector.y;
        return *this;
    }
    Vector2D& Vector2D::Divide(const Vector2D& vector) {
        x /= vector.x;
        y /= vector.y;
        return *this;
    }

    Vector2D& Vector2D::operator+=(const Vector2D& vector) {
        return this->Add(vector);
    }

    Vector2D& Vector2D::operator-=(const Vector2D& vector) {
        return this->Subtract(vector);
    }

    Vector2D& Vector2D::operator*=(const Vector2D& vector) {
        return this->Multiply(vector);
    }

    Vector2D& Vector2D::operator/=(const Vector2D& vector) {
        return this->Divide(vector);
    }

    Vector2D& Vector2D::operator*=(const int scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2D& Vector2D::Nullify() {
        x = 0.0f;
        y = 0.0f;
        return *this;
    }

    Vector2D& operator+(Vector2D& v1, const Vector2D& v2) {
        return v1.Add(v2);
    }

    Vector2D& operator-(Vector2D& v1, const Vector2D& v2) {
        return v1.Subtract(v2);
    }

    Vector2D& operator*(Vector2D& v1, const Vector2D& v2) {
        return v1.Multiply(v2);
    }

    Vector2D& operator/(Vector2D& v1, const Vector2D& v2) {
        return v1.Divide(v2);
    }

    std::ostream& operator<<(std::ostream& stream, const Vector2D& vector) {
        stream << "(" << vector.x << ", " << vector.y << ")";
        return stream;
    }
}