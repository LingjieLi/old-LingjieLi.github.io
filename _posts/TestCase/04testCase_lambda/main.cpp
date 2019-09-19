#include <iostream>
#include <algorithm>

using namespace std;
int main()
{

    cout << "Test lambda with capture and parameter:\n";
    int test_data[] = { 1, 5, 9, 7, 3, 19, 13, 17 };
    int border = 8;
    auto f3 = [border](const int& i) { int esp=2; if(i-esp > border) cout<<i<<'\t'; };
    for_each(begin(test_data), end(test_data), f3);
    cout << endl;

    cout << "Test lambda with capture reference:\n";
    auto f4 = [&border](const int& i) { if(i > border) cout<<i<<'\t'; };
    border = 6;
    for_each(begin(test_data), end(test_data), f4);
    cout << endl;

    return 1;
}