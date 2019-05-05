## 2.Add Two Numbers
[TOC]

### Description
- 地址
[https://leetcode.com/problems/add-two-numbers/](https://leetcode.com/problems/add-two-numbers/)

- 题目

>You are given two non-empty linked lists representing two >non-negative integers. The digits are stored in reverse >order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

>You may assume the two numbers do not contain any leading zero, except the number 0 itself.

>Example:

>Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
>Output: 7 -> 0 -> 8
>Explanation: 342 + 465 = 807.

- 解析
![https://leetcode.com/problems/add-two-numbers/Figures/2_add_two_numbers.svg](https://leetcode.com/problems/add-two-numbers/Figures/2_add_two_numbers.svg)

- 步骤
 1.初始化结果链表$result&，表头设置为0
 2.初始化结果链表指针p为表头
 3.初始化l1和l2链表指针pl1和pl2
 4.初始化进位carry=0
 5.遍历链表l1和l2，直到都达到结尾
 5.1 设置val1为pl1的值，若pl1为空，则设置为0
 5.2 设置val2为pl2的值，若pl2为空，则设置为0
 5.3 更新p->next的值为(val1+val2+carry）%10
 5.4 更新carry为(val1+val2+carry)/10
 5.5更新p指针
 5.6更新pl1和pl2指针
 6.如果carry!=0,在result链表结尾追加一个节点，值为1
 7.返回结果链表result


### Wrong Solution

我直接用的两个数值相加的方法，最后扩大到`long`类型，只有**1560 / 1563 test cases passed.**.所以这道题的终极解决办法还是自己按照位数做加法。
```cpp
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
 };
```
### Good Solution

这里给出的Good Solution 时间复杂度仍然是$O(m+n)$，只是在代码上更简洁一下罢了

#### 在这份代码中，值得被借鉴的写法

- 两条链表中只要有一条还有数字，就要继续做加法。如果有一条链表没有元素了，那么它的加数就为0
	```cpp
    while (pl1 != NULL || pl2 != NULL)
        {
            int val1 = pl1 == NULL ? 0 : pl1->val;
            int val2 = pl2 == NULL ? 0 : pl2->val;
	```
- 不用每次判断链表是否为空（添加的元素是否为表头。即，使用带头结点的链表
  ```cpp
  ListNode *result = new ListNode(0)，*p = result；
  p->next = new ListNode((val1 + val2 + carry) % 10);
  p=p->next;
  return result->next;
  ```
- 判断是否需要进位的方法
  ```cpp
  carry = (val1 + val2 + carry) / 10;
  p->next = new ListNode((val1 + val2 + carry) % 10);
  
  ```
- 判断最高位是否需要进位
   ```cpp
   if(carry>0)
   {
      p->next=new ListNode(1);
   }
```

#### Solution
```cpp
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
```
### Commont
#### int,long,unsigned long,long long
| 类型 | 长度 |范围(min)|范围(max)|
|--------|--------|--------|--------|
|char		|8	|		-128|127|
|short(短整型)|16	|-32768	|32767	|
|int(整型)	|32      |-2147483648|2147483647|
|unsigned int|32|0|4294967295|
|long(长整型)	|64|-9223372036854775808        |9223372036854775807|
|unsigned long	|64|0|18446744073709551615|
|double||-1.79769e+308|1.79769e+308|
|float||-3.40282e+38|3.40282e+38|

**！没有long long 类型**
#### How to input in C++?
