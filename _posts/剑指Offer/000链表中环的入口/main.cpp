/*
 * @Description: 链表中环的入口点
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-06 21:37:33
 * @Author: lydia
 * @Date: 2019-09-06 21:17:39
 */

#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
    }

    bool IsLoop(ListNode* pHead)
    {
        ListNode* fastPointer = pHead;
        ListNode* slowPointer = pHead;
        while (fastPointer != nullptr & fastPointer->next == nullptr) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            if (slowPointer == fastPointer) {
                return true;
            }
        }
        return false;
    };
};

int main()
{
    int n = 10;
    int entry = 4; //第四个是环的入口点
    vector<ListNode*> data(10, nullptr);
    data[entry] = new ListNode(4);
    data[n - 1] = new ListNode(n - 1);
    data[n - 1]->next = data[entry];

    for (int i = n - 2; i >= 0; i--) {
        data[i] = new ListNode(i);
        data[i]->next = data[i + 1];
    }

    ListNode* pHead = data[0];
    ListNode* cNode = data[0];
    while (cNode->) {
        /* code */
    }
}
