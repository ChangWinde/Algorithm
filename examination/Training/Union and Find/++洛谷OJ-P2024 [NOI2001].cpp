//  P2024 [NOI2001]食物链

#include<iostream>
#include<vector>

using namespace std;
int* tr;

int findRoot(int x){
    if(tr[x]==-1)
        return x;
    else{
        int temp = findRoot(tr[x]);
        tr[x] = temp;
        return temp;
    }
}
void merge(int x,int y){
    tr[findRoot(x)] = findRoot(y);
}
int main(){
    int n,k;
    while(cin>>n>>k&&n&&k){
        tr = new int[(n+1)*3];
        memset(tr,-1,sizeof(tr));
        int ans = 0;
        for(int i = 1;i<=k;++i){
            int mode,x,y;
            cin>>mode>>x>>y;
            if(x>n||y>n)
                ans++;
            if(mode == 1){
                if(findRoot(x)==findRoot(y+n)||findRoot(x+n)==findRoot(y)){ans++;continue;}
                merge(x,y);
                merge(x+n,y+n);
                merge(x+2*n,y+2*n);
            }else{
                if(findRoot(x)==findRoot(y)||findRoot(x+2*n)==findRoot(y)){ans++;continue;}
                merge(x,y+2*n);
                merge(x+n,y);
                merge(x+2*n,y+n);
            }
        }
        cout<<ans<<endl;
    }
}

