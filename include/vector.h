template<typename T>
class Vector{
    T** _coordinates;
    int _dimension; 
public:
    Vector(): _coordinates(nullptr), _dimension(0){}
    Vector(int size, T value) {}
    Vector(int size, T Top, T bottom){}
};