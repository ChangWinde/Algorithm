//  hdu1229 还是A+B
//  %的使用

#include<stdio.h>
using namespace std;
int q = 100000000; 
int a,b,k;

int main(){
    while (scanf_s("%d%d%d",&a,&b,&k)){
        if(a==0&&b==0)break;
        if((a%q)==(b%q)){
            printf("-1\n");
        }else{
            printf("%d\n",a+b);
        }
    }
}