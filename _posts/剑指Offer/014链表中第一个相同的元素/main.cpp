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
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
    {
        int length1 = 0;
        int length2 = 0;
        ListNode* curNode = pHead1;
        while (curNode != nullptr) {
            length1++;
            curNode = curNode->next;
        }

        curNode = pHead2;
        while (curNode != nullptr) {
            length2++;
            curNode = curNode->next;
        }

        ListNode* list1 = pHead1;
        ListNode* list2 = pHead2;
        if (length1 > length2) {
            while (length1 > length2) {
                list1 = list1->next;
                length1--;
            }
        }
        if (length2 > length1) {
            while (length2 > length1) {
                list2 = list2->next;
                length2--;
            }
        }

        while (list1 != list2) {
            list1 = list1->next;
            list2 = list2->next;
        }

        return list2;
    }
};

int main()
{
    ListNode *pHead1, *pHead2;
}