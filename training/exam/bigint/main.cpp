#include "bigint.hpp"
#include <iostream>

int main(void)
{
	const bigint a(42);
	bigint b(21), c, d(1337), e(d);

	// base test
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;

	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a + c = " << a + c << std::endl;
	std::cout << "(c += a) = " << (c += a) << std::endl;

	std::cout << "b = " << b << std::endl;
	std::cout << "++b = " << ++b << std::endl;
	std::cout << "b++ = " << b++ << std::endl;

	// b = 23, b << 10 -> 23000000000 + 42 = 23000000042
	std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
	std::cout << "(d <<= 4) = " << (d <<= 4) << ", d: " << d << std::endl;
	std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << ", d: " << d << std::endl;

	std::cout << "a = " << a << std::endl; // a = 42
	std::cout << "d = " << d << std::endl; // d = 5348

	std::cout << "(d < a) = " << (d < a) << std::endl; // (d < a) = 0
	std::cout << "(d > a) = " << (d > a) << std::endl; // (d > a) = 1
	std::cout << "(d == d) = " << (d == d) << std::endl; // (d == d) = 1
	std::cout << "(d != a) = " << (d != a) << std::endl; // (d != a) = 1
	std::cout << "(d <= a) = " << (d <= a) << std::endl; // (d <= a) = 0
	std::cout << "(d >= a) = " << (d >= a) << std::endl; // (d >= a) = 1

	// extra
	bigint x(12345678); bigint y(5);
	std::cout << "(x << y) = " << (x << y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >>= y) = " << (x >>= y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

	std::cout << "x= " << (x <<= 5) << ", y= " << (y <<= 12) << std::endl;
	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

	return (0);
}

// #include "bigint2.hpp"
// #include <iostream>

// int main()
// {
//     const bigint a(42);
//     bigint b(21), c, d(4237), e(d);

//     std::cout << "(c <<= 4) = " << (c <<= 4) << std::endl;
//     std::cout << "a = " << a << std::endl;
//     std::cout << "b = " << b << std::endl;
//     std::cout << "c = " << c << std::endl;
//     std::cout << "d = " << d << std::endl;
//     std::cout << "e = " << e << std::endl;

//     std::cout << "a + b = " << a + b << std::endl;
//     std::cout << "(c += a) = " << (c += a) << std::endl;
//     std::cout << c << std::endl;
//     std::cout << "(d += b) = " << (d += b) << std::endl;
//     std::cout << "b = " << b << std::endl;
//     std::cout << "d = " << d << std::endl;
//     std::cout << "++b = " << ++b << std::endl;
//     std::cout << "b++ = " << b++ << std::endl;
//     std::cout << "b = " << b << std::endl;

//     std::cout << "(b << 10) = " << (b << 10) << std::endl;
//     std::cout << "check if b keeps its value : " << b << std::endl;
//     std::cout << "(b >> 1) = " << (b >> 1) << std::endl;
//     std::cout << "check if b keeps its value : " << b << std::endl;
//     std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
//     std::cout << "check if b keeps its value : " << b << std::endl;
//     std::cout << "56 + b = " << 56 + b << std::endl;
//     std::cout << "d = " << d << std::endl;
//     std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
//     std::cout << "check if d keeps its value : " << d << std::endl;
//     std::cout << "(d >>= (const bigint)2) = " << (d >>= (const bigint)2) << std::endl;
//     std::cout << "check if d keeps its value : " << d << std::endl;

    // std::cout << "a = " << a << std::endl;
    // std::cout << "d = " << d << std::endl;
    // std::cout << "e = " << e << std::endl;

    // std::cout << "(d < a) = " << (d < a) << std::endl;
    // // std::cout << "(d <= a) = " << (d <= a) << std::endl;
    // std::cout << "(d > a) = " << (d > a) << std::endl;
    // std::cout << "(d < a) = " << (d < a) << std::endl;
    // std::cout << "we do d = 4236 which is d < e" << std::endl;
    // d = 4236;
    // std::cout << "(d > e) = " << (d > e) << std::endl;
    // std::cout << "(d < e) = " << (d < e) << std::endl;
    // std::cout << "(d == e) = " << (d == e) << std::endl;
    // d = 425800;
    // d >>= 4;
    // std::cout << "a = " << a << std::endl;
    // std::cout << "d = " << d << std::endl;
    // std::cout << "(d > a) = " << (d > a) << std::endl;
    // std::cout << "(d < a) = " << (d < a) << std::endl;
    // std::cout << "(d >= a) = " << (d >= a) << std::endl;
    // std::cout << "(d == a) = " << (d == a) << std::endl;
    // std::cout << "(d != a) = " << (d != a) << std::endl;
//     return 0;
// }