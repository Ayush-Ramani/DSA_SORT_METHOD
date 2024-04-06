
#include<stdio.h>
#define size 6
int a[size],i;
void input(int a[size])
{

	for(i=0;i<size;i++)
	{
		printf("\nEnter The Value = ");
		scanf("%d",&a[i]);
	}
}
void display(int a[size])
{
	for(i=0;i<size;i++)
	{
		printf(" %d ",a[i]);
	}
}
void selection(int a[size])
{
	int j,temp,t;
	for(i=0;i<size;i++)
	{
		temp=i;
		for(j=i+1;j<size;j++)
		{
			if(a[j] < a[temp])
			{
				temp=j;
			}
		}
		if(temp!=i)
		{
			t=a[i];
			a[i]=a[temp];
			a[temp]=t;
		}
	}

}
int main()
{
	int z,ch=1;
	while(ch!=0)
	{
		printf("\n1. input :");
		printf("\n2. display :");
		printf("\n3. Selection sort :");
		printf("\n Enter Your Choice = :");
		scanf("%d",&z);
		if(z==0)
		{
			break;
		}
		else if(z==1)
		{
			input(a);
		}
		else if(z==2)
		{
			display(a);
		}
		else if(z==3)
		{
			insertion(a);
		}
		else
		{
			printf("\n Please Enter Valid Choice . ");
		}
    }
	return 0;
}
