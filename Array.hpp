#include <algorithm>

template< typename T, size_t SIZE>
class Arr {
public:
    Arr() = default;
    Arr( Arr<T, SIZE>& other);
    template< typename... Args>
    Arr( const Args... data);

    T& operator[] ( const size_t index);

    T* begin();
    T* end();

    size_t get_len();

private:
    T* data;
    const size_t length;
};

template< typename T, size_t SIZE>
Arr<T, SIZE>::Arr( Arr<T, SIZE>& other):
    data{ new T[sizeof(other)]},
    length{ other.get_len() }   
{
    for (size_t i=0; i < length; ++i) {
        data[i] = other[i];
    }
}


template< typename T, size_t SIZE>
template< typename... Args>
Arr<T, SIZE>::Arr( const Args... data):
    data{ new T[sizeof...(data)]{ std::move(data)... } },
    length{ sizeof...(data)}
{}


template< typename T, size_t SIZE>
T& Arr<T, SIZE>::operator[] ( const size_t index) {
    return this->data[index];
}

template< typename T, size_t SIZE>
T* Arr<T, SIZE>::begin() {
    return data;
}

template< typename T, size_t SIZE>
T* Arr<T, SIZE>::end() {
    return data + length;
}

template< typename T, size_t SIZE>
size_t Arr<T, SIZE>::get_len() {
    return length;
}