//  KMP
//  next[j] = k ，那么代表(j - k ,……j - 1 )位的字符与长度为k的前缀匹配。
#include<cstdio>
#include<string.h>
using namespace std;

const int maxn=1000005;
int next[maxn],len1,len2;
char s1[maxn],s2[maxn];

void make()
{
    int i,j=-1;
    next[0]=-1;
    i=0;
    while(i<len2)
    {
        while(j!=-1 && s2[j]!=s2[i]) j=next[j];
        next[++i]=++j;
    }
}

void kmp()
{
    int i=0,j=0;
    while(i<len1)
    {
        //注意 s1[i]!=s2[j]
        while(j!=-1&&s1[i]!=s2[j]) j=next[j];
        if(j==len2-1)
        {
            printf("%d\n",i-j+1);
            j=next[j];
        }
        i++;j++;
    }
}

int main()
{
    scanf("%s",s1);scanf("%s",s2);
    len1=strlen(s1);len2=strlen(s2);
    make();
    kmp();
    for(int i=1;i<=len2;i++)printf("%d ",next[i]);
    printf("\n");
    return 0;
}