#include<iostream>
using namespace std;

int n,l,r,ans,mid;

bool isWork(int k)//这个函数通常返回bool 
{
	// This isWork is a example 
	if(k<=100)return true;
	else return false;
}

int main()
{
	cin>>n;
	l=1;r=n;//二分答案，假设答案在1~n之间，且函数isWork单调 
	while(l<r)//注意是<,不是<= 
	{
		mid=(l+r)>>1;//取l,r的中点 
		if(isWork(mid))//将mid参数传进去 
		{
			ans=mid;
			l=mid+1;//注意是mid+1 
		}else r=mid-1;//注意是mid-1 
	}
	//所有含注意的是易错点，并且一个都不能错，否则可能会导致死循环 
	cout<<ans<<endl;
	return 0;
}

