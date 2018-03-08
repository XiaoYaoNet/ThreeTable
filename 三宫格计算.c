#include <stdio.h>
#define M 3
int zhen[5][5];

int count=0;
void init(int a[5][5])     //初始化数组
{
	int i,j,num=1;
	for(i=0;i<M;i++)
		for(j=0;j<M;j++)
		{
			a[i][j]=0;
		}
}

int decide(int a[5][5],int m,int n,int x,int y)   //判断当前手势顺序是否是一个合法手势
{
	int max,min;
	int flag1=m-x;
	int flag2=(n-y)*(-1);
	if(m==-1&&n==-1)
		return 1;
	if((m==x)&&(n!=y))
	{
		if(n>y)
		{
			max=n;
			min=y;
		}else
		{
			max=y;
			min=n;
		}
		for(min+=1;min<max;min++)
		{
			if(a[m][min]==0)
				return 0;
		}
		return 1;
	}
	if((m!=x)&&(n==y))
	{

		if(m>x)
		{
			max=m;
			min=x;
		}else
		{
			max=x;
			min=m;
		}
		for(min+=1;min<max;min++)
		{
			if(a[min][n]==0)
				return 0;
		}
		return 1;
	}
	if(m==n&&x==y)
	{
		if(m>x)
		{
			max=m;
			min=x;
		}
		else
		{
			max=x;
			min=m;
		}
		for(min+=1;min<max;min++)
		{
			if(a[min][min]==0)
				return 0;
		}
		return 1;
	}
	if(flag1==flag2)
	{
		if(m>x)
		{
			for(m-=1,n+=1;(m>x)&&(n<y);m--,n++)
				if(a[m][n]==0)
					return 0;
		}else
		{
			for(m+=1,n-=1;(m<x)&(n>y);m++,n--)
				if(a[m][n]==0)
					return 0;
		}
		return 1;
	}
	return 1;
}
void deal(int a[5][5],int level,int m,int n)
{
	int i,j;
	int flag;
	if((m<M)&&(n<M))
	{
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			if(a[i][j]!=1)
			{
				flag=decide(a,m,n,i,j);
				if(flag!=0)
				{
					a[i][j]=1;
					level+=1;
					if(level>=4)
					{
						count++;
					}
					deal(a,level,i,j);
					a[i][j]=0;
				    level--;
				}
			}
		}
	}
	}
}

int main()
{
	int i,j;
	init(zhen);
	deal(zhen,0,-1,-1);
	printf("%d\n",count);
	return 0;
}