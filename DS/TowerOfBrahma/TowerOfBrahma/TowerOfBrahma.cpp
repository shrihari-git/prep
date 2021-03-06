// TowerOfBrahma.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Tower {
    stack<int> line;
    std::string name;
};

void TowerOfBrahma(char source, char destin, char inter, int n) {
    if(n == 0)
        return;

    TowerOfBrahma(source, inter, destin, n - 1);
    std::cout << "Moving disc " << n << " from " << source << " to " << destin << std::endl;
    TowerOfBrahma(inter, destin, source, n - 1);
    return;
}

void TowerOfBrahma_stack(Tower& source, Tower& destin, Tower& inter, int n) {
    if (n == 0)
        return;

    TowerOfBrahma_stack(source, inter, destin, n - 1);
    std::cout << "Moving disc " << n << " from " << source.name << " to " << destin.name << std::endl;
    int x = source.line.top();
    source.line.pop();
    destin.line.push(x);
    TowerOfBrahma_stack(inter, destin, source, n - 1);
    return;
}



int main()
{
    //TowerOfBrahma('A', 'B', 'C', 3);
    Tower src;
    Tower des;
    Tower buff;

    src.name = "source";
    des.name = "destination";
    buff.name = "buffer";

    src.line.push(4);
    src.line.push(3);
    src.line.push(2);
    src.line.push(1);
    TowerOfBrahma_stack(src, des, buff, 4);


    

    getchar();
    return 0;
}

