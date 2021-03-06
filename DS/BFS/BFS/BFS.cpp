// BFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>

#include "node.h"

using namespace std;

const int MAX = 100001;
int arr[MAX];

vector<vector<int> > adjList;

void bfs(int k) {

	queue<int> q;
	q.push(k);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		arr[v] = 1;
		for (int i = 0; i < adjList[v].size(); ++i) {
			cout << "b: " << adjList[v][i] <<endl;
			q.push(adjList[v][i]);
		}		
	}

}


void bfs_tree(Node* root) {

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		auto v = q.front();
		q.pop();

		if (arr[v->m_data] == 0) {
			arr[v->m_data] = 1;
			cout << v->m_data << endl;
			if(v->m_left!= nullptr)
				q.push(v->m_left);
			if (v->m_right != nullptr)
				q.push(v->m_right);
		}
	}
}

int main2()
{
	memset(arr, 0, MAX * sizeof(int));
	int n;
	cin >> n;
	adjList = vector<vector<int> >(n);
	int ei;
	cin >> ei;
	while (ei--) {
		int x, y;
		cin >> x >> y;
		adjList[x].push_back(y);
	}

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == 0) {
			bfs(i);
		}
	}

    return 0;
}


int main() {
	memset(arr, 0, MAX * sizeof(int));
	int n;
	cin >> n;
	int* t_arr = new int[n];
	vector<int> arr = vector<int>(n);
	for (int i = 0; i < n; ++i)
	{
		t_arr[i] = i;
	}

	Node* root = nullptr;
	root = insert(t_arr, root, 0, n);
	//root->print();
	bfs_tree(root);
	getchar();
	return 0;
}
