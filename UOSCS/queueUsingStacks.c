#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define TRUE 1
#define FALSE 0

typedef struct stack
{
  int top;
  int v[SIZE];
}stack;

typedef struct queue
{
  stack s1;
  stack s2;
}queue;

void init(stack *S)
{
  S->top = -1;
}

void createQueue(queue *L)
{
  init(&L->s1);
  init(&L->s2);
}

int isEmpty(stack *S)
{
  if(S->top == -1) return TRUE;
  else return FALSE;
}

int isFull(stack *S)
{
  if(S->top == SIZE-1) return TRUE;
  else return FALSE;
}

void push(stack *S, int data)
{
  if(isFull(S))
  {
    printf("FULL!");
    exit(-1);
  }
  S->v[++S->top] = data;
}

void pop(stack *S, int *data)
{
  if(isEmpty(S))
  {
    printf("EMPTY!");
    exit(-1);
  }
  *data = S->v[S->top--];
}

int top(stack *S)
{
  return S->v[S->top];
}

void print(stack *S)
{
  int i;
  for(i=S->top; i>=0; i--)
    printf("[%d] ", S->v[i]);
  printf("\n");
}

void printQueue(queue *L)
{
  print(&L->s1);
}

void enqueue(queue *L, int input)
{
  int data;
  while(!isEmpty(&L->s1))
  {
    pop(&L->s1, &data);
    push(&L->s2, data);
  }
  push(&L->s1, input);
  while(!isEmpty(&L->s2))
  {
    pop(&L->s2, &data);
    push(&L->s1, data);
  }
}

void dequeue(queue *L, int *output)
{
  int data;
  if(isEmpty(&L->s1))
  {
    printf("EMPTY!");
    exit(-1);
  }
  *output = top(&L->s1);
  pop(&L->s1, &data);
}

int main()
{
  int value, num;
  queue q;
  createQueue(&q);
  while(1)
  {
    printf("1. Insert\n");
    printf("2. Remove\n");
    printf("3. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &num);
    switch(num)
    {
      case 1:
        printf("Enter value to insert : ");
        scanf("%d", &value);
        enqueue(&q, value);
        printQueue(&q);
        break;
      case 2:
        dequeue(&q, &value);
        printf("Removed value is : %d\n",value);
        printQueue(&q);
        break;
      case 3:
        exit(1);
        break;
    }
  }
}
