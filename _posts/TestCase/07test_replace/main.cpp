#include <vector>
#include <iostream>

using namespace std;
/**
* @name    replacevector
* @brief   循环替换
*
* @parm
* @author  lydia <vera71@126.com>
* @date    2019-07-16 19:33:08
* @return
*
**/
bool replacevector(
    std::vector<uint>& vec1, int b1, int e1,
    const std::vector<uint>& vec2, int b2, int e2)
{
    if (e1 >= vec1.size() || e2 >= vec2.size() || b1 >= vec1.size() || b2 >= vec2.size()) {
        std::cout << "ERROR:e1 b1 must less than vec1 length and e2 b2 must less than vec2\n";
        // std::cout << "b1 = " << b1 << "\n"
        //           << "e1 = " << e1 << "\n"
        //           << "b2 = " << b2 << "\n"
        //           << "e2 = " << e2 << "\n"
        //           << "vec1 length:" << vec1.size() << "\n"
        //           << "vec2 length:" << vec2.size() << "\n";
        return false;
    }

    std::vector<uint>::iterator begin1 = vec1.begin() + b1, end1 = vec1.begin() + e1 + 1;
    std::vector<uint>::const_iterator begin2 = vec2.begin() + b2, end2 = vec2.begin() + e2 + 1;

    ///循环vector
    //
    std::vector<uint> subvector;
    if (b2 > e2) {
        subvector.insert(subvector.end(), begin2, vec2.end()); //vec2[begin2,vec2.end())
        subvector.insert(subvector.end(), vec2.begin(), end2); //vec2[vec2.begin(),end2)
    } else {
        subvector.insert(subvector.begin(), begin2, end2);
    }

    if (b1 > e1) {
        vec1.erase(begin1, vec1.end()); //[begin1,vec.end())
        vec1.erase(vec1.begin(), end1); //[vec.begin(),end1)
        vec1.insert(vec1.begin(), subvector.begin(), subvector.end()); //subvector[begin,end)
    } else {
        std::vector<uint>::iterator it = vec1.erase(begin1, end1); /// 移除范围[first; last) 返回指向last元素
        vec1.insert(it, subvector.begin(), subvector.end()); //pos前插入来自范围[first, last)的元素
    }

    return true;
}
int main()
{
    vector<uint> a = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<uint> b = { 0, 12, 23, 34, 45, 56, 67, 78, 89, 90, 100, 119 };

    bool res = replacevector(a, 8, 2, b, 3, 11);
    //a.insert(a.begin(), b.begin(), b.end());

    for (uint r : a) {
        std::cout << r << " ";
    }
    std::cout << "\n";
    return 0;
}