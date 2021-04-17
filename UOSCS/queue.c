
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct node
{
  int data;
  struct node *link;
}Node;

typedef struct
{
  Node * front;
  Node * rear;
}linkedQueue;

void init(linkedQueue *L)
{
  L->front = L->rear = NULL;
}

int is_Empty(linkedQueue *L)
{
  return L->front == NULL;
}

void enqueue(linkedQueue *L, int data)
{
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->link = NULL;
  
  if(is_Empty(L))
    L->front = L->rear = newNode;
  else
  {
    L->rear->link = newNode;
    L->rear = newNode;
  }
}

int dequeue(linkedQueue *L)
{
  Node *p = L->front;
  int data;
  if(is_Empty(L))
  {
    printf("Queue is Empty!");
    exit(-1);
  }
  else
  {
    data = p->data;
    L->front = p->link;
    if(L->front == NULL)
      L->rear = NULL;
    
    free(p);
    return data;
  }
}

void print(linkedQueue *L)
{
  Node *p;
  for(p=L->front; p !=NULL; p=p->link)
    printf("|%d| -> ", p->data);
  printf("|NULL|\n");
}

int main()
{
  linkedQueue queue;
  init(&queue);

  enqueue(&queue, 10); print(&queue);
  enqueue(&queue, 20); print(&queue);
  enqueue(&queue, 30); print(&queue);
  getchar();
  dequeue(&queue); print(&queue);
  dequeue(&queue); print(&queue);
  dequeue(&queue); print(&queue);

  return 0;
}
