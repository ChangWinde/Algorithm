// primeNumber  
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100000
int prime[MAX];
int psize = 1;
bool mark[MAX];
int k;
void init(){
    memset(mark,false,sizeof(mark));
    for(int i = 2;i<MAX;i++){
        if(mark[i])
            continue;
        prime[psize++] = i;
        for(int j = i*i;j<MAX;j+=i){
            mark[j] = true;
        }
    }
}
int main(){
    init();
    while(cin>>k){
        cout<<prime[k]<<endl;
    }
}