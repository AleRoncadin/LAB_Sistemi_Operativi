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
    if (head == NULL)
        return 0;

    // Passo ricorsivo: somma 1 e chiamata ricorsiva sulla coda della lista
    return 1 + length(head->next);
}

// ricerca di un elemento in una lista
struct node *find(struct node *head, int data)
{
    // Caso base: la lista è vuota o l'elemento è stato trovato
    if (head == NULL || head->data == data)
        return head;

    // Passo ricorsivo: chiamata ricorsiva sulla coda della lista
    return find(head->next, data);
}

// concatenate 2 liste
struct node *last(struct node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
        return head;

    return last(head->next);
}

struct node *append(struct node *head1, struct node *head2)
{
    // Caso base: se la prima lista è vuota, restituisce la seconda lista
    if (head1 == NULL)
        return head2;

    // Verifica se la seconda lista è vuota prima di tentare di concatenarla
    if (head2 == NULL)
        return head1;

    // Caso base: se l'elemento corrente è l'ultimo della prima lista
    if (head1->next == NULL)
    {
        head1->next = head2;
        return head1;
    }

    // Passo ricorsivo: chiamata ricorsiva sulla coda della prima lista
    return append(head1->next, head2);
}

// libera la memoria
void destroy(struct node *head)
{
    if (head == NULL)
        return;

    // Passo ricorsivo: chiamata ricorsiva sulla coda della lista
    destroy(head->next);

    // Dopo aver deallocato la coda, dealloca l'elemento corrente
    free(head);
}
