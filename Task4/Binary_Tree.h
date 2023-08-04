#include <stdio.h>
#include <stdlib.h>

typedef struct Binary_Tree
{
    int data;
    struct Binary_Tree* left_child;
    struct Binary_Tree* right_child;
} Binary_Tree;


void add_child(Binary_Tree**, int d_);
int print_tree(Binary_Tree*, int);
void menu();