//
// Created by zack on 30/03/20.
//
#include <iostream>
using namespace std;

int Unival_trees;

class BSTNode{
    int data;
    BSTNode * left;
    BSTNode * right;

public:
    BSTNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    BSTNode * getLeftChild()
    {
        return this->left;
    }

    BSTNode* getRightChild()
    {
        return this->right;
    }

    void setLeftChild(BSTNode * left)
    {
        this->left = left;
    }

    void setRightChild(BSTNode * right)
    {
        this->right = right;
    }

    int getData()
    {
        return this->data;
    }

    void setData(int data)
    {
        this->data = data;
    }

};

bool checkUnival(BSTNode * root)
{
    if(!root->getRightChild() && root->getLeftChild())
        return root->getLeftChild()->getData() == root->getData();
    else if(!root->getLeftChild() && root->getRightChild())
        return root->getRightChild()->getData() == root->getData();
    else
    {
        bool right = root->getRightChild()->getData() == root->getData();
        bool left = root->getLeftChild()->getData() == root->getData();
        return right && left;
    }
}

bool Unival(BSTNode *root)
{
    if(!root->getLeftChild() && !root->getRightChild())
    {
        Unival_trees++;
        return true;
    }
    else if(Unival(root->getLeftChild()) && Unival(root->getRightChild()) && checkUnival(root))
    {
        Unival_trees++;
        return true;
    }
    return false;
}

int main()
{
    BSTNode left(1);
    BSTNode right(1);
    BSTNode root(1);
    root.setRightChild(&right);
    root.setLeftChild(&left);
    BSTNode leftL(1);
    BSTNode leftR(1);
    root.getLeftChild()->setLeftChild(&leftL);
    root.getLeftChild()->setRightChild(&leftR);
    BSTNode rightL(2);
    BSTNode rightR(2);
    root.getRightChild()->setLeftChild(&rightL);
    root.getRightChild()->setRightChild(&rightR);
    Unival(&root);
    cout<<"Number of Unival trees/subtrees in the binary tree is "<<Unival_trees<<'\n';
    return 0;
}

