#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENT 100


typedef struct
{
  int heap[MAX_ELEMENT];
  int heap_size;
}HeapType;

void init(HeapType *H)
{
  H->heap_size = 0;
}

void upHeap(HeapType *H)
{
  int i = H->heap_size;
  int temp = H->heap[i];

  while( i != 1 && temp < H->heap[i/2])
  {
    H->heap[i] = H->heap[i/2];
    i = i/2;
  }
  H->heap[i] = temp;
}

void downHeap(HeapType *H)
{
  int temp = H->heap[1];
  int parent = 1, child = 2;

  while(child <= H->heap_size)
  {
    if( (child < H->heap_size) && (H->heap[child] > H->heap[child+1]) )
      child++;
    if(temp <= H->heap[child])
      break;
    H->heap[parent] = H->heap[child];    
    parent = child;
    child *= 2;
  }
  H->heap[parent] = temp;
}

void insert(HeapType *H, int data)
{
  H->heap_size++;
  H->heap[H->heap_size] = data;

  upHeap(H);
}

int removeMin(HeapType *H)
{
  int temp = H->heap[1];
  H->heap[1] = H->heap[H->heap_size];
  H->heap_size--;

  downHeap(H);

  return temp;
}

void printHeap(HeapType *H)
{
  int i;
  for(i=1; i<=H->heap_size; i++)
  {
    printf("[%d] ", H->heap[i]);
  }
  printf("\n");
}

void inPlaceHeapSort(HeapType *H)
{
  int size = H->heap_size;
  int data;
  int i;
  
  for(i=0; i<size; i++)
  {
    data = removeMin(H);
    H->heap[H->heap_size+1] = data;
  }
}

int main()
{
  HeapType heap;
  int i;

  init(&heap);
  srand(time(NULL));

  for(i=0; i<15; i++)
  {
    insert(&heap, rand()%99+1);
  }
  printHeap(&heap);

  inPlaceHeapSort(&heap);

  for(i=1; heap.heap[i] > 0; i++)
  {
    printf("[%d] ", heap.heap[i]);
  }

  return 0;
}
