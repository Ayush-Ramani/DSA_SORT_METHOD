#include<stdio.h>
#include<stdlib.h>
struct Heap
{
    int *array;
    int indxOfArray;
    int sizeOfArray;   
};


void printHeap(struct Heap *heap,int indx)
{  
  if(indx<heap->sizeOfArray)  
  printf("\nelement : %d",*(heap->array+indx));
}

void showHeap(struct Heap *heap)
{

printf("\n");

 int i=0;

 while(i< (heap->sizeOfArray))
 {  
    printHeap(heap,i);
    printHeap(heap,i+1);
    printHeap(heap,i+2);
    i = i+3;
 }
 
}


void heapify(struct Heap *heap,int indx_check)
{
  if(indx_check != 0)
  {     
        int pos;

            pos = (indx_check-1) / 2;
            while(*(heap->array+pos) < *(heap->array+indx_check))
            {
                int temp = *(heap->array+pos);
                *(heap->array+pos) = *(heap->array+indx_check);
                *(heap->array+indx_check) = temp;

                indx_check = pos ;
                pos = (indx_check-1) / 2;
                
            }        
  }
}

void heapify2(struct Heap *heap,int max)
{
  int indx_check = 0;
  if(indx_check >= 0 && indx_check < heap->indxOfArray)
  {     
         
         int temp;
         
         while(*(heap->array+indx_check) < *(heap->array+(indx_check * 2 + 1)) || *(heap->array+indx_check) < *(heap->array+((indx_check * 2 + 1)+1)))
         {
         if((indx_check * 2 + 1) >= max ||((indx_check * 2 + 1)+1) >= max)
         break;
         
         if(*(heap->array + (indx_check * 2 + 1)) > *(heap->array + (indx_check * 2 + 1)+1))
         {
             temp = *(heap->array + indx_check); 
             *(heap->array + indx_check) = *(heap->array + (indx_check * 2 + 1));
             *(heap->array + (indx_check * 2 + 1)) = temp;
             indx_check = (indx_check * 2 + 1);
         }
         else
         {
             temp = *(heap->array + indx_check); 
             *(heap->array + indx_check) = *(heap->array + (indx_check * 2 + 1)+1);
             *(heap->array + (indx_check * 2 + 1)+1) = temp;
             indx_check  = ((indx_check * 2 + 1)+1);
         }
       
        }
      
  }
}

void insertHeap(struct Heap *heap,int *ptr,int size)
{
    int i=0;
    while(i<size)
    {
       
        *(heap->array+i) = *(ptr+i);
        ++(heap->indxOfArray);
        heapify(heap,i);
        i++;
    }

}

void heapSort(struct Heap *heap)
{   
    int i=(heap->indxOfArray-1),temp;
    while(i>=0)
    {
  
    temp = *(heap->array+0);
    *(heap->array+0) = *(heap->array+i);
    *(heap->array+i) = temp;
  
    if(i==2) break; 
    heapify2(heap,--(heap->indxOfArray));
   
    i--;
    }

}
struct Heap* createHeap(int SIZE)
{   
    
    struct Heap *heap = (struct Heap*)malloc(sizeof(struct Heap));

    heap->array = (int*)malloc(sizeof(int)*SIZE);
    
    heap->indxOfArray = 0;
    heap->sizeOfArray = SIZE;
    
    return(heap);

}
int main()
{   
    int array[]={7,44,114,22,32,0,45,114,88,99,100,2,5,7,28,36,261};
    struct Heap *heap = createHeap((sizeof(array)/4));
    
    insertHeap(heap,array,(sizeof(array)/4));
    heapSort(heap);
    showHeap(heap);
    
}