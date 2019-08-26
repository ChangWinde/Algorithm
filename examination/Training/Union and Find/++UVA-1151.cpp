//  UVA1151 买还是建 Buy or Build

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct pakage
{
    int m,c;
    vector<int> l;
};
struct city
{
    int x,y;
    int dis(const city & other){
        return pow(other.x-x,2)+pow(other.y-y,2);
    }
};

int n,q;
vector<int> t;
vector<pakage> p;
vector<city> cs;

int findRoot(int x){return x==t[x]?x:findRoot(t[x]);}

int main(){
    int test;
    cin>>test;
    while(test--){
        cin>>n>>q;
        t = vector<int>(n+1);
        p = vector<pakage>(q+1);
        for(int i = 1;i<=q;++i){
            cin>>p[i].m>>p[i].c;
            p[i].l = vector<int>(p[i].m+1);
            for(int j = 1;j<=p[i].m;++j)
                cin>>(p[i].l)[i];
        }
        cs = vector<city>(n+1);
        for(int i = 1;i<=n;++i){
            cin>>cs[i].x>>cs[i].y;
        }
        //考察每个包的效果
        for(int i = 1;i<=q;++i){

        }
    }
}