#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int solve(const vector<int>& list, int m){

};

int main()
{
    int m, n;
    int n, m;
    while (cin >> n >> m) {
        vector<int> list(n);
        for (int i = 0; i < n; ++i)
            cin >> list[i];
        cout << solve(list, m) << endl;
    }
    return 0;

    // ///algorithm
    // int result = 0;
    // for (int i = 0; i < list.size(); i++) {
    //     for (int j = i + 1; j < list.size(); j++) {
    //         temp = list[i] ^ list[j];
    //         std::cout << list[i] << "\t" << list[j] << "\t" << temp << "\n";
    //         if (temp > m) {
    //             result++;
    //         }
    //     }
    // }
    // std::cout << result << "\n";

    // return 0;
}