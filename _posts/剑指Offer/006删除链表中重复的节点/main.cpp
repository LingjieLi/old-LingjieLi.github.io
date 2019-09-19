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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == nullptr || pHead->next == nullptr) {
            return pHead;
        }
        ListNode* curNode = pHead->next;
        ListNode* lastNode = pHead;
        while (curNode != nullptr) {
            if (curNode->val == lastNode->val) {
                ListNode* temp = curNode;
                curNode = curNode->next;
                lastNode->next = curNode;
                delete temp;
            } else {
                lastNode = curNode;
                curNode = curNode->next;
            }
        }

        return pHead;
    }
};

int main()
{
    ListNode* pHead = nullptr;
    ListNode* cNode = nullptr;
    int val;
    int length = 0;
    cin >> length;
    for (int i = 0; i < length; i++) {
        cin >> val;
        if (pHead == nullptr) {
            pHead = new ListNode(val);
            cNode = pHead;
        } else {
            cNode->next = new ListNode(val);
            cNode = cNode->next;
        }
    }
    cNode = pHead;
    while (cNode != nullptr) {
        cout << cNode->val << "->";
        cNode = cNode->next;
    }
    cout << "\n";
    Solution* sol = new Solution;
    pHead = sol->deleteDuplication(pHead);
    cNode = pHead;
    while (cNode != nullptr) {
        cout << cNode->val << "->";
        cNode = cNode->next;
    }
    cout << "\n";
}