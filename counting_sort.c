#include<stdio.h>
#include<stdlib.h>

void showArray(int *ptr,int size) 
{

printf("\n");

 int i=0;
 while (i<size)
 {
     printf("\n element %d :%d ",i,*(ptr+i));
     i++;
 }
 
}

void showArrayCount(int (*arr)[2],int size) 
{


 int i=0;
 while (i<size&&arr[i][1]!=0)
 {
    printf("\n element %d :%d  %d",i,arr[i][0],arr[i][1]);
    i++;
 }
 
}

int checkDuplicate(int element,int (*arr)[2],int size) 
{
    int i=0,flag=1;
    while(i<size)
    {
       if(arr[i][0]==element)
       { 
           flag=0;break;
       }
       i++;
    }
     return(flag);
}

void countingSort(int a[],int size)
{   

    int count[size][2],i=0,j=0,result[size];

    while(i<size) 
    {   
      
        if(checkDuplicate(a[i],count,i))
        {
        count[j][0] = a[i]; 
        count[j][1] = 0;    
        j++;
        }
        i++;
    }
    for(j=0;j<size;j++)
    {

       
        for(i=0;i<size;i++)
        {   
           
            if(count[i][0]==a[j])
            { 
                ++count[i][1];
              
            } 
        }

        
    }
   
    for(j=1;count[j][1]!=0;j++) 
    {
        count[j][1] = count[j][1] + count[j-1][1];
    }
   printf("\n");
   

   for(i=(size-1);i>=0;i--) 
   {    
        int find = a[i];
         j=0;
         while(count[j][1]!=0) 
         {
           if(find==count[j][0])
           {   
               
               break;
           }  
           j++;
         }
        result[--count[j][1]] =  a[i]; 
        if(i==0) 
        {    
            j=0;
            while(j!=size)
            {
                a[j]= result[ j ];
                j++;
            }
        }
   }
}

int main()
{   
    //10,99,8,6,6,6,6,80,451,23,77,70,100,99,77,8,10,99
    int array[]={1,2,3,4,1,5,6,7,1,8,9};
    //printf("\n  max : %d",getMax(array,(sizeof(array)/4)));
    countingSort(array,(sizeof(array)/4));
    showArray(array,(sizeof(array)/4));
    return 0;
}