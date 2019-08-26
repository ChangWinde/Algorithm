#include<iostream>
using namespace std;

const long long p=1e9+7;

long long quickpow(long long a,long long n,long long p)
{
	long long ans=1,w=a;
	while(n>0)
	{
		if(n & 1)ans=(ans*w)%p;
		w=(w*w)%p;
		n=n>>1;
	}
	return ans;
}

int main()
{
	cout<<quickpow(3,4,p)<<endl;
	long long a,b;
	cin>>a>>b;
	cout<<quickpow(a,b,p)<<endl;
	//a^b%p
	//注意是long long 
	return 0;
}
//求出1~n的逆元
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 3e6+5;
ll d[maxn] = {0,1};
int main(){
    int n,p;
    cin>>n>>p;
    cout<<d[1]<<endl;
    for(int i = 2;i<=n;i++){
        d[i] = (p-p/i)*d[p%i]%p;
        cout<<d[i]<<endl;
    }
}
