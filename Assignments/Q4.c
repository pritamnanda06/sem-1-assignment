#include<stdio.h>
//no of ways n no of matrices can be multiplied.

int countWays(int n);

int main(){
    int n;
    printf("Enter no of matrices");
    scanf("%d",&n);

    int result=countWays(n);
    printf("No of ways to multiply %d matrices is %d\n",n,result);
    return 0;

}

int countWays(int n){
    if(n<=1){
        return 1;
    }
    int ways=0;
    for(int i=1;i<n;i++){
        int leftWays=countWays(i);
        int rightWays=countWays(n-i);
        ways+=leftWays*rightWays;
    }
    return ways;
}