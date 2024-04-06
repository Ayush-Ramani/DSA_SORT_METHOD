#include<stdio.h>
#include<stdlib.h>
int getMax(int *ptr,int size) { 
    int max=*(ptr),i=0; 

    while (i!=size)
    {
        if(max < *(ptr+i))
        {
          max = *(ptr+i);
        }
        i++;
    }
    return(max);
}

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

void radixSort(int *ptr,int size)
{
    int maxElem  = getMax(ptr,size);
    int round,i=0,rem;


    for(round=1;maxElem/round>0;round*=10) 
    {   
        int count[10]={0},result[size]; 
        while(i<size)
        {result[i]=0;
        i++;}

        printf("\n\n pass : %d \n",round);

        for(i=0;i<size;i++) {
            rem = ((*(ptr+i)/round) % 10);
            
            ++count[rem];
            
        }
       
        for(i=1;i<10;i++) 
        {   

          
            count[i] = count[i] + count[i-1];
            
        }
       
        for(i=(size-1);i>=0;i--) 
        {                        

          int temp =  --count[ ((*(ptr+i)/round) % 10) ];

         
          result[temp] = *(ptr+i); 

          
          if(i==0) 
          {               
              int j=0;
              while(j!=size)
              {
                  *(ptr+j) = result[ j ];
                  j++;
              }

          }

        
        }
    }
   
}

int main()
{
    int array[]={10,99,88,6,126,451,23,77,70,100,1500,1,8,7,26,758,8,456,1089,1356,5000,2,9};
    radixSort(array,(sizeof(array)/4));
    showArray(array,(sizeof(array)/4));
}