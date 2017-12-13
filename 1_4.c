#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int proverka(char * a)// for big stroka
{
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] == '\n')
        {
            return 1;
        }
        i += 1;

    }
    return 0;
}
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
    List* l = (List*)malloc(sizeof(List));
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

void find_and_delete(List* li)
{
    int g = 0;
    while (li->next->next != NULL)
    {
        g = 0;
        if ((li->a > 0) && ((li->a + li->next->a) ==0))
        {
            li->prev->next = li->next->next;
            li->next->next->prev = li->prev;
            li = li->prev;
            g = 1;
        }
        if (g == 0)
        {
            li = li->next;
        }
    }
    if((li->next->next == NULL) && ((li->a > 0) && ((li->a + li->next->a) ==0))) //for last element
    {
        li->prev->next = NULL;
    }
}
int main(void)
{
    FILE* in_fd;
    int n = 5;
    int k = 1;
    in_fd = fopen("input.txt", "r");
    char * m1 = (char*)malloc(n * sizeof(char));
    char * m2 = (char*)malloc(n * sizeof(char));
    while (fgets(m1, n, in_fd))
    {
        if (proverka(m1) == 0)
        {
            n *= 2;
            m2 = (char*)realloc(m2, n * sizeof(char));
            strcat(m2, m1);

        }
        else
        {
            strcat(m2, m1);

        }

    }
    free(m1);
    fclose(in_fd);
    //puts(m2);

    List* stroka = list_new();
    int i = 0;
    int p = 0;
    while(m2[i] != '\0')
    {

        if (m2[i] == '(')
        {
            int a1 = 1;

            p = push(stroka, &a1);
        }
        if (m2[i] == ')')
        {

            int a2 = -1;
            p = push(stroka, &a2);
        }
        if (m2[i] == '{')
        {
            int a3 = 2;
            p = push(stroka, &a3);
        }
        if (m2[i] == '}')
        {
            int a4 = -2;
            p = push(stroka, &a4);
        }
        i += 1;
    }
    free(m2);
    find_and_delete(stroka);
    //printf("after...\n");
    print_list(stroka);
    if (stroka->next != NULL)
    {
        printf("wrong bracket expression\n");//
    }
    else
    {
        printf("correct bracket expression\n");
    }

    return 0 ;
}
