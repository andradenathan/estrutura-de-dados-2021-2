#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void printLinkedList(Node* node) {
  while(node != NULL) {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("\n");
}

int indexLinkedList(Node** head, int elem) {
  Node* ptr = (*head);
  int i = 0;
  while(ptr) {
    if(ptr->data == elem)
      return i;

    ptr = ptr->next;
    i++;
  }
  return -1;
}

void pop(Node** head, int elem) {
  if((*head) == NULL) {
    printf("Element not in list\n");
  }
  else if(elem == (*head)->data) {
    (*head) = (*head)->next;
  } 
  else {
    Node* ancestor = (*head);
    Node* ptr = (*head)->next;
    while(ptr) {
      if(ptr->data == elem) {
        ancestor->next = ptr->next;
        ptr->next = NULL;
      }
      ancestor = ptr;
      ptr = ptr->next;
    }
  }
}

void push(Node** head, int elem) {
  Node* node = (Node*) malloc(sizeof(Node));
  if((*head) == NULL) {
    node->data = elem;
    node->next = (*head);
    (*head) = node; 
  } else {
    Node* ptr = (*head);
    while(ptr->next) {
      ptr = ptr->next;
    }
    node->data = elem;
    ptr->next = node;
  }
}


int main(void) {
  Node* node = NULL;
  push(&node, 10);
  push(&node, 15);
  push(&node, 20);
  push(&node, 50);
  pop(&node, 10);
  int id = indexLinkedList(&node, 40);
  if(id != -1) printf("Element in index: %d\n", id);
  else printf("Element not in list\n");
  printLinkedList(node);
  free(node);
  return 0;
}