// SubsetSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int sumArray[5] = {2,3,7,8,10};
bool resArray[5][12];
bool subset(int sum, int n) {
	if (sum == 0)
	{
		return true;
	}

	if (n == 0 && sum > 0)
		return false;

	if (sumArray[n - 1] > sum)
	{
		return subset(sum, n - 1);
	}
	else
	{
		return subset(sum, n - 1) || subset(sum - sumArray[n - 1], n - 1);
	}
}

bool subset2(int sum, int n) {
	if (sum == 0)
	{
		resArray[n - 1][sum] = true;
		return true;
	}

	if (n == 0 && sum > 0)
	{
		resArray[n][sum] = false;
		return false;
	}

	if (sumArray[n - 1] > sum)
	{
		auto v = subset(sum, n - 1);
		resArray[n - 1][sum] = v;
		return v;
	}
	else
	{
		auto v = subset(sum, n - 1) || subset(sum - sumArray[n - 1], n - 1);
		resArray[n - 1][sum] = v;
		return v;
	}
}


bool dp[6][12];
int functio(int n, int sum)
{
	int i, j;


	for (i = 1; i<=n; i++)
	{
		for (j = 1; j <= sum; j++)
		{		

			if (sumArray[i - 1] > j)
			{//go to next
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - sumArray[i - 1]];
			}


		}
	}

	return dp[n][sum];
}


int functio2(int n, int sum)
{
	int i, j;
	
	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= sum; j++)
		{
			if (i == 0) {
				if (j == sumArray[i])
				{
					dp[i][j] = true;
				}
				else {
					dp[i][j] = false;
				}
				continue;
			}
			if (sumArray[i - 1] > j)
			{//go to next
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - sumArray[i - 1]];
			}


		}
	}

	return dp[n][sum];
}
int main()
{
	bool val = subset2(11, 5);
	cout << val << endl;

	/*for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 12; ++j) {
			cout << resArray[i][j] << "  ";
		}
		cout << endl << endl;
	}*/

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 12; ++j) {
			if(j==0) 
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}


	cout << functio(5, 11) << endl;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 12; ++j) {
			cout << dp[i][j] << "  ";
		}
		cout << endl;
	}
	getchar();
    return 0;
}

