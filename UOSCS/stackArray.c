#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct arrayStack
{
  int v[SIZE];
  int top;
}arrayStack;

void init(arrayStack *L)
{
  L->top = -1;
}

int isEmpty(arrayStack *L)
{
  if(L->top == -1)
    return 1;
  else return 0;
}

void push(arrayStack *L, int item)
{
  L->top++;
  L->v[L->top] = item;
}

void pop(arrayStack *L)
{
  if(isEmpty(L))
  {
    printf("stack is empty");
    exit(-1);
  }
  else{
    printf("pop : %d\n", L->v[L->top]);
    L->top--;
  }
}

void peek(arrayStack *L)
{
  if(isEmpty(L))
  {
    printf("stack is empty");
    exit(-1);
  }
  else {
    printf("peek : %d\n", L->v[L->top]);
  }
}

void print(arrayStack *L)
{
  if(isEmpty(L))
  {
    printf("stack is empty");
    exit(-1);
  }
  int i;
  for(i=0;i<=L->top;i++)
    printf("[%d] ", L->v[i]);
  printf("\n");
}


int main()
{
  arrayStack stack;
  init(&stack);

  push(&stack, 1); print(&stack);
  push(&stack, 2); print(&stack);
  push(&stack, 3); print(&stack);
  push(&stack, 4); print(&stack);

  pop(&stack); print(&stack);
  peek(&stack);

  return 0;
}
