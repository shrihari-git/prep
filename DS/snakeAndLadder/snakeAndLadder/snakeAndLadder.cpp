// snakeAndLadder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <iostream>

using namespace std;

const int MAX = 100;
int moves[MAX];

struct queueEntry
{
	int vertex;
	int vertexDiceDistance;
};

int snakeAndLadder(int n) {
	bool *arr = new bool[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = false;
	}

	queue<queueEntry> q;
	

	queueEntry src={ 0,0 };
	q.push(src);
	arr[0] = true;
	
	queueEntry tracker;
	while (!q.empty()) {
		
		tracker = q.front();
		q.pop();
		int vert = tracker.vertex;
		if (vert == n - 1)
			break;

		for (int i = vert + 1; i < (vert + 6) && i < n; ++i) {
			if (arr[i] == false) {
				arr[i] = true;
				queueEntry temp;
				if (moves[i] == -1) {
					temp.vertex = i;
				}
				else {
					temp.vertex = moves[i];
				}
				temp.vertexDiceDistance = tracker.vertexDiceDistance + 1;
				q.push(temp);
			}
		}

	}
	return tracker.vertexDiceDistance;
}



int main()
{
	int n = 30;
	for (int i = 0; i < n; ++i) {
		moves[i] = -1;
	}

	moves[2] = 22;
	moves[8] = 15;
	moves[16] = 28;

	moves[19] = 4;
	moves[14] = 3;

	
	cout << snakeAndLadder(n);
	
	getchar();
    return 0;
}

