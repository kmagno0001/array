#include <iostream>
#include "Array.hpp"

int main() {
    Arr<int, 4> array {10,20,30,40};
    Arr<int, 4> arr = array;

    std::cout << array[3] <<" " <<  array.get_len() <<"\n";
    array[3] = 8;
    for (auto i : arr) {
        std::cout << i;
    }
    
    return 0;
}