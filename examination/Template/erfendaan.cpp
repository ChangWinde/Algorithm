#include<iostream>
using namespace std;

int n,l,r,ans,mid;

bool isWork(int k)//�������ͨ������bool 
{
	// This isWork is a example 
	if(k<=100)return true;
	else return false;
}

int main()
{
	cin>>n;
	l=1;r=n;//���ִ𰸣��������1~n֮�䣬�Һ���isWork���� 
	while(l<r)//ע����<,����<= 
	{
		mid=(l+r)>>1;//ȡl,r���е� 
		if(isWork(mid))//��mid��������ȥ 
		{
			ans=mid;
			l=mid+1;//ע����mid+1 
		}else r=mid-1;//ע����mid-1 
	}
	//���к�ע������״�㣬����һ�������ܴ�������ܻᵼ����ѭ�� 
	cout<<ans<<endl;
	return 0;
}

