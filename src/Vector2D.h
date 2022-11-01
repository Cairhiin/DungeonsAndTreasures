#pragma once

#include <iostream>

namespace DungeonCats {
    /**
     * @brief A struct for movement calculations.
     *
     * Functions:
     *
     * A default constructor and another constructor that takes
     * two arguments: a float for the x position and a float for
     * the y position.
     *
     * Overload operator for printing to a 2D vector an output stream (<<):
     * Takes two arguments, a reference to an output stream and a
     * reference to a const 2D Vector. Returns a reference to an output
     * stream.
     *
     * Add: takes a reference to a const 2D vector. Adds the vector
     * returns a reference to a 2D Vector.
     *
     * Subtract: takes a reference to a const 2D vector. Subtracts
     * the vector and returns a reference to a 2D Vector.
     *
     * Multiply: takes a reference to a const 2D vector: Multiplies by the
     * vector and returns a reference to a 2D Vector.
     *
     * Divide: takes a reference to a const 2D vector. Divides by the
     * vector and returns a reference to a 2D Vector.
     *
     * Override the addition assignment operator (+=).
     * Takes a reference to a const 2D vector and returns a reference
     * to a 2D vector after adding the vector.
     *
     * Override the subtraction assignment operator (-=).
     * Takes a reference to a const 2D vector and returns a reference
     * to a 2D vector after subtracting the vector.
     *
     * Override the multiplication assignment operator (*=).
     * Takes a reference to a const 2D vector and returns a reference
     * to a 2D vector after multiplying by the vector.
     *
     * Override the division assignment operator (/=).
     * Takes a reference to a const 2D vector and returns a reference
     * to a 2D vector after dividing by the vector.
     *
     * Override the multiplication assignment operator (*=). Takes an int
     * and returns a reference to a 2D vector after multiplying by
     * the scalar.
     *
     * Nullify: A function that sets the Vector2D object to 0. Takes no
     * arguments, and returns a reference to the (0.0f, 0.0f) vector.
     *
     * Override the addition operator (+). Takes two 2D vector objects
     * and adds them together. The second paramater is const.
     * Returns a reference to a 2D vector.
     *
     * Override the subtraction operator (-). Takes two 2D vector objects
     * and subtracts the second from the first. The second paramater is
     * const. Returns a reference to a 2D vector.
     *
     * Override the multiplication operator (*). Takes two 2D vector objects
     * and multiplies them. The second paramater is const.Returns a
     * reference to a 2D vector.
     *
     * Override the division operator (/). Takes two 2D vector objects
     * and divides the first by the second. The second paramater is const.
     * Returns a reference to a 2D vector.
     *
     * Members:
     *
     * a float for the x and a float for the y position.
     */
    struct Vector2D {
        Vector2D();
        Vector2D(float x, float y);

        friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vector);

        Vector2D& Add(const Vector2D& vector);
        Vector2D& Subtract(const Vector2D& vector);
        Vector2D& Multiply(const Vector2D& vector);
        Vector2D& Divide(const Vector2D& vector);

        Vector2D& operator+=(const Vector2D& vector);
        Vector2D& operator-=(const Vector2D& vector);
        Vector2D& operator*=(const Vector2D& vector);
        Vector2D& operator/=(const Vector2D& vector);

        Vector2D& operator*=(const int scalar);
        Vector2D& Nullify();

        friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
        friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
        friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
        friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

        float x;
        float y;
    };
}

