#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(int data);
int length(struct node *head);
struct node *find(struct node *head, int data);
struct node *last(struct node *head);
struct node *append(struct node *head1, struct node *head2);
void destroy(struct node *head);

int main()
{
    // Creazione di due liste
    struct node *list1 = create(1);
    list1->next = create(2);
    list1->next->next = create(3);

    struct node *list2 = create(4);
    list2->next = create(5);
    list2->next->next = create(6);

    // Stampa lunghezza delle liste
    printf("Length of list1: %d\n", length(list1));
    printf("Length of list2: %d\n", length(list2));

    // Ricerca di un elemento nella lista 1
    int searchValue;
    printf("Enter a value to search in list1: ");
    scanf("%d", &searchValue);
    struct node *foundNode = find(list1, searchValue);
    if (foundNode)
        printf("Element found in list1.\n");
    else
        printf("Element not found in list1.\n");

    // Concatenazione delle liste
    struct node *concatenatedList = append(list1, list2);

    // Stampa lunghezza della lista concatenata
    printf("Length of concatenated list: %d\n", length(concatenatedList));

    // Distruzione delle liste
    destroy(list1);
    destroy(list2);

    return 0;
}

// alloca dinamicamente i nodi della lista
struct node *create(int data)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

int length(struct node *head)
{
    int len = 0;
    for (struct node *n = head; n; n = n->next)
    {
        ++len;
    }
    return len;
}

// ricerca di un elemento in una lista
struct node *find(struct node *head, int data)
{
    for (struct node *n = head; n; n = n->next)
    {
        if (n->data == data)
            return n;
    }
    return NULL;
}

// concatenate 2 liste
struct node *last(struct node *head)
{
    for (struct node *n = head; n; n = n->next)
    {
        if (n->next == NULL)
            return n;
    }
    return NULL;
}
struct node *append(struct node *head1, struct node *head2)
{
    struct node *last1 = last(head1);
    last1->next = head2;
    return head1;
}

// libera la memoria
void destroy(struct node *head)
{
    struct node *next = head;
    while (next)
    {
        struct node *n = next;
        next = n->next;
        free(n);
    }
}