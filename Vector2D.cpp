#include"Vector2D.h"
#include <math.h>
#include <limits>
//Direction Constants
//Up direction (0,1) vector
const Vector2D Vector2D::up = Vector2D(0,1);
//Down direction (0,-1) vector
const Vector2D Vector2D::down = Vector2D(0,-1);
//Left direction (-1,0) vector
const Vector2D Vector2D::left = Vector2D(-1,0);
//Right direction (1,0) vector
const Vector2D Vector2D::right = Vector2D(1,0);
//Zero vector (0,0) vector
const Vector2D Vector2D::zero = Vector2D(0,0);

//Functions

//Function to add two vectors
void Vector2D::Sum(const Vector2D& vector)
{
    this->x += vector.x;
    this->y += vector.y;
}
//Function to add two vectors
Vector2D Vector2D::Sum(const Vector2D& vector1,const Vector2D& vector2)
{
    return Vector2D(vector1.x+vector2.x,vector1.y+vector2.y);
}

//Function to subtract two vectors
void Vector2D::Subtract(const Vector2D& vector)
{
    this->x -= vector.x;
    this->y -= vector.y;
}
//Function to subtract two vectors
Vector2D Vector2D::Subtract(const Vector2D& vector1,const Vector2D& vector2)
{
    return Vector2D(vector1.x-vector2.x,vector1.y-vector2.y);
}
Vector2D Vector2D::Subtract(const float& num,const Vector2D& vector2)
{
    return Vector2D(num*vector2.x,num*vector2.y);
}
//Calculates norm of vector
const float Vector2D::Norm() const
{
   return std::sqrt(this->x*this->x+this->y*this->y);
}

//invert direction of Vector
void Vector2D::Invert()
{
    this->x*=-1;
    this->y*=-1;
}
//invert direction of Vector
Vector2D Vector2D::Invert(const Vector2D& vector)
{
    return Vector2D(-vector.x,-vector.y);
}

//Normalizes vector
void Vector2D::Normalize()
{
    float norm = this->Norm();
    //if norm is equal to zero, do nothing
    if(norm !=0)
    {
        this->x/=norm;
        this->y/=norm;
    }
}
//Normalizes vector
Vector2D Vector2D::Normalize(const Vector2D& vector)
{
    float norm = vector.Norm();
    if(norm!=0)
    {
        return Vector2D(vector.x/norm,vector.y/norm);
    }
    return Vector2D::zero;

}

//distance value between two points(vector2d)
float Vector2D::Distance(const Vector2D& point1,const Vector2D& point2)
{
    Vector2D vec = Vector2D::Subtract(point2,point1);
    return vec.Norm();
}

//Calculates the dot product of two vectors
float Vector2D::DotProduct(const Vector2D& vector1,const Vector2D& vector2)
{
    return vector1.x*vector2.x + vector1.y*vector2.y;
}

//returns the smallest angle, in radians between 2 vectors, NULL if undefined.
float Vector2D::RadiansBetween(const Vector2D& vector1,const Vector2D& vector2)
{
    //follows the equation cos(teta)*normProduct = dotProduct
    float dotProduct = Vector2D::DotProduct(vector1,vector2);
    float normProduct = vector1.Norm()*vector2.Norm();
    //if neither of the vectors have Norm = zero;
    if(normProduct!=0)
    {
        return std::acos(dotProduct/normProduct);
    }
    return -std::numeric_limits<float>::max();
}
//returns normalized vector with direction from point1 to point2
Vector2D Vector2D::Direction(const Vector2D& point1,const Vector2D& point2)
{
    Vector2D vec = Vector2D::Subtract(point2,point1);
    vec.Normalize();
    return vec;
}

//returns true if vector is equal to the vector that called function
const bool Vector2D::EqualTo(const Vector2D& vector) const
{
    if(this->x==vector.x && this->y ==vector.y)
        return true;
    return false;
}

//Returns string with value of vector in "(x,y) format"
const std::string Vector2D::ToString() const
{
    return "("+std::to_string(this->x)+","+std::to_string(this->y)+")";
}



