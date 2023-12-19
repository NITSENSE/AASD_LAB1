
#include "../include/vector.h"

template<typename T>
Vector<T>::Vector(int size, T value) : _dimension(size), _coordinates(new T[size]) {
        for(int i = 0; i < size; i++){
            _coordinates[i] = value;
        }
    }
template<typename T>
Vector<T>::Vector(int size, T bottom, T top) : _dimension(size), _coordinates(new T[size]) {
    std::random_device rd;
    std::mt19937 gen(rd());

    if constexpr (std::is_integral_v<T>) {
        std::uniform_int_distribution<T> dist(bottom, top);
        for (int i = 0; i < size; i++) {
            _coordinates[i] = dist(gen);
        }
    }

    else if constexpr (std::is_floating_point_v<T>) {
        std::uniform_real_distribution<T> dist(bottom, top);
        for (int i = 0; i < size; i++) {
            _coordinates[i] = dist(gen);
        }
    }
}

template<>
Vector<std::complex<double>>::Vector(int size, std::complex<double> bottom, std::complex<double> top) : _dimension(size), _coordinates(new std::complex<double>[size]) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist_r(bottom.real(), top.real());
    std::uniform_real_distribution<double> dist_i(bottom.imag(), top.imag());
    for (int i = 0; i < size; i++) {
        _coordinates[i] = std::complex<double>(dist_r(gen), dist_i(gen));
    }
}

template<>
Vector<std::complex<float>>::Vector(int size, std::complex<float> bottom, std::complex<float> top) : _dimension(size), _coordinates(new std::complex<float>[size]) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist_r(bottom.real(), top.real());
    std::uniform_real_distribution<float> dist_i(bottom.imag(), top.imag());
    for (int i = 0; i < size; i++) {
        _coordinates[i] = std::complex<float>(dist_r(gen), dist_i(gen));
    }
}

template<typename T>
Vector<T>::~Vector() {
    delete[] _coordinates;
}

template<typename T>
const T& Vector<T>::operator[](int index) const {
    if (index >= _dimension) {
        throw std::out_of_range("Index out of range");
    }
    return _coordinates[index];
}

template<typename T>
T& Vector<T>::operator[](int index) {
    if (index >= _dimension) {
        throw std::out_of_range("Index out of range");
    }
    return _coordinates[index];
}

template<typename T>
Vector<T>::Vector(const Vector& copy) : _dimension(copy._dimention), _coordinates(new T[copy._dimention]) {
    for (int i = 0; i < _dimension; ++i) {
        _coordinates[i] = copy._coordinates[i];
    }
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
Vector<T>& Vector<T>::operator+=(const Vector<T> &other) {
    if (_dimension != other._dimension) {
        throw std::invalid_argument("Vectors dimensions do not match");
    }
    for (int i = 0; i < _dimension; i++) {
        _coordinates[i] += other._coordinates[i];
    }
    return *this;
}


template<typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& other) {
    if (_dimension != other._dimension) {
        throw std::invalid_argument("Vectors dimensions do not match");
    }
    for (int i = 0; i < _dimension; i++) {
        _coordinates[i] -= other._coordinates[i];
    }
    return *this;
}
    

template<typename T>
Vector<T>& Vector<T>::operator+(const Vector<T>& other) const {
    if (_dimension != other._dimension) {
        throw std::invalid_argument("Vectors dimensions do not match");
    }
    Vector<T> temp = *this;
    return temp += other;
}


template<typename T>
Vector<T>& Vector<T>::operator-(const Vector<T>& other) const {
    if (_dimension != other._dimension) {
        throw std::invalid_argument("Vectors dimensions do not match");
    }
    Vector<T> temp = *this;
    return temp -= other;
}


template<typename T>
T Vector<T>::operator*(const Vector<T>& other) const {
    if (_dimension != other._dimension) {
        throw std::invalid_argument("Vectors dimensions do not match");
    }
    T result = 0;
    for (int i = 0; i < _dimension; i++) {
        result += _coordinates[i] * other._coordinates[i];
    }
    return result;
}

template<typename T>
Vector<T>& Vector<T>::operator*=(const T& scalar) {
    for (int i = 0; i < _dimension; i++) {
        _coordinates[i] *= scalar;
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator*(const T& scalar) const {
    Vector<T> temp = *this;
    return temp *= scalar;
}

template<typename T>
Vector<T>& Vector<T>::operator/=(const T& scalar) {
    if (!_dimension) {
        throw std::invalid_argument("divide by zero");
    }
    for (int i = 0; i < _dimension; i++) {
        _coordinates[i] /= scalar;
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator/(const T& scalar) const {
    if (!_dimension) {
        throw std::invalid_argument("divide by zero");
    }
    Vector<T> temp = *this;
    return temp /= scalar;
}

template<typename T>
bool Vector<T>::operator==(const Vector& other) const {
    if (_dimension != other._dimension) {
        return false;
    }

    for (int i = 0; i < _dimension; ++i) {
        if (_coordinates[i] != other._coordinates[i]) {
            return false;
        }
    }

    return true;
}

template<typename T>
void Vector<T>::print() {
    for (int i = 0; i < _dimension; i++) {
        std::cout<<"Value " << i + 1 << ": " << *_coordinates[i] << std::endl;
    }
}

template<typename T>
double Vector<T>::abs() const {
    T temp = 0;
    for (int i = 0; i < _dimension; i++) {
        temp += _coordinates[i] * _coordinates[i];
    }
    return (sqrt(temp));
}


int main()
{
    Vector<float> a(4, 2, 6);
    Vector<float> b(4, 2, 6);
    std::cout << "Vector a" << std::endl;
    std::cout << a << std::endl;
    std::cout << "Vector b" << std::endl;
    std::cout << b << std::endl;
    std::cout << "Area of triangle" << std::endl;
    double abc = area(a,b);
    std::cout << abc << std::endl;
    return 0;
}
