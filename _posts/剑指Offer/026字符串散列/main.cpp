#include <string>

using namespace std;

const int HASHSIZE = 100;

//并非最好的散列函数，但是比较有效的散列函数
unsigned long BKDRHash(const string& str)
{
    unsigned long seed = 31;
    unsigned long hashval = 0;

    for (int i = 0; i < str.size(); i++) {
        hashval = hashval * seed + str[i]; //无符号算数运算
    }

    return hashval % HASHSIZE;
}

//利用很小的额外开销提供了随机的散列结果，对字符串关键字的散列有明显的改进
unsigned long RSHash(const string& str)
{
    unsigned long a = 31415, b = 27183;
    unsigned long hashval = 0;
    for (int i = 0; i < str.size(); i++) {
        hashval = (hashval * a + str[i]) % HASHSIZE;
        a = a * b % (HASHSIZE - 1); //采用伪随机系数代替固定基数，并且在算法执行过程中不断产生这些系数
    }
}

int main()
{

    return 0;
}
