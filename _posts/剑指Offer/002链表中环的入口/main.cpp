/*
 * @Description: 链表中环的入口点 快慢指针法
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-07 11:17:36
 * @Author: lydia
 * @Date: 2019-09-06 21:17:39
 */

#include <vector>
#include <iostream>

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
        ListNode* firstPointer = pHead;
        ListNode* secondPointer = IsLoop(pHead);
        if (secondPointer != nullptr) {
            while (firstPointer != secondPointer) {
                firstPointer = firstPointer->next;
                secondPointer = secondPointer->next;
            }
            return firstPointer;
        } else {
            return nullptr;
        }
    }

    ListNode* IsLoop(ListNode* pHead)
    {
        ListNode* fastPointer = pHead;
        ListNode* slowPointer = pHead;
        while (fastPointer != nullptr && fastPointer->next != nullptr) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            cout << slowPointer->val << "\t" << fastPointer->val << "\n";
            if (slowPointer == fastPointer) {
                return slowPointer;
            }
        }
        return nullptr;
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
        if (i != entry) {
            data[i] = new ListNode(i);
        }
        data[i]->next = data[i + 1];
    }

    ListNode* pHead = data[0];
    ListNode* cNode = pHead;
    int round = 20;
    while (cNode != nullptr && round >= 0) {
        cout << cNode->val << "->";
        cNode = cNode->next;
        round--;
    }
    cout << cNode->val << "\n";

    Solution* sol = new Solution;
    ListNode* entrypoint = sol->EntryNodeOfLoop(pHead);
    if (entrypoint != nullptr) {
        cout << "entry: " << entrypoint->val << "\n";
    } else {
        cout << "can't loop\n";
    }
    // ListNode* meetpoint = sol->IsLoop(pHead);
    // if (meetpoint != nullptr) {
    //     cout << "meet: " << meetpoint->val << "\n";
    //     ListNode* entrypoint = sol->EntryNodeOfLoop(pHead);
    //     if (entrypoint != nullptr) {
    //         cout << "entry: " << entrypoint->val << "\n";
    //     }
    // } else {
    //     cout << "don't loop\n";
    // }

    return 0;
}
