#include <memory>
#include <iostream>

using namespace std;

static int* p = new int(2);
int main()
{
    shared_ptr<int> sh = shared_ptr<int>(p);
    cout << sh.use_count();

        return 0;
}