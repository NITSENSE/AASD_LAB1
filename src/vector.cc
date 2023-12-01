#pragma once

#include "../include/vector.h"

template<typename T>
Vector<T>::Vector(int size, T value) : _dimension(size) {
        _coordinates = new T * [size];
        for(int i = 0; i < size; i++){
            *_coordinates[i] = value
        }
    }
template<typename T>
Vector<T>::Vector(int size, T Top, T bottom) : _dimension(size), _coordinates[(size)]{
        
    }
