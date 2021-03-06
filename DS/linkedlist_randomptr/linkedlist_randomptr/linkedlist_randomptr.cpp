// linkedlist_randomptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct node {
    int data;
    node* next;
    node* random;
    node() :data(-1), next(nullptr), random(nullptr) {}
    node(int _data) :data(_data), next(nullptr), random(nullptr) {}
};

void addAtEnd(node* head, node* nextNode) {
    if (head == nullptr)
    {
        head = nextNode;
        return;
    }

    auto temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = nextNode;
}

void addAtEnd(node* head, int d) {
    node* nextNode = new node(d);
    addAtEnd(head, nextNode);
}

node* copy(node* src) {
    if (src == nullptr){
        return nullptr;
    }
    
    node* dest = new node();
    dest->data = src->data;
    dest->next = copy(src->next);

    return dest;
}

node* mergeNodes(node* src, node* dest) {
    node* returnlist = src;
    node* temp1 = nullptr;
    node* temp2 = nullptr;

    while (src != nullptr
        && dest != nullptr) {
        temp1 = src->next;
        src->next = dest;
        temp2 = dest->next;
        dest->next = temp1;

        src = temp1;
        dest = temp2;
    }
    return returnlist;
}

void assignRandom(node* src) {
    while (src != nullptr) {
        if(src->random)
            src->next->random = src->random->next;
        src = src->next->next;
    }
}

//1->2->3->n
//x->y->z->n
node* copy_random(node* src) {
    node* dest = copy(src);
    src = mergeNodes(src, dest);
    assignRandom(src);
    //1->x->2->y->3->z->n
    while (src != nullptr) {
        auto temp = src->next;
        src->next = temp->next;
        src = src->next;
        if(temp->next != nullptr)
            temp->next = temp->next->next;
    }

    

    return dest;

}

void printrandom(node* head) {
    std::cout << "Printing Random: ";
    while (head != nullptr) {
        if (head->random == NULL) {
            std::cout << "NULL -> ";
        }
        else {
            std::cout << head->random->data << " -> ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

void print(node* head) {
    printrandom(head);
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}


int main()
{
    node* a = new node(1);
    addAtEnd(a,2);
    addAtEnd(a,3);
    addAtEnd(a,4);
    addAtEnd(a,5);

    a->random = a->next->next;
    a->next->random = a->next;
    a->next->next->random = a;
    a->next->next->next->next->random = a->next;

    node* b = nullptr;
    print(a);
    print(b);
    b = copy_random(a);
    print(a);
    print(b);
    getchar();
    return 0;
}