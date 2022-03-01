#ifndef VECTOR2D_H
#define VECTOR2D_H
#include<string>

/**
 * @brief Struct to store a 2 dimensional float vector, for the purpose to manipulate it easily
 * @details Struct has x and y components and Functions to manipulate them
 * @author Lucas Walger do Nascimento
 */
struct Vector2D
{
    //Horizontal (x) and Vertical(y) components of vector
    float x,y; 

    //direction constants
    const static Vector2D up,down,left,right,upRight,upLeft,downLeft,downRight,zero;

    // Non-Static Functions to manipulate vector2Ds
    //sums vectors with vector math
    void Sum(const Vector2D& vector);
    //subtracts vectors with vector math
    void Subtract(const Vector2D& vector);
    //gets norm of a vector
    const float Norm() const;
    //normalizes a vector
    void Normalize();
    //inverts vector
    void Invert();
    //tests to see if 2 vectors have the same variables
    const bool EqualTo(const Vector2D& vector) const;

    //Static Functions to manipulate vector2Ds
    //returns sum of 2 vectors
    static Vector2D Sum(const Vector2D& vector1,const Vector2D& vector2);
    //returns subtraction of 2 vectors
    static Vector2D Subtract(const Vector2D& vector1,const Vector2D& vector2);
    //returns multiplication of vector by scalar
    static Vector2D Multiply(const float& scalar,const Vector2D& vector2);
    //returns vector normalized
    static Vector2D Normalize(const Vector2D& vector);
    //returns inverted vector
    static Vector2D Invert(const Vector2D& vector);
    //returns distance between 2 points
    static float Distance(const Vector2D& point1,const Vector2D& point2);
    //returns dot product of 2 vectors
    static float DotProduct(const Vector2D& vector1,const Vector2D& vector2);
    //returns angle between vectors in radians
    static float RadiansBetween(const Vector2D& vector1, const Vector2D& vector2);
    //returns the vector direction from point a to point b
    static Vector2D Direction(const Vector2D& point1, const Vector2D& point2);

    //Function to create string with vector data
    const std::string ToString() const;

    // Member Operators
    
    Vector2D operator+(const Vector2D& vec) const; //sum operation
    Vector2D operator-(const Vector2D& vec) const; //subtraction operation
    Vector2D operator-() const; //sign inversion operation
    Vector2D operator/(const float& scalar) const; //division operation
    bool operator==(const Vector2D& vec) const; //is equal operation
    bool operator!=(const Vector2D& vec) const; //is unequal operation
    void operator=(const Vector2D& vec); //equate operation
    void operator-=(const Vector2D& vec); // subtract by vec operation
    void operator+=(const Vector2D& vec); // sum by vec operation
    void operator*=(const float& scalar); //multiply by scalar operation
    void operator/=(const float& scalar); //divide by scalar operation
    
    //Constructors 
    Vector2D(): x(0),y(0) {};
    //constructs with x and y components
    Vector2D(float x, float y) : x(x),y(y) {};
};

//Non-Member Operations
//* operation multiplies by scalar. commutative
Vector2D operator*(const Vector2D& vec,const float& scalar);
//* operation multiplies by scalar. commutative
Vector2D operator*(const float& scalar,const Vector2D& vec);



#endif
