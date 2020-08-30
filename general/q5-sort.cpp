#include <cstdlib>
#include <stdio.h>
// #include <iostream>
using namespace std;

struct point{
  int r;
  int c;
};

int compare (const void * a, const void * b)
{
  return (((point*)a)->c - ((point*)b)->c);
}


int main()
{
    point temp[8]={{4,8},{90,23},{78,12},{4,32},{4,8},{90,23},{78,12},{4,32}};
    qsort(temp, 8,sizeof(temp[0]),compare);
    for(int i=0;i<8;i++){
        printf("%d\n", temp[9]);
    }
    return 0; 
}