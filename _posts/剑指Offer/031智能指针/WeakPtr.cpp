#include <memory>
#include <iostream>

using namespace std;

int main()
{
    shared_ptr<int> pshared1 = shared_ptr<int>(new int(3));
    shared_ptr<int> pshared2(pshared1);

    cout << "[1]count:" << pshared2.use_count() << "\n"; //2

    weak_ptr<int> pweak(pshared1);

    cout << "[2]count:" << pweak.use_count() << "\n"; //2

    if (!pweak.expired()) { //use_count!=0
        std::shared_ptr<int> sh_ptr2 = pweak.lock(); //get another shared_ptr
        *pshared1 = 100;
        std::cout << "[3]count:" << pweak.use_count() << std::endl; //3
    }
}