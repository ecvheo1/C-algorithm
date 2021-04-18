#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 100
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t) )


struct Heap
{
  int H[MAX_ELEMENT];
  int n;
} _Heap;

void downHeap(int i)
{
  if(i*2 > _Heap.n) return;
  if(_Heap.H[i] < _Heap.H[i*2] || _Heap.H[i] < _Heap.H[i*2+1])
  {
    if(_Heap.H[i*2] > _Heap.H[i*2+1]) {
      int temp;
      SWAP(_Heap.H[i], _Heap.H[i*2], temp);
      downHeap(i*2);
    }
    else {
      int temp;
      SWAP(_Heap.H[i], _Heap.H[i*2+1], temp);
      downHeap(i*2+1);
    }
  } 
  else return;
}

void buildHeap()
{
  int i;
  for(i=_Heap.n / 2; i>=1; i--)
    downHeap(1);
}

void rBuildHeap(int i)
{
  if(i > _Heap.n)
    return;
  if(i * 2 <= _Heap.n)
    rBuildHeap(i*2);
  if(i * 2 + 1 <= _Heap.n)
    rBuildHeap(i*2 +1);
  downHeap(i);
}

int removeMax()
{
  int data = _Heap.H[1];
  _Heap.H[1] = _Heap.H[_Heap.n--];
  downHeap(1);
  return data;
}

void inPlaceHeapSort()
{
  int size = _Heap.n;
  int i,data;
  for(i=0; i<size; i++)
  {
    data = removeMax();
    _Heap.H[_Heap.n+1] = data;
  }
}

void printHeap()
{
  int i;
  for(i=1; i<=_Heap.n; i++)
    printf("[%d] ", _Heap.H[i]);
  printf("\n\n");
}

void printArray()
{
  int i;
  for(i=1;_Heap.H[i] > 0; i++)
    printf("[%d] ", _Heap.H[i]);
  printf("\n\n");
}

int main()
{
  _Heap.n = 0;
  int i;
  srand(time(NULL));
  scanf("%d", &_Heap.n);
  for(i=1; i<=_Heap.n; i++)
    _Heap.H[i] = rand()%100;

  buildHeap();
  // rBuildHeap(1);
  printHeap();
  inPlaceHeapSort();
  printArray();

  return 0;
}
