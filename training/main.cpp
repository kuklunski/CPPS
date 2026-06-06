#include <iostream>
#include <stdexcept>

template <typename T>
T divide(T a, T b) {
    if (b == 0)
        if constexpr (std::is_same_v<T, int>)
            throw std::invalid_argument("Undefined behaviour");
    return a / b;
}

int main() {
    try {
    std::cout << divide(10, 3) << std::endl;
    std::cout << divide(10.0, 3.0) << std::endl;
    std::cout << divide(10, 0) << std::endl;
    std::cout << divide(10.0, 0.0) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    } 
    return 0;
}