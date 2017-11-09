# work_with_memory
#include<stdio.h>
#include<stdlib.h>

typedef struct list_element {
    int a;
    int b;
    double c;
    struct list_element* next;
    struct list_element* prev;
} list_element;

list_element* create_list_element(int a, int b, double c)
{
    list_element* pstr = malloc(sizeof(list_element));
    pstr->a = a;
    pstr->b = b;
    pstr->c = c;
    pstr->next = NULL;
    pstr->prev = NULL;
    return pstr;
}

void insert_into_list(list_element* a, list_element* b)
{
    list_element* c = a->next;
    a->next = b;
    b->prev = a;
    b->next = c;
    if(c != NULL)
        c->prev = b;
}

void print_list(list_element* a)
{
    list_element* el;
    el = a;
    while(el != NULL) {
        printf("value = %d\n", el->a);
        el = el->next;
    }
}

list_element* get_by_number(list_element* a, int number)//буду считать что нумерация элементов списка с нуля
{
    list_element* el;
    el = a;
    int i;
    for (i = 1; i <= number; i++)
    {
        if (el == NULL)
        {
            prinf("запрошен не существующий элемент списка");
            return NULL;
        }
        el = el->next;
    }
    return el;
}

void delete_from_list(list_element* a)
{
    list_element* pred_el, sled_el;
    pred_el = a->prev;
    sled_el = a->next;
    pred_el->next = sled_el;
    sled_el->prev = pred_el;
    return 0;
}

int main()
{
    list_element* r = create_list_element(42, -1, 3.14);
    int i;
    list_element* ri;
    for(i = 0; i < 10; i++) {
        ri = create_list_element(i, -i, 3.14);
        insert_into_list(r, ri);
    }

    print_list(r);

    list_element* to_delete = get_by_number(r, 6);
    delete_from_list(to_delete);
    printf("%d\n", to_delete->a);

    print_list(r);

    return 0;
}
