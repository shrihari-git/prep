// stairijump.cpp : Defines the entry point64_t for the console application.
//

#include "stdafx.h"
#include <iostream>

#include <vector>
#define REP(i,n) for (int i = 1; i <= n; i++)
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 3;

// computes A * B
matrix mul(matrix A, matrix B)
{
	matrix C(K + 1, vector<ll>(K + 1));
	REP(i, K) REP(j, K) REP(k, K)
		C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
	return C;
}

// computes A ^ p
matrix pow(matrix A, int p)
{
	if (p == 1)
		return A;
	if (p % 2)
		return mul(A, pow(A, p - 1));
	matrix X = pow(A, p / 2);
	return mul(X, X);
}

int stairJump_Mat(int N)
{
	// create vector F1
	vector<ll> F1(K + 1);
	F1[1] = 1;
	F1[2] = 1;
	F1[3] = 2;

	// create matrix T
	matrix T(K + 1, vector<ll>(K + 1));
	T[1][1] = 0, T[1][2] = 1, T[1][3] = 0;
	T[2][1] = 0, T[2][2] = 0, T[2][3] = 1;
	T[3][1] = 1, T[3][2] = 1, T[3][3] = 1;

	// raise T to the (N-1)th power
	if (N == 1)
		return 1;
	T = pow(T, N - 1);

	// the answer is the first row of T . F1
	ll res = 0;
	REP(i, K)
		res = (res + T[1][i] * F1[i]) % MOD;
	return res;
}


int64_t stairJump(int64_t n) {
	if (n == 0 || n == 1)
		return 1;
	if (n == 2)
		return 2;
	

	return stairJump(n - 1) + stairJump(n - 2) + stairJump(n - 3);
}


int64_t stairJump_13Arr[101] = { -1 };

int64_t stairJump_13(int64_t n) {
	if (n == 0 || n == 1)
	{
		stairJump_13Arr[n] = 1;
		return 1;
	}
	if (n == 2)
	{
		stairJump_13Arr[n] = 1;
		return 1;
	}

	/*if (n == 3) 
	{
		stairJump_13Arr[n] = 2;
		return 2;
	}*/

	if(stairJump_13Arr[n] == -1)
		stairJump_13Arr[n] = stairJump_13(n - 1) + stairJump_13(n - 3);

	return stairJump_13Arr[n];
}


//totally wrong
int64_t stairJump_giri(int64_t n) {
	if (n <= 1)
		return n;

	return stairJump_giri(n - 1) + stairJump_giri(n - 2) + stairJump_giri(n - 3);
}

void setup(int64_t* arr, int64_t size, int64_t val) {
	for (int64_t i = 0; i < size; ++i)
		arr[i] = val;
}

int main()
{
	setup(stairJump_13Arr, 101, -1 );
	//int64_t ans = stairJump_13(100);

	int arr[] = { 1,2,3,4,5,6 };
	for (int i =0; i<6; ++i)
	{
		cout <<arr[i] << " - " << stairJump_Mat(arr[i] + 1) <<endl;
	}
	cout << endl;
	for (int i = 0; i<6; ++i)
	{
		cout << arr[i] << " = " << stairJump(arr[i]) << endl;
	}
	getchar();

    return 0;
}

