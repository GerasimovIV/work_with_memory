#include <stdio.h>
#include <stdlib.h>



typedef struct book // первый элемент будет служебным
{
    char name[50];
    char number[50];
    struct book* next;
    struct book* prev;
}book;


book* book_new() // просто создаем записную книжку, те первый служебный элемент
{
   book* el = malloc(sizeof(book));
   char n1[1], n2[1];
   n1[0] = "f";
   n2[0] = "f";
   strcpy(el->name, n1);
   strcpy(el->number, n2);
   el->next = NULL;
   el->prev = NULL;
   return el;
}



void print_book(book* a)
{
    book* el = a->next;
    while(el != NULL)
    {
        printf("%s %s\n", el->name, el->number);
        el = el->next;
    }
}
void add_new_person(book* li, char* nam, char* num)// если добавляют существующее имя то меняем старый телефон на новый и пишем об этом
{
    while(li->next != NULL)
    {
        if (strcmp(li->name, nam) == 0)
        {
            char mas[50];
            strcpy(mas, li->number);
            strcpy(li->number, num);
            printf("Change. Old value = %s\n", mas);
            return 0;
        }
        li = li->next;
    }
    if ((li->next == NULL) && strcmp(li->name, nam) == 0)
    {
        char mas[50];
        strcpy(mas, li->number);
        strcpy(li->number, num);
        printf("Change. Old value = %s\n", mas);
        return 0;
    }

    book* el1 = malloc(sizeof(book));
    el1->next = NULL;
    el1->prev = li;
    li->next = el1;
    strcpy(el1->name, nam);
    strcpy(el1->number, num);
    return 0;
}
void find_person(book* b, char* na)
{
    while ((b->next != NULL) && (strcmp(na, b->name) != 0))
    {
        b = b->next;
    }
    if ((b->next == NULL) && (strcmp(na, b->name) != 0))
    {
        printf("NO\n");
        return 0;
    }
    printf("%s\n", b->number);

    return 0;
}


int main()
{

    book* book1 = book_new();
    char na[30], nu[30];
    int i;
    for (i = 0; i <= 2; i++)
    {
        scanf("%s",&na[0]);
        scanf("%s",&nu[0]);
        add_new_person(book1, na, nu);

    }
    print_book(book1);
    char fp[20];
    printf("кого найти?\n");
    scanf("%s",&fp[0]);
    find_person(book1, fp);
    printf("добавь существующего\n");
    char n01[20], n02[20];
    scanf("%s %s", &n01[0], &n02[0]);
    add_new_person(book1, n01, n02);
    print_book(book1);

    return 0;
}
