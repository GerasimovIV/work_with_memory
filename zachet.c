#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            char mas[50] = {0};
            strcpy(mas, li->number);
            strcpy(li->number, num);
            printf("Change. Old value = %s\n", mas);
            return 0;
        }
        li = li->next;
    }
    if ((li->next == NULL) && strcmp(li->name, nam) == 0)
    {
        char mas[50] = {0};
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
    if (strcmp(na, b->name) != 0)
    {
        puts("NO");
        return 0;
    }
    printf("%s\n", b->number);
    return 0;
}


void print_revers(book* list)
{
    while (list->next != NULL)
    {
        list = list->next;
    }
    while (list->prev != NULL)
    {
        printf("name: %s number: %s\n", list->name, list->number);
        list = list->prev;
    }
}

int main()
{
    book* book1 = book_new();
    char insert[7];
    insert[0] = 'I';
    insert[1] = 'N';
    insert[2] = 'S';
    insert[3] = 'E';
    insert[4] = 'R';
    insert[5] = 'T';
    insert[6] = '\0';
    char find[5];
    find[0] = 'F';
    find[1] = 'I';
    find[2] = 'N';
    find[3] = 'D';
    find[4] = '\0';
    char a[100];
    //file descriptor (указатель на файл
    FILE* in_fd;
    if ((in_fd = fopen("input.txt", "r")) == NULL)
    {
        printf("Can not open file!\n");
        return -1;
    }
    while (fgets(a, 100, in_fd))
    {
        //читаем первое слово-команду
        int i = 0;
        char comanda[10] = {0};
        while (a[i] != ' ')
        {
            comanda[i] = a[i];
            i += 1;
        }
        i += 1;
        if (strcmp(comanda, find) == 0)
        {
            //читаем дальше - кого найти
            int j = 0;
            char no_name[50];
            while (a[i] != '\n')
            {
                no_name[j] = a[i];
                i += 1;
                j += 1;
            }
            no_name[j] = '\0';
            // выполняем поиск
            find_person(book1, no_name);
        }
        if (strcmp(comanda, insert) == 0)
        {
            //читаем имя
            int j = 0;
            char n_name[50];
            while (a[i] != ' ')
            {
                n_name[j] = a[i];
                i += 1;
                j += 1;
            }
            n_name[j] = '\0';
            i += 1;
            //читаем номер
            j = 0;
            char n_number[50];
            while (a[i] != '\n')
            {
                n_number[j] = a[i];
                i += 1;
                j += 1;
            }
            n_number[j] = '\0';
            //выполняем команду insert
            add_new_person(book1, n_name, n_number);
        }
    }
    fclose(in_fd);
    print_revers(book1);
    return 0;
}
