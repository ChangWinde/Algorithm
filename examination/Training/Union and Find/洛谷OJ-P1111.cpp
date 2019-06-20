//  P1111 修复公路

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Path
{
    int x,y,t;
    Path(){}
    Path(int _x,int _y,int _t){
        x=_x;y=_y;t=_t;
    }
    bool operator<(const Path& other)const{
        return t<other.t;
    }
};
int findRoot(vector<int>& tr,int x){
    if(tr[x]==-1)
        return x;
    else{
        int temp = findRoot(tr,x);
        tr[x] = temp;
        return temp;
    }
}
int main(){
    int n,m;
    vector<int> tr(n+1,-1);
    while(cin>>m&&m){
        if(m<n-1){
            cout<<-1<<endl;
            continue;
        }
        Path* p = new Path[m+1];
        for(int i = 1;i<=m;++i){
            cin>>p[i].x>>p[i].y>>p[i].t;
        }
        sort(p+1,p+n+1);
        //合并
        int count = n;
        int index = 1;
        while(count==1||index>m){
            int a = findRoot(p[m].x);
            int b = findRoot(p[m].y);
            if(a!=b){
                if(a==-1)
                    count--;
                tr[a] = b;
            }
            index++;
        }
        if(count == 1){
            cout<<p[index-1]<<endl;
        }
    }
    system("pause");
}