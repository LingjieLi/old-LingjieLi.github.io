/**
* @projectName e:\LingjieLi.github.io\_posts\LearnIntroAlgorithm\code\BinarySearchTree
* @fileName    main.cpp
* @brief       测试程序
*
* @author  lydia <vera71@126.com>
* @date    2019-06-09 19:56:48
*
**/

#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree t;
    t.insert(21);
    t.insert(12);
    t.insert(0);
    t.insert(35);
    t.insert(15);
    t.insert(36);
    t.insert(14);

    std::cout << (t.findMax())->data << std::endl;
    std::cout << (t.findMin())->data << std::endl;
    std::cout << (t.find(35))->data << std::endl;

    t.remove(35);
    if (t.find(35) == nullptr) {
        std::cout << "Node not exist\n";
    }
    std::cout << "is empty? " << t.isEmpty() << "\n";
    t.makeEmpty();
    std::cout << "is empty? " << t.isEmpty() << "\n";
    return 0;
}