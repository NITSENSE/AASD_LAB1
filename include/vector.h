#include <iostream>
#include <complex>
#include <random>
#include <typeinfo> 

template<typename T>
class Vector{
    T** _coordinates;
    int _dimension; 
public:
    Vector() : _coordinates(nullptr), _dimension(0) {};
    Vector(int size, T value);
    Vector(int size, T bottom, T top);
    Vector(const Vector& copy);
    void Swap(Vector& other) noexcept;
    const T& operator[](int index) const;
    T& operator[](int index);
    Vector<T>& operator=(Vector<T> other);
    Vector<T>& operator+=(const Vector<T>& other);
    Vector<T>& operator-=(const Vector<T>& other);
    Vector<T>& operator+(const Vector<T>& other) const;
    Vector<T>& operator-(const Vector<T>& other) const;
    T& operator*(const Vector<T>& other) const;
    Vector<T>& operator*=(const T& scalar);
    Vector<T>& operator*(const T& scalar) const; 
    Vector<T>& operator/=(const T& scalar);
    Vector<T>& operator/(const T& scalar) const;
    void print();
};

template <typename T>
Vector<T> operator*(const T& scalar, Vector<T>& vec) {
    Vector<T> temp = vec;
    return temp *= scalar;
}