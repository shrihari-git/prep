// ReverseWords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>

void swapChars(char* a, char* b) {
    if (a == b)
        return;
    while (a < b) {
        char t = *a;
        *a = *b;
        *b = t;
        a++;
        b--;
    }
}

void reverseWords(char* s) {
    if (s == nullptr || s == '\0'
        || strlen(s) == 1)
        return;

    char *p1 = s;
    char *p2 = s + 1;

    while (*p1 != '\0') {
        
        while (*p2 != ' ' && *p2 != '\0') {
            p2++;
        }
        swapChars(p1, p2 - 1);
        if(*p2 == ' ')
            p2++;
        p1 = p2;
        
    }

    swapChars(s, p2 - 1);    

}

int main()
{
    char carr[] = "Hello my stupid box ";
    printf("\"%s\"\n", carr);
    reverseWords(carr);

    printf("Reveresed:  \"%s\"\n", carr);
    return 0;
}

