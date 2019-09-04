#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <limits>

using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*Wrong Answer
 class Solution
 {
   public:
     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
     {
         vector<ListNode *> listNodes;
         listNodes.push_back(l1);
         listNodes.push_back(l2);
         vector<unsigned long> nums;
         nums.push_back(0);
         nums.push_back(0);

         ListNode *p = NULL;

         for (int i = 0; i < 2; i++)
         {
             p = listNodes[i];
             unsigned long par = 1;
             while (p != NULL)
             {
                 nums[i] += par * p->val;
                 par *= 10;
                 p = p->next;
             }
         }

         nums[0] += nums[1];

         string sum_str = std::to_string(nums[0]);
         ListNode *sum_list = NULL;

         delete p;
         p=NULL;
         for (int i=sum_str.size()-1;i>=0;i--)
         {
            ListNode *node = new ListNode(sum_str.at(i)-'0');
            if (sum_list == NULL)
             {
                sum_list = node;
                p = node;
             }
             else
             {
                p->next = node;
                p = p->next;
             }
         }

         return sum_list;
     }
 };*/

//Right Solution
/*class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = NULL, *pl1 = l1, *pl2 = l2, *p = NULL;
        int carry = 0; //进位
        while (pl1 != NULL && pl2 != NULL)
        {
            ListNode *node = NULL;
            std::cout<<"val1: "<<pl1->val<<" ,val2: "<<pl2->val<<std::endl;
            if (pl1->val + pl2->val + carry >= 10)
            {
                node = new ListNode(pl1->val + pl2->val + carry - 10);
                carry = 1;
            }
            else
            {
                node = new ListNode(pl1->val + pl2->val + carry);
                carry = 0;
            }
            if (result == NULL)
            {
                result = node;
                p = result;
            }
            else
            {
                p->next = node;
                p = p->next;
            }

            pl1=pl1->next;
            pl2=pl2->next;
        }

        while(pl1==NULL&&pl2!=NULL)
        {
            ListNode *node=NULL;
            if(pl2->val+carry>=10)
            {
                node= new ListNode(pl2->val + carry-10);
                carry=1;
            }
            else
            {
                node=new ListNode(pl2->val+carry);
                carry=0;
            }

            if (result == NULL)
            {
                result = node;
                p = result;
            }
            else
            {
                p->next = node;
                p = p->next;
            }

            pl2=pl2->next;
        }
        while(pl1!=NULL&&pl2==NULL)
        {
            ListNode *node = NULL;
            if (pl1->val + carry >= 10)
            {
                node = new ListNode(pl1->val + carry - 10);
                carry = 1;
            }
            else
            {
                node = new ListNode(pl1->val + carry);
                carry = 0;
            }

            if (result == NULL)
            {
                result = node;
                p = result;
            }
            else
            {
                p->next = node;
                p = p->next;
            }

            pl1=pl1->next;
        }

        if(carry==1)
        {
            ListNode *node=new ListNode(1);
            if (result == NULL)
            {
                result = node;
                p = result;
            }
            else
            {
                p->next = node;
                p = p->next;
            }
        }

        return result;
    }
};*/

//Good Solution
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode(0), *pl1 = l1, *pl2 = l2, *p = result;
        int carry = 0; //进位

        while (pl1 != NULL || pl2 != NULL)
        {
            int val1 = pl1 == NULL ? 0 : pl1->val;
            int val2 = pl2 == NULL ? 0 : pl2->val;
            p->next = new ListNode((val1 + val2 + carry) % 10);
            p=p->next;
            carry = (val1 + val2 + carry) / 10;

            if(pl1!=NULL) pl1=pl1->next;
            if(pl2!=NULL) pl2=pl2->next;
        }

        if(carry>0)
        {
            p->next=new ListNode(1);
        }

        return result->next;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << std::numeric_limits<char>::lowest() - 0 << "\t," << numeric_limits<char>::min() - 0 << "\t," << numeric_limits<char>::max() - 0 << std::endl;
    std::cout << std::numeric_limits<short>::lowest() << "\t," << numeric_limits<short>::min() << "\t," << numeric_limits<short>::max() << std::endl;
    std::cout << std::numeric_limits<int>::lowest() << "\t," << numeric_limits<int>::min() << "\t," << numeric_limits<int>::max() << std::endl;
    std::cout << std::numeric_limits<unsigned int>::lowest() << "\t," << numeric_limits<unsigned int>::min() << "\t," << numeric_limits<unsigned int>::max() << std::endl;
    std::cout << std::numeric_limits<long>::lowest() << "\t," << numeric_limits<long>::min() << "\t," << numeric_limits<long>::max() << std::endl;
    std::cout << std::numeric_limits<long long>::lowest() << "\t," << numeric_limits<long long>::min() << "\t," << numeric_limits<long long>::max() << std::endl;
    std::cout << std::numeric_limits<unsigned long>::lowest() << "\t," << numeric_limits<unsigned long>::min() << "\t," << numeric_limits<unsigned long>::max() << std::endl;
    std::cout << std::numeric_limits<double>::lowest() << "\t," << numeric_limits<double>::min() << "\t," << numeric_limits<double>::max() << std::endl;
    std::cout << std::numeric_limits<float>::lowest() << "\t," << numeric_limits<float>::min() << "\t," << numeric_limits<float>::max() << std::endl;

    string temp;
    vector<char> stack;
    //vector<vector<int>> nums;
    vector<ListNode *> listNodes;
    int num_index = 0;

    /*ListNode *tempNode=NULL;
listNodes.push_back(tempNode);
listNodes.push_back(tempNode);*/
    listNodes.resize(2);

    cin >> temp;

    ListNode *p = NULL;
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp.at(i) >= '0' && temp.at(i) <= '9')
        {
            ListNode *node = new ListNode(temp.at(i) - '0');
            if (listNodes[num_index] == NULL)
            {
                listNodes[num_index] = node;
                p = listNodes[num_index];
            }
            else
            {
                p->next = node;
                p = p->next;
            }
        }
        else if (temp.at(i) == ']')
        {
            num_index++;
            p = NULL;
        }
    }

    //输出数据
    for (int i = 0; i < 2; i++)
    {
        p = listNodes[i];
        unsigned long par = 1;
        unsigned long num = 0;
        while (p != NULL)
        {
            num += par * p->val;
            par *= 10;
            p = p->next;
        }
        cout << "num: " << num << std::endl;
    }

    ListNode *sum;
    Solution sol;
    sum = sol.addTwoNumbers(listNodes[0], listNodes[1]);

    p = sum;
    unsigned long par = 1;
    unsigned long num = 0;
    while (p != NULL)
    {
        num += par * p->val;
        par *= 10;
        p = p->next;
    }
    cout << "sum: " << num << std::endl;

    return 1;
}
