#pragma once
#include <iostream>
#include <complex>
#include <random>
#include <typeinfo> 
#include <math.h>
template<typename T>
class Vector{
    T* _coordinates;
    int _dimension; 
public:
    Vector() : _coordinates(nullptr), _dimension(0) {};
    Vector(int size, T value);
    Vector(int size, T bottom, T top);
    Vector(const Vector& copy);
    ~Vector();
    void Swap(Vector& other) noexcept;
    const T& operator[](int index) const;
    T& operator[](int index);
    Vector<T>& operator=(Vector<T> other);
    Vector<T>& operator+=(const Vector<T>& other);
    Vector<T>& operator-=(const Vector<T>& other);
    Vector<T>& operator+(const Vector<T>& other) const;
    Vector<T>& operator-(const Vector<T>& other) const;
    T operator*(const Vector<T>& other) const; //было Т&
    Vector<T>& operator*=(const T& scalar);
    Vector<T>& operator*(const T& scalar) const; 
    Vector<T>& operator/=(const T& scalar);
    Vector<T>& operator/(const T& scalar) const;
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const { return !(*this == other); }
    friend std::ostream& operator<<(std::ostream& os, const Vector& vector) {
        os << "(";
        for (int i = 0; i < vector._dimension; ++i) {
            os << vector._coordinates[i];
            if (i != vector._dimension - 1) {
                os << ", ";
            }
        }
        os << ")";
        return os;
    }
    double abs() const;
    void print();
};

template <typename T>
Vector<T> operator*(const T& scalar, Vector<T>& vec) {
    Vector<T> temp = vec;
    return temp *= scalar;
}

template <typename T>
double area(const Vector<T>& other, const Vector<T>& other2) {
    double corner_cos = (other2 * other) / (other2.abs() * other.abs());
    double corner_sin = sqrt(1 - (corner_cos * corner_cos));
    double left_piece = other2.abs() * other.abs();
    return left_piece * corner_sin * 0.5; 
}