#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main(){

    int n;
    printf("enter rows");
    scanf("%d",&n);    

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n-i+1; ++j){
            printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}