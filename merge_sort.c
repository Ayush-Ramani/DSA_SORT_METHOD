#include<stdio.h>
#define size 5
#define size2 4
int main()
{
	int n = size+size2;
	int l,m,a[size],b[size2],e[n],c;
	for(c=0;c<size;c++)
	{
		printf("Enter the value of a[%d]:",c);
		scanf("%d",&a[c]);
	}
	for(c=0;c<size2;c++)
	{
	printf("Enter the value of b[%d]:",c);
	scanf("%d",&b[c]);
	}
	l=0;
	m=0;
	for(c=0;c<n;c++)
	{
		if(l<size && m<size2)
		{
			 if(a[l]<b[m])
			 {
				 e[c]=a[l];
				l++;
			 }
			else
			{
				e[c]=b[m];
				m++;
			}
		}
	   else
		{
			if(l>=size)
			{
				e[c]=b[m];
				m++;
			}
			else
			{
				e[c]=a[l];
				l++;
			}
	   }
	}
	printf("\nSORTING LIST\n");

	for(c=0;c<n;c++)
	{
		printf("%d \t",e[c]);
	}
	return 0;
}



