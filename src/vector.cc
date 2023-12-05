#pragma once
#include "../include/vector.h"

template<typename T>
Vector<T>::Vector(int size, T value) : _dimension(size) {
        _coordinates = new T * [size];
        for(int i = 0; i < size; i++){
            _coordinates[i] = new T (value);
        }
    }
template<typename T>
Vector<T>::Vector(int size, T bottom, T top) : _dimension(size){
    _coordinates = new T*[size];
    std::random_device rd;
    std::mt19937 gen(rd());

    if constexpr (std::is_integral_v<T>) {
        std::uniform_int_distribution<T> dist(bottom, top);
        for (int i = 0; i < size; i++) {
            _coordinates[i] = new T(dist(gen));
        }
    }

    else if constexpr (std::is_floating_point_v<T>) {
        std::uniform_real_distribution<T> dist(bottom, top);
        for (int i = 0; i < size; i++) {
            _coordinates[i] = new T(dist(gen));
        }
    }
}

template<>
Vector<std::complex<double>>::Vector(int size, std::complex<double> bottom, std::complex<double> top) : _dimension(size) {
    _coordinates = new std::complex<double>*[size];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist_r(bottom.real(), top.real());
    std::uniform_real_distribution<double> dist_i(bottom.imag(), top.imag());
    std::cout << bottom.real()<< top.real() << std::endl;
    for (int i = 0; i < size; i++) {
        _coordinates[i] = new std::complex<double>(dist_r(gen), dist_i(gen));
    }
}

template<>
Vector<std::complex<float>>::Vector(int size, std::complex<float> bottom, std::complex<float> top) : _dimension(size) {
    _coordinates = new std::complex<float>*[size];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist_r(bottom.real(), top.real());
    std::uniform_real_distribution<float> dist_i(bottom.imag(), top.imag());
    std::cout << bottom.real() << top.real() << std::endl;
    for (int i = 0; i < size; i++) {
        _coordinates[i] = new std::complex<float>(dist_r(gen), dist_i(gen));
    }
}

template<typename T>
const T& Vector<T>::operator[](int index) const {
    if (index >= 0 || _dimension > index) {
        return *_coordinates[index];
    }
}

template<typename T>
T& Vector<T>::operator[](int index) {
    if (index >= 0 || _dimension > index)
        return *_coordinates[index];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& copy) :
    _coordinates(new T* [copy._dimension]),
    _dimension(copy._dimension)
{
    for (int i = 0; i < _dimension; ++i)
        _coordinates[i] = new T(*copy._coordinates[i]);
}

template<typename T>
void Vector<T>::Swap(Vector<T>& other) noexcept
{
    std::swap(_dimension, other._dimension);
    std::swap(_coordinates, other._coordinates);
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T> other) {
    Swap(other);
    return *this;
}

template<typename T>
void Vector<T>::print() {
    for (int i = 0; i < _dimension; i++) {
        std::cout << *_coordinates[i] << std::endl;
    }
}


int main() {
    std::complex<float> a(3.3, 3.3);
    std::complex<float> b(20.9, 20.9);
    std::complex<float> c(10, 10);
    Vector<std::complex<float>> test(3, a, b);
    test[0] = c;
    test.print();
    std::cout << 55;
    test.print();
    return 0;
}