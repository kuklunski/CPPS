#include "bigint1.hpp"
#include <iostream>

int main()
{
    const bigint a(42);
    bigint b(21), c, d(4237), e(d);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "(c += a) = " << (c += a) << std::endl;
    std::cout << c << std::endl;
    std::cout << "(d += b) = " << (d += b) << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "++b = " << ++b << std::endl;
    std::cout << "b++ = " << b++ << std::endl;
    std::cout << "b = " << b << std::endl;

    std::cout << "(b << 10) = " << (b << 10) << std::endl;
    std::cout << "check if b keeps its value : " << b << std::endl;
    std::cout << "(b >> 1) = " << (b >> 1) << std::endl;
    std::cout << "check if b keeps its value : " << b << std::endl;
    std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
    std::cout << "check if b keeps its value : " << b << std::endl;
    std::cout << "56 + b = " << 56 + b << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
    std::cout << "check if d keeps its value : " << d << std::endl;
    std::cout << "(d >>= (const bigint)2) = " << (d >>= (const bigint)2) << std::endl;
    std::cout << "check if d keeps its value : " << d << std::endl;

    std::cout << "a = " << a << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    std::cout << "(d < a) = " << (d < a) << std::endl;
    // std::cout << "(d <= a) = " << (d <= a) << std::endl;
    std::cout << "(d > a) = " << (d > a) << std::endl;
    std::cout << "(d < a) = " << (d < a) << std::endl;
    std::cout << "we do d = 4236 which is d < e" << std::endl;
    d = 4236;
    std::cout << "(d > e) = " << (d > e) << std::endl;
    std::cout << "(d < e) = " << (d < e) << std::endl;
    std::cout << "(d == e) = " << (d == e) << std::endl;
    // d = 425800;
    // d >>= 4;
    // std::cout << "a = " << a << std::endl;
    // std::cout << "d = " << d << std::endl;
    // std::cout << "(d > a) = " << (d > a) << std::endl;
    // std::cout << "(d < a) = " << (d < a) << std::endl;
    // std::cout << "(d >= a) = " << (d >= a) << std::endl;
    // std::cout << "(d == a) = " << (d == a) << std::endl;
    // std::cout << "(d != a) = " << (d != a) << std::endl;
}