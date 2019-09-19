/**
* @projectName e:\LingjieLi.github.io\_posts\DataStructureChenHe\code\BinaryTree2.0
* @fileName    main.cpp
* @brief       二叉树2.0测试程序
*
* @author  lydia <vera71@126.com>
* @date    2019-06-09 21:53:45
*
**/
#include "BinaryTree.h"
int main()
{
    BinaryTree<char> bitree('a');
    bitree.insertLeftChild(bitree.getRoot(), 'D');
    bitree.insertRightChild(bitree.getRoot(), 'G');

    bitree.insertLeftChild(bitree.getRoot(), 'B');
    bitree.insertRightChild(bitree.getRoot()->lChild, 'E');

    bitree.insertRightChild(bitree.getRoot(), 'C');
    bitree.insertLeftChild(bitree.getRoot()->rChild, 'F');

    std::cout << "Empty? : " << bitree.isEmpty() << std::endl;
    std::cout << "Root data: "
              << bitree.retrieve(bitree.getRoot());

    std::cout << std::endl
              << "set root data A!";
    bitree.Assign(bitree.getRoot(), 'A');
    std::cout << "root data: "
              << bitree.retrieve(bitree.getRoot()) << std::endl;

    std::cout << "level traverse: " << std::endl;
    bitree.LevelOrderTraverse(bitree.getRoot());

    std::cout << std::endl;
    return 0;
}