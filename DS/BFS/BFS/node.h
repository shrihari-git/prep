#pragma once
#include <vector>
#include <memory>
#include <iostream>
class Node
{

	//std::vector<std::shared_ptr<Node>> children;
public:
	Node * m_left;
	Node* m_right;
	int m_data;

	Node(int data)
		:m_data(data) {}
	//	, m_left(nullptr)
	//	, m_right(nullptr) {}
	//Node(Node* left, Node* right, int data) 
	//	:m_data(data)
	//	, m_left(left)
	//	, m_right(right) {}
	/*
	Node* getLeft() {
		return m_left;
	}
	Node* getRight() {
		return m_right;
	}*/

	/*void addChild(std::shared_ptr<Node> cN) {
		children.push_back(cN);
	}

	std::vector<std::shared_ptr<Node>> getChildren()
	{
		return children;
	}*/
	~Node() {}


	

	void print() {
		std::cout << m_data << std::endl;
		if(m_left!= nullptr) m_left->print();		
		if(m_right != nullptr) m_right->print();
		
	}
};


Node* insert(int arr[], Node* root, int i, int n)
{
	if (i < n)
	{
		Node* temp = new Node(arr[i]);
		root = temp;

		root->m_left = insert(arr,
			root->m_left, 2 * i + 1, n);

		root->m_right = insert(arr,
			root->m_right, 2 * i + 2, n);
	}
	return root;
}

