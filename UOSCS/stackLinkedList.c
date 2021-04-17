#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct node
{
  int data;
  struct node * link;
}Node;

typedef struct listStack
{
  Node *head;
}listStack;

void init(listStack *L)
{
  L->head = NULL;
}

int isEmpty(listStack *L)
{
  if(L->head == NULL) return TRUE;
  else return FALSE;
}

void push(listStack *L, int item)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  
  newNode->data = item;
  newNode->link = L->head;

  L->head = newNode;
}

int pop(listStack *L)
{
  int popData;
  Node *rnode;
  if(isEmpty(L)){
    printf("stack is empty!");
    exit(-1);
  } 
  popData = L->head->data;
  rnode = L->head;
  L->head = rnode->link;
  free(rnode);

  return popData;
}

int top(listStack *L)
{
  if(isEmpty(L)){
    printf("stack is empty!");
    exit(-1);
  }

  return L->head->data;
}

int main()
{
  listStack stack;
  init(&stack);

  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);

  while(!isEmpty(&stack))
    printf("%d \n", pop(&stack));

  return 0;
}
