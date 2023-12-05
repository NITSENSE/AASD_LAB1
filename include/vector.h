#include <iostream>
#include <complex>
#include <random>
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
    Vector<T>&operator=(Vector<T> other);
    void print();
};

