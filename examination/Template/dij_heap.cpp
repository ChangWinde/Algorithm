#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
#define maxint 0x3f3f3f3f
int d[maxn], head[maxn], tot;
bool v[maxn];
int n, m, s;
struct edge {
	int to, w, next;
}path[maxm];

struct node {
	int dis, pos;
	node(int d, int p) {
		dis = d;
		pos = p;
	}
	node(){}
	bool operator<(const node& x)const {
		return x.dis < dis;
	}
};
void addPath(int u, int v, int d) {
	tot++;
	path[tot].to = v;
	path[tot].w = d;
	path[tot].next = head[u];
	head[u] = tot;
}
priority_queue<node> q;
void dij(int s) {
	memset(v, false, sizeof(v));
	for (int i = 1; i <= n; i++)d[i] = maxint; d[s] = 0;
	node temp(0, s);
	q.push(temp);
	while (!q.empty()) {
		node cur = q.top(); q.pop();
		int x = cur.pos;
		if (v[x])continue;
		v[x] = 1;
		for (int i = head[x]; i; i = path[i].next) {
			int y = path[i].to;
			if (d[y] > d[x] + path[i].w) {
				d[y] = d[x] + path[i].w;
				if (!v[y]) {
					node tep(d[y], y);
					q.push(tep);
				}
			}
		}
	}
}
int main() {
	scanf_s("%d%d%d", &n, &m, &s);
	memset(head, 0, sizeof(head));
	for (int i = 1; i <= m; i++) {
		int u, v, d;
		scanf_s("%d%d%d", &u, &v, &d);
		addPath(u, v, d);
	}
	dij(s);
	for (int i = 1; i <= n; i++)
		printf("%d ", d[i]);
	printf("\n");
	system("pause");
}




/*
#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
const int maxm=2e5+5;
const int maxint=2147483647;

struct edge
{
    int to,w,next;
}path[maxm];

int head[maxn],d[maxn],tot;
bool v[maxn];
int n,m,s;

inline void addd(int u,int v,int d)
{
	tot++;
	path[tot].to=v;
	path[tot].w=d;
	path[tot].next=head[u];
	head[u]=tot;
}

struct node
{
    int dis,pos;
    bool operator<(const node &x)const
    {
        return x.dis<dis;
    }
};

priority_queue<node> q;

inline void dijkstra(int s)
{
    for(int i=1;i<=n;++i)d[i]=maxint;d[s]=0;
    memset(v,0,sizeof(v));
	q.push((node){0,s});
    while(!q.empty())
    {
        node cur=q.top();
        q.pop();
        int x=cur.pos,d=cur.dis;
        if(v[x])continue;
        v[x]=1;
        for( int i=head[x];i;i=path[i].next)
        {
            int y=path[i].to;
            if(d[y]>d[x]+path[i].w)
            {
                d[y]=d[x]+path[i].w;
                if(!v[y])
                    q.push((node){d[y],y});
            }
        }
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&s);
    memset(head,0,sizeof(head));
	for(int i=0;i<m;++i)
    {
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        addd(u,v,d);
    }
    dijkstra(s);
    for(int i=1;i<=n;i++)printf("%d ",d[i]);
    printf("\n");
    return 0;
}
*/
