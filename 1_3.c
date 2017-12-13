#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct List // первый элемент будет служебным

{

    int a;

    struct List* next;

    struct List* prev;

}List;

List* list_new ()
{
    List* li = malloc (sizeof(List));
    li->next = NULL;
    li->prev = NULL;
    li->a = 0;
    return li;
}

int list_delete(List * li)
{
    li = li->next;
    while (li->next != NULL)
    {
        free(li->prev);
        li = li->next;
    }
    free(li->prev);
    free(li);
    return 1;
}

int push(List * li,int* b)
{
    while (li->next != NULL)
    {
        li = li->next;
    }
    List* l = malloc(sizeof(List));
    li->next = l;
    l->prev = li;
    l->next = NULL;
    l->a = *b;
    return 1;
}

int pop(List* li,int* x)
{
    if (li == NULL)
    {
        return 0;
    }
    while (li->next != NULL)
    {
        li = li->next;
    }
    *x = li->a;
    return 1;
}

int unshift(List* li, int b)
{
    List* l = malloc (sizeof(List));
    if (li->next == NULL)
    {
        li->next = l;
        l->prev = li;
        l->next = NULL;
        l->a = b;
        return 1;
    }

    li->next->prev = l;
    l->next = li->next;
    li->next = l;
    l->prev = li;
    l->a = b;
    return 1;
}

int shift(List* li, int* x)
{
    if (li == NULL)
    {
        return 0;
    }
    *x = li->next->a;
    return 1;
}
void print_list(List* li)
{
    List*el = li->next;
    while(el != NULL)
    {
        printf("%d\n", el->a);
        el = el->next;
    }
}

int main(void)
{
    List* list = list_new();
    printf("new list a:%d\n", list->a);
    int b = 23;
    printf("push 23: %d\n", push(list, &b));
    int i = 0;
    for (i = 0; i <= 10; i += 1)
    {
        int k;
        k = push(list, &i);
    }
    int c;
    printf("pop : %d\n", pop(list, &c));
    printf("last element: %d\n", c);
    int d = 155;
    printf("unshift : %d\n", unshift(list, d));
    printf("first element: %d\n", list->next->a);
    int e;
    printf("shift : %d\n", shift(list, &e));
    printf("shift first element: %d\n", e);
    print_list(list);
    printf("list before delete:\n");
    print_list(list);
    list_delete(list);
    printf("list after delete:\n");
    print_list(list);
    return 0 ;
}
