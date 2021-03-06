// ZigzagPrint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <queue>
#include <iostream>


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int _data):
        data(_data)
        , left(nullptr)
        , right(nullptr) {}
};
using namespace std;
void printZigzag(Node* root) {

    if (root == nullptr) return;
    using namespace std;
    stack<Node*> stack1, stack2;

    stack1.push(root);

    while (!stack1.empty()|| !stack2.empty()) {

        while (!stack1.empty()) {
            auto temp = stack1.top();
            stack1.pop();
            
            if (temp == nullptr) return;

            cout << temp->data << " ";

            if (temp->right != nullptr)
                stack2.push(temp->right);

            if (temp->left != nullptr)
                stack2.push(temp->left);
        }
        cout << "\n";
        while (!stack2.empty()) {
            auto temp = stack2.top();
            stack2.pop();

            if (temp == nullptr) return;

            cout << temp->data << " ";

            if (temp->left != nullptr)
                stack1.push(temp->left);

            if (temp->right != nullptr)
                stack1.push(temp->right);
        }
        cout << "\n";
    }
}

int height(Node* root) {
    if (root == NULL)
        return 0;

    return std::max(height(root->left), height(root->right)) + 1;
}

void printlevel(Node* node, int level, bool flag) {
    if (node == nullptr)
        return;
    if (level == 1)
    {
        cout << node->data << " ";
        return;
    }
    if (flag == true) {
        printlevel(node->right, level - 1, flag);
        printlevel(node->left, level - 1, flag);
    }
    else {
        printlevel(node->left, level - 1, flag);
        printlevel(node->right, level - 1, flag);
    }
}

void printZigzag2(Node* root) {

    int h = height(root);

    int flag = true;
    for (int i = 1; i <= h; ++i) {
        printlevel(root, i, flag);
        flag = !flag;
        cout << endl;
    }

}

void printZigzag_giri(Node* root) {
    if (root == nullptr) return;
    using namespace std;
    stack<Node*> stk;
    queue<Node*> que;

    que.push(root);
    stk.push(root);

    int currentLevel = 1;
    int nxtLevel = 0;
    bool flag = true;

    while (!que.empty()) {
        Node* tmp = NULL;
        if (flag) {
            tmp = stk.top();
            cout << tmp->data << " ~ ";
            stk.pop();
        }
        else {
            tmp = que.front();
            //que.pop();
            cout << tmp->data << " ";
        }
        tmp = que.front();
        if(!que.empty())
            que.pop();
        

        --currentLevel;

        if (tmp->left != nullptr) {
            que.push(tmp->left);
            if (flag == false) {
                stk.push(tmp->left);
            }
            ++nxtLevel;
        }
        if (tmp->right != nullptr) {
            que.push(tmp->right);
            if (flag == false) {
                stk.push(tmp->right);
            }
            ++nxtLevel;
        }

        if (currentLevel == 0) {
            currentLevel = nxtLevel;
            nxtLevel = 0;
            flag = !flag;
            cout << endl;
        }
    }


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
    printZigzag(root);
    printZigzag2(root);
    getchar();
    return 0;
}

