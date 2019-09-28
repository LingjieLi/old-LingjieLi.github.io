#include "WeakPtr.h"
//#include "Repeater.h"
//#include "myshared_ptr.h"
using namespace std;

int main()
{
    //Repeater* xiaoming = new Repeater(3, "xiaomimg");

    SharedPtr<int> pshared = SharedPtr<int>(new int(2));
    cout << "count:" << pshared.use_count() << "\n"; //1

    SharedPtr<int> pshared1(pshared);
    cout << "count:" << pshared.use_count() << "\n"; //2

    WeakPtr<int> pweakptr = WeakPtr<int>(pshared);
    cout << "count:" << pweakptr.use_count(); //1

    WeakPtr<int> pweakptr1;
    pweakptr1 = pshared1;
    return 0;
}