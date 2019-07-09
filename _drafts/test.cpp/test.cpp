#include <iostream>
#include <stdio.h>
#include <limits>
#include <bitset>
#include <iomanip>

using namespace std;
struct
{
    long a1;
    int a2;
    short a3;
} A;

struct
{
    int a2;
    short a3;
} B;

struct
{
    short a1;
    short a2;
    short a3;
} C;

struct
{
    long a1;
    short a2;
    short a3;
} D;

struct
{
    long a1;
    short a2;
} E;
struct
{
    short a1;
    char a2;
} F;

int main()
{
    // std::cout << sizeof(long) << std::endl;
    // std::cout << sizeof(int) << std::endl;
    // std::cout << sizeof(short) << std::endl;
    // std::cout << sizeof(A) << std::endl;
    // std::cout << sizeof(B) << std::endl;
    // std::cout << sizeof(C) << std::endl;
    // std::cout << sizeof(D) << std::endl;
    // std::cout << sizeof(E) << std::endl;
    // std::cout << sizeof(F) << std::endl;

    std::cout << "[" << bitset<sizeof(int8_t) * 8>(std::numeric_limits<int8_t>::lowest())
              << "," << bitset<sizeof(int8_t) * 8>(std::numeric_limits<int8_t>::max()) << "]" << std::endl;

    int8_t num1 = 0x7F; //max
    int8_t num2 = 0xFF; //min

    std::cout << bitset<sizeof(int8_t) * 8>(num1) << dec << "\t" << num1 << std::endl;
    num1 = num1 + 1;
    std::cout << bitset<sizeof(int8_t) * 8>(num1) << dec << "\t" << num1 << std::endl;

    std::cout << bitset<sizeof(int8_t) * 8>(num2) << dec << "\t" << num2 << std::endl;
    num2 = num2 - 1;
    std::cout << bitset<sizeof(int8_t) * 8>(num2) << dec << "\t" << num2 << std::endl;
    return 1;
}
