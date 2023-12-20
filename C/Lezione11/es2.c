#include <stdio.h>
#include <stdlib.h>

#include "es2.h"

Node *list_empty() {
  return NULL;
}

int list_is_empty(Node *head) {
  return head == NULL;
}

Node *list_create(int data) {
  Node *ptr = malloc(sizeof(Node));
  ptr->data = data;
  ptr->next = NULL;

  return ptr;
}

int list_length(Node *head) {
  if(head == NULL)
    return 0;

  return 1 + list_length(head->next);
}

Node *list_find(Node *head, int data) {
  if(head == NULL)
    return NULL;

  if(head->data == data)
    return head;

  return list_find(head->next, data);
}

Node *list_last(Node *head) {
  if(head == NULL)
    return NULL;

  if(head->next == NULL)
    return head;

  return list_last(head->next);
}

Node *list_append(Node *head1, Node *head2) {
  if(head1 == NULL)
    return head2;

  Node *last1 = list_last(head1);
  last1->next = head2;

  return head1;
}

void list_print(Node *head) {
  if(head == NULL) {
    putchar('\n');
    return;
  }

  printf("%d ", head->data);
  list_print(head->next);
}

void list_destroy(Node *head) {
  if(head == NULL)
    return;

  Node *next = head->next;

  free(head);
  list_destroy(next);
}

int main() {
  Node *list =
    list_append(list_create(3), list_append(list_create(42),
    list_append(list_create(2), list_create(4))));

  printf("Elementi della lista: ");
  list_print(list);

  printf("Lunghezza della lista: %d\n", list_length(list));

  printf("Lista a partire da 'find(list, 42)': ");
  list_print(list_find(list, 42));

  list_destroy(list);

  return 0;
}

