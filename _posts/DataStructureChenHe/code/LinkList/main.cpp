/**************************************************************************
*
*   Copyright (C) 2019 by lydia <vera71@126.com>
*
*   All Rights Reserved
*
**************************************************************************/

/**
* @projectName e:\LingjieLi.github.io\_posts\DataStructureChenHe\code\LinkList
* @fileName    main.cpp
* @brief       单链表的测试程序
*
* @author  lydia <vera71@126.com>
* @date    2019-06-10 09:25:18
*
**/
#include"LinkList.h"

int main(){
    LinkList<char> list;
    for(char i='a';i<='m';i++){
        list.addTail(i);
        std::cout<<list.getTail()->data<<"\t";
    }
    std::cout<<"\n";
    int count=list.getCount();
    std::cout<<"length: "<<count<<std::endl;
    //print
    for(int i=0;i<count;i++){
        std::cout<<"#"<<i<<": "<<list.getAt(i)<<"\t";
    }
    std::cout<<"\n";
    std::cout<<"tail: "<<list.getTail()->data<<"\n";
    //reverse
    list.reverse();
    for(int i=0;i<count;i++){
        std::cout<<"#"<<i<<": "<<list.getAt(i)<<"\t";
    }
    std::cout<<"\n";
    std::cout<<"tail: "<<list.getTail()->data<<std::endl;
    //remove
    std::cout<<"remove #3:"<<list.removeAt(3)<<std::endl;
    //print
    count=list.getCount();
    std::cout<<"length: "<<count<<std::endl;
    for(int i=0;i<count;i++){
        std::cout<<"#"<<i<<": "<<list.getAt(i)<<"\t";
    }
    std::cout<<"\n";
    //remove tail
    list.removeAt(count-1);
    std::cout<<"remove tail -> tail: "<<list.getTail()->data<<std::endl;
    //remove all
    list.removeAll();
    std::cout<<"length:"<<list.getCount()<<std::endl;
    return 0;
}
