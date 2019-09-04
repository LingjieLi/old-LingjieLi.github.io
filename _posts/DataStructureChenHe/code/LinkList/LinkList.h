#ifndef LINK_LIST_H
#define LINK_LIST_H

#include<iostream>

template <class T>
struct ListNode {
    T data;
    ListNode<T>* next = nullptr;
    ListNode(){};
    ListNode(T _data, ListNode<T>* _next = nullptr)
        : data(_data)
        , next(_next){};
};
template <class T>
class LinkList {
private:
    ListNode<T>* head;
    ListNode<T>* tail;

public:
    LinkList(/* args */);
    virtual ~LinkList();

    bool addTail(const T& val);
    bool removeTail();
    bool insertAt(int index, const T& val);
    bool removeAt(int index);

    T& getAt(int index);
    bool isEmpty();
    int getCount();
    void removeAll();

    //链表逆置
    void reverse();

    ListNode<T>* getHead() const;
    ListNode<T>* getTail() const;
    ListNode<T>* getNodeAt(int index) const;
};
template <class T>
LinkList<T>::LinkList()
{
    head = new ListNode<T>(); ///单独头结点，含有单独头结点的好处就是可以不用判断链表是否为空
    tail = head;
    tail->next = nullptr;
}
template <class T>
LinkList<T>::~LinkList()
{
    ListNode<T>* current;
    if (head != nullptr) {
        current = head;
        while (current != nullptr) {
            ListNode<T>* p;
            p = current;
            current = current->next;
            delete p;
        }
    }
    head = nullptr;
    tail = nullptr;
}

template <class T>
bool LinkList<T>::addTail(const T& val)
{
    ListNode<T>* node = new ListNode<T>(val);

    tail->next = node;
    tail = tail->next;
    tail->next = nullptr;
}

template <class T>
bool LinkList<T>::insertAt(int index, const T& val)
{
    //判断索引值是否正确
    //至少含有一个元素才可以插入
    if (index < 0 || index > getCount() - 1) {
        std::cout << "Bad position!!\n";
        return false;
    }
    /*
    ListNode<T>* node = new ListNode<T>(val);
    ListNode<T>* current = head;
    int idx = 0;
    while (idx < index - 1) {
        idx++;
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    if(current==tail){
        tail=tail->next;
    }
    return true;*/
    ListNode<T>* current = head;
    index--;
    while (index) {
        current = current->next;
        index--;
    }
    ListNode<T>* node = new ListNode<T>(val);
    node->next=current->next;
    current->next=node;
    
    if(current->next!=nullptr){
        if(current==tail){///处理尾指针
            tail=tail->next;
        }
        return true;
    }
    return false;
}

template <class T>
bool LinkList<T>::removeAt(int index)
{
    //判断索引值是否正确
    //至少含有一个元素才可以删除
    if (index < 0 || index > getCount() - 1) {
        std::cout << "Bad Position!!\n";
        return false;
    }

   /*
    ListNode<T>* current = head;
    int idx = 1;
    while (idx < index) {
        idx++;
        current = current->next;
    }
    ListNode<T>* temp = current->next->next;
    delete current->next;
    current->next = temp;
    return true;
    */
    //function 2.0
    ListNode<T> *current=head->next;
    index--;
    while(index){
        index--;
        current=current->next;
    }
    if(current!=nullptr){
        ListNode<T> *temp=current->next;
        if(temp==tail){
            tail=current;
            tail->next=nullptr;
        }else{
            current->next=current->next->next;
        }    
        delete temp;
        return true;
    }
    return false;
}

template <class T>
bool LinkList<T>::removeTail()
{
    /*
    if (head != tail) {
        ListNode<T>* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
    } else {
        std::cout << "Empty linklist\n";
        return false;
    }
    return true;
    */
    ///function 2.0
    return removeA(getCount()-1);
}

template <class T>
T& LinkList<T>::getAt(int index)
{
    if (index < 0 || index > getCount()) {
        std::cerr << "Wrong Ppsition!!\n";
    }
    /*
    ListNode<T>* current = head;
    int idx = 0;
    while (idx != index) {
        idx++;
        current = current->next;
    }
    return current->data;*/
    ///function 2.0
    ListNode<T> * current=head->next;
    while(index){
        current=current->next;
        index--;
    }
    return current->data;
};
template <class T>
bool LinkList<T>::isEmpty()
{
    return head->next == nullptr;
};
template <class T>
int LinkList<T>::getCount(){
    int count = 0;
    ListNode<T> * current = head->next;
    while (current != nullptr) {
        count++;
        current = current->next;
    } 
    return count;
}
template <class T>
void LinkList<T>::removeAll(){
    ListNode<T>* current = head->next;
    while (current != nullptr) {
        ListNode<T>* temp = current;
        current = current->next;
        delete temp;
    };
    head->next=nullptr;
    tail=head;
}
template <class T>
void LinkList<T>::reverse(){
   //头插法逆置
    if(head->next==nullptr||head->next->next==nullptr){//空表或者只有一个节点
        return;    
    } 
    ListNode<T>* pre=head->next;
    ListNode<T>* current=pre->next;
    ListNode<T>* next;
    ListNode<T>*temp_tail=head->next;
    
    while(current!=nullptr){
        next=current->next;        

        head->next=current;
        current->next=pre;
        temp_tail->next=next;

        
        std::cout<<pre->data<<"\t"<<current->data<<"\t"<<next->data<<"\n";        

        pre=current;   
        current=next;
    }
    tail=current;
    tail->next=nullptr;    
}
template <class T>
ListNode<T>* LinkList<T>::getHead() const
{
    return head;
};
template <class T>
ListNode<T>* LinkList<T>::getTail() const
{
    return tail;
};
template <class T>
ListNode<T>* LinkList<T>::getNodeAt(int index) const
{
    if (index < 0 || index > getCount()) {
        std::cerr << "Wrong Position!!\n";
        return nullptr;
    }
    int idx = 0;
    ListNode<T>* current = head;
    while (idx < index) {
        idx++;
        current = current->next;
    }
    return current;
};

#endif
