// RotatedSortedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void binarySearch(int* arr, int start, int end, int num) {
    int mid = (start + end) / 2;
    if (arr[mid] == num) {
        cout << " Num " << num << " found in index " << mid << endl;
        return;
    }
    if (arr[mid] < num) {
        return binarySearch(arr, mid + 1, end, num);
    }
    else {
        return binarySearch(arr, start, mid - 1, num);
    }

}
void findNumber(int* arr, int start, int end, int num) {
    if (arr[start] == num)
    {
        cout << " Num " << num << " found in index " << start<<endl;
        return;
    }
    if (arr[end] == num)
    {
        cout << " Num " << num << " found in index " << end << endl;
        return;
    }

    if (arr[end] > arr[start])
        return binarySearch(arr, start, end, num);
    
    int mid = (start + end) / 2;
    if (arr[mid] == num)
    {
        cout << " Num " << num << " found in index " << mid << endl;
        return;
    }
    
    else if (arr[mid] < num && ) {
        //the rotation is on left half
        if (arr[mid] < arr[end]) {
            binarySearch(arr, mid + 1, end, num);
        }
        //rotation on right half
        else {

        }

    }
    else if (arr[mid] > num) {

        }
}


int main()
{
    return 0;
}

