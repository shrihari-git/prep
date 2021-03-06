// LongestSubsequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <algorithm>


void lcs(char* a, char* b, const int aSize, const int bSize) {

    int** lcsMatrix = new int*[aSize + 1];

    for (int i = 0; i < aSize + 1; ++i) {
        lcsMatrix[i] = new int[bSize + 1];
    }

    for (int i = 0; i <= aSize; ++i) {
        for (int j = 0; j <= bSize; ++j) {
            if (i == 0 || j == 0) {
                lcsMatrix[i][j] = 0;
            }
            else if (a[i-1] == b[j-1]) {
                lcsMatrix[i][j] = 1 + lcsMatrix[i - 1][j - 1];
            }
            else {
                lcsMatrix[i][j] = std::max(lcsMatrix[i - 1][j], lcsMatrix[i][j - 1]);
            }

        }
    }

    int length = lcsMatrix[aSize][bSize];
    char* lcsOut = new char[length + 1];

    lcsOut[length] = '\0';

    int i = aSize;
    int j = bSize;
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            lcsOut[--length] = a[i-1];
            --i;
            --j;
        }
        else if (lcsMatrix[i - 1][j] > lcsMatrix[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }


    std::cout << "LCS: String '" << lcsOut << "' Length: " << lcsMatrix[aSize][bSize] << std::endl;

}


int main()
{
    char s1[] = "abcdeea";
    char s2[] = "acdeba";
    const int s1Len = strlen(s1);
    const int s2Len = strlen(s2);

    
    lcs(s1, s2, s1Len, s2Len);
    getchar();
    return 0;
}

