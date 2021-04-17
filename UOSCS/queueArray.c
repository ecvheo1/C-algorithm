// 원형 큐
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define TRUE 1
#define FALSE 0

typedef struct arrayQueue
{
  int front;
  int rear;
  int v[SIZE];
}arrayQueue;

void init(arrayQueue *L)
{
  L->front = 0;
  L->rear = 0;
}

int isEmpty(arrayQueue *L)
{
  if(L->front == L->rear) return TRUE;
  else return FALSE;
}

int nextIdx(int pos)
{
  if(pos == SIZE - 1) return 0;
  else return pos+1;
}

void enqueue(arrayQueue *L, int data)
{
  if(nextIdx(L->rear) == L->front)
  {
    printf("full");
    exit(-1);
  }
  L->rear = nextIdx(L->rear);
  L->v[L->rear] = data;
}

int dequeue(arrayQueue *L)
{
  if(isEmpty(L)){
        printf("empty");
        exit(-1);
    }

  L->front = nextIdx(L->front);
  return L->v[L->front];
}

int peek(arrayQueue *L)
{
  if(isEmpty(L)){
        printf("empty");
        exit(-1);
    }

  return L->v[nextIdx(L->front)];
}

int main()
{
  arrayQueue queue;
  init(&queue);

  enqueue(&queue, 1);
  enqueue(&queue, 2);
  enqueue(&queue, 3);
  enqueue(&queue, 4);

  while(!isEmpty(&queue))
    printf("%d \n", dequeue(&queue));

  return 0;
}
