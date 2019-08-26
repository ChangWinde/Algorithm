//  合唱队形

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int h[105],dpi[105],dpd[105];

int slove(){
    for(int i = 1;i<=n;i++)
        dpi[i] = dpd[i] = 1;
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<i;j++){
            if(h[i]>h[j])
                dpi[i] = max(dpi[i],dpi[j]+1);
        }
        for(int j = n;j>n+1-i;--j){
            if(h[n+1-i]>h[j])
                dpd[n+1-i] = max(dpd[n+1-i],dpd[j]+1);
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++)
        ans = max(ans,dpi[i]+dpd[i]-1);
    return n-ans;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i = 1;i<=n;++i)
            scanf("%d",&h[i]);
        printf("%d\n",slove());
    }
}
