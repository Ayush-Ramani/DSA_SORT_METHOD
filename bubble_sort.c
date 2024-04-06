#include<stdio.h>

void showArray(int *ptr,int size)
{

    printf("\n");

    int i=0;
    while (size>0)
    {
        printf("\n element :%d ",*(ptr+i));
        size--;
        i++;
    }
    
}

void bubbleSort(int *ptr,int size) 
{
    int round,swap,i;

    for(round=1;round<size;round++)
    {
        for(i=0;i<=(size-1)-round;i++)
        {
            if(*(ptr+i) > *(ptr+i+1))
            {
                 swap = *(ptr+i) ;
                *(ptr+i) = *(ptr+i+1) ;
                *(ptr+i+1) = swap ;
            }
        }
    }
    printf("\n%d round scanned in normal bubble sort !",round);
}

void bubbleSort2(int *ptr,int size) 
{
    int round,swap,i,flag;

    for(round=1;round<size;round++)
    {
        flag=0;
        
        for(i=0;i<=(size-1)-round;i++)
        {
            if(*(ptr+i) > *(ptr+i+1))
            {
                 swap = *(ptr+i) ;
                *(ptr+i) = *(ptr+i+1) ;
                *(ptr+i+1) = swap ;
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("\n%d round scanned in modified bubble sort!",round);
            return;
        }
    }
}

int main()
{

    int array[10]={10,99,88,6,126,451,23,77,70,100};
    bubbleSort2(array,10);
    
    int array2[10]={10,99,88,6,126,451,23,77,70,100};
    bubbleSort(array2,10);

    showArray(array,10);
    showArray(array2,10);


}