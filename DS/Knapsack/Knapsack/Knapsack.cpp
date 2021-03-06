// Knapsack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>

using namespace std;

int weights[5] = { 1,2,5,8,9 };
int values[5] = { 1,4,8,11,15 };
int k[5][5]{ 0 };

int knapsack(int t_weight, int n) {
	if (n == 0 || t_weight == 0)
	{
		return 0;
	}

	if (weights[n - 1] > t_weight) {
		return knapsack(t_weight, n - 1);;
	}
	else {

		return std::max((values[n - 1] + knapsack(t_weight - weights[n - 1], n - 1))
			, knapsack(t_weight, n - 1));
	}
}

int knapsack2(int t_weight, int n) {
	if (n == 0 || t_weight == 0)
	{
		k[n][t_weight] = 0;
		return 0;
	}

	if (weights[n - 1] > t_weight) {
		k[n][t_weight] = knapsack(t_weight, n - 1);
	}
	else {
		k[n][t_weight] = std::max((values[n - 1] + knapsack(t_weight - weights[n - 1], n - 1))
			, knapsack(t_weight, n - 1));
	}
	return k[n][t_weight];
}

void print(int* k, int i, int j) {

}

int main()
{
	int totalweight = 14;
	int ans = knapsack2(totalweight, 5);
	cout << ans;


	getchar();
	return 0;
}

