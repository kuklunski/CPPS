#include "vect3.hpp"

int main()
{
    std::vector<int> vect(2, 0);
    std::cout << vect[0] << " " << vect[1] << std::endl;
    vect2 v1; // 0, 0
    std::cout << v1[0] << " " << v1[1] << std::endl;
    vect2 v2(1, 2); // 1, 2
    std::cout << v2[0] << " " << v2[1] << std::endl;

    const vect2 v3(v2); // 1, 2
    std::cout << v3[0] << " " << v3[1] << std::endl;
    vect2 v4 = v2; // 1, 2
    std::cout << v1 << v2 << v3 << v4 << std::endl;
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;

    std::cout << "v4++: ";
    std::cout << v4++ << v4 << std::endl; // 2, 3
    
    std::cout << "++v4: ";
    std::cout << ++v4 << std::endl; // 3, 4

    v4--;
    std::cout << v4 << std::endl; // 2, 3
    std::cout << --v4 << std::endl; // 1, 2
    v2 += v3; // 2, 4
    v1 -= v2; // -2, -4
    std::cout << "+=, -=\n";
    std::cout << v2 << std::endl << v1 << std::endl;
    v2 = v3 + v3 *2; // 3, 6
    std::cout << v2 << std::endl;
    v2 = 3 * v2; // 9, 18
    std::cout << v2 << std::endl;
    v2 += v2 += v3; // 20, 40
    v1 *= 42; // -84, -168
    v1 = v1 - v1 +v1;
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "-v2: " << -v2 << std::endl;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    v1[1] = 12;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    std::cout << "v3[1]: " << v3[1] << std::endl;
    std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
    std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
    std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
    std::cout << "v1 != v1: " << (v1 != v1) << std::endl;
}