#include<stdio.h>
#define size 5
int i,a[size];
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
void insertion(int a[size])
{
	int i,j,temp;
	for(i=0;i<size;i++)
	{
		temp = a[i];
		j=i-1;
		while(j>=0 && a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;

	}
}


int main()
{
	int z,ch=1;
	while(ch!=0)
	{
		printf("\n1. input :");
		printf("\n2. display :");
		printf("\n3. insertion sort :");
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

