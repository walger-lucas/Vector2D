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

    const static Vector2D up,down,left,right,zero;

    // Non-Static Functions to manipulate vector2Ds

    void Sum(const Vector2D& vector);
    void Subtract(const Vector2D& vector);
    const float Norm() const;
    void Normalize();
    void Invert();
    const bool EqualTo(const Vector2D& vector) const;

    //Static Functions to manipulate vector2Ds

    static Vector2D Sum(const Vector2D& vector1,const Vector2D& vector2);
    static Vector2D Subtract(const Vector2D& vector1,const Vector2D& vector2);
    static Vector2D Normalize(const Vector2D& vector);
    static Vector2D Invert(const Vector2D& vector);
    static float Distance(const Vector2D& point1,const Vector2D& point2);
    static float DotProduct(const Vector2D& vector1,const Vector2D& vector2);
    static float RadiansBetween(const Vector2D& vector1, const Vector2D& vector2);
    static Vector2D Direction(const Vector2D& point1, const Vector2D& point2);

    //Function to create string with vector data

    const std::string ToString() const;


    //Constructors
    
    Vector2D(): x(0),y(0) {};
    Vector2D(float x, float y) : x(x),y(y) {};

    
};


#endif