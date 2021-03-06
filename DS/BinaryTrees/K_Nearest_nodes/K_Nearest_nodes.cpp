// K_Nearest_nodes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int _data) :
        data(_data)
        , left(nullptr)
        , right(nullptr) {}
};

using namespace std;

void printDownNodes(Node* target, int k) {
    if (target == nullptr || k == -1)
        return;

    if (k == 0)
        cout << target->data << endl;

    printDownNodes(target->left, k - 1);
    printDownNodes(target->right, k - 1);
}

int printKNodes(Node* root, Node* target, int k) {
    if (target == nullptr || root == nullptr)
        return -1;

    if (target == root)
    {
        printDownNodes(root, k);
        return 0;
    }

    int l = printKNodes(root->left, target, k);
    if (l != -1) {
        if (l + 1 == k)
            cout << root->data << endl;
        else
            printDownNodes(root->right, k - (l + 1) -1);

        return l + 1;
    }

    int r = printKNodes(root->right, target, k);
    if (r != -1) {
        if (r + 1 == k)
            cout << root->data << endl;
        else
            printDownNodes(root->left, k - (r + 1) - 1);

        return r + 1;
    }

    return -1;
}

int main()
{
    auto root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    printKNodes(root, root->right->left->left, 6);
    getchar();
    return 0;
}


//         1
//    2         3
// 4    5    6     7
//8 9 10 11 12 13 14 15