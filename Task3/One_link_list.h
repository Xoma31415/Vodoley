#include <stdio.h>
#include <stdlib.h>
#define DEFAULT__ 10

typedef struct One_link_list
{
    int data;
    struct One_link_list* next;
}One_link_list;

void push_head(One_link_list** ,int);
void push_tail(One_link_list** ,int);
void pop_head(One_link_list**);
void pop_tail(One_link_list**);
int print_from_head(One_link_list*);
int print_from_tail(One_link_list*);
void fill_random(One_link_list**);
int deep_clean(One_link_list**);
void menu(int* , One_link_list**);