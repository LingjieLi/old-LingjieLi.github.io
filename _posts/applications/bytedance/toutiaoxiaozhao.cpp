#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> list;
    int num;

    string line;
    stringstream ss;
    getline(cin, line);
    ss.str("");
    ss.clear();
    ss.str(line);
    ss >> num;

    getline(cin, line);
    ss.str("");
    ss.clear();
    ss.str(line);
    int tmp;
    while (ss >> tmp) {
        list.push_back(tmp);
    }

    sort(list.begin(), list.end()); //从小到大

    int result = 0;
    int size = 1;
    int i = 1;
    int last = list.size() - 1;
    for (; i < list.size();) {
        //std::cout << size << "\t" << i << "\n";
        if (size == 0) {
            if (i == last) { //尾部,补两个
                result += 2;
                size += 3;
                i++;
            } else {
                size++;
                i++;
            }
        } else if (size == 1) {
            if (i == last) { //尾部
                if (list[i] - list[i - 1] <= 20) { //
                    result += 1;
                    size += 2;
                    i++;
                }
            } else {
                if (list[i] - list[i - 1] <= 10) {
                    size++;
                    i++;
                } else if (list[i] - list[i - 1] > 10 && list[i] - list[i - 1] <= 20) { //插入1个数字
                    result += 1;
                    size += 2;
                    i++;
                } else { //插入2个数字
                    result += 2;
                    size += 2;
                }
            }
        } else if (size == 2) {
            if (i == last) { //尾部
                if (list[i] - list[i - 1] <= 10) {
                    size++;
                    i++;
                } else {
                    result = result + 1 + 2; //插入1个+追加2个
                    size += 1;
                    i++;
                }
            } else {
                if (list[i] - list[i - 1] <= 10) {
                    size++;
                    i++;
                } else if (list[i] - list[i - 1] > 10) { //插入1个元素
                    result += 1;
                    size++;
                }
            }
        } else if (size == 3) {
            size = 0;
        }
    }

    std::cout << result << "\n";
    return 1;
}
