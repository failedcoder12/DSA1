#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    printf("Enter Maximum number of nodes ");
    scanf("%d",&n);
    int h = ceil(log(n+1)/log(2));
    printf("\nHeight is %d",h);
}