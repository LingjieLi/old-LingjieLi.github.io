#include <iostream>
#include <vector>
#include "sort.h"

using namespace std;

int main()
{
    char test_case[] = {'S', 'O', 'R', 'T', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int length = 11;
    for(uint i=0;i<length;i++){
        std::cout<<test_case[i]<<"\t";
    }
    std::cout<<std::endl;

    std::cout<<"quick sort: \n";
    Sort::quick_sort<char>( test_case, length );

    return 1;
}
