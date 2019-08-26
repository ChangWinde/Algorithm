//  UVA1395 苗条的生成树 Slim Span
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<int> u,v,w,q,t;
int findRoot(int x){return t[x]==x?x:findRoot(t[x]);}

bool cmp(int x,int y){return w[x]<w[y];}

void init(){
    for(int i = 1;i<=m;++i){t[i] = i;}
}

int solve(){
    //二次枚举
    int ans = INT_MAX;
    for(int l = 1;l<=m;++l){
        int block = n;
        init();//恢复并查集
        for(int r = l;r<=m;++r){
            int i = q[r];
            int x = findRoot(u[i]),y = findRoot(v[i]);
            if(x !=  y){
                t[x] = y;
                n--;
            }
            if(n == 1){
                ans = max(ans,w[i]-w[q[l]]);
                break;
            }
        }
    }
    return ans != INT_MAX?ans:-1;
}

int main(){
    while(cin>>n>>m&&n&&m){
        t = q = u = v = w = vector<int>(m+1);
        for(int i = 1;i<=m;++i){
            cin>>u[i]>>v[i]>>w[i];
            t[i] = q[i] = i;
        }
        sort(q+1,q+n+1,cmp);//间接排序
        cout<<solve()<<endl;
    }
    system("pause");
}