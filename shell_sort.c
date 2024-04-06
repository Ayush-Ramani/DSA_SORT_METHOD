
#include<stdio.h>
#define n 6
int arr[n],k,i,j,temp,m,l;

int main()
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nenter the value for arr[%d]=",i);
		scanf("%d",&arr[i]);
	}
	printf("\nyour values=");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	k=n/2;
	do
	{
		for(i=0,j=i+k;j<n;i++,j++)
		{
			if(arr[i] > arr[j])
			{
				for(m=i,l=j;arr[m] > arr[l];m=m-k,l=l-k)
				{
					temp=arr[m];
					arr[m]=arr[l];
					arr[l]=temp;
				}
			}
		}
		k=k/2;
	}while(k!=0);
	printf("\nshell sorted array=");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

        {
            for(j=i-gap;j>=0;j-=gap)
            {
                if(*(ptr+j) >= *(ptr+j+gap))
                {
                    temp = *(ptr+j);
                    *(ptr+j) = *(ptr+j+gap);
                    *(ptr+j+gap) = temp;
                }
            }
        }
    }
}

int main()
{
    int array[10]={10,99,88,6,126,451,23,77,70,100};
    shellSort(array,10);
    showArray(array,10);
}