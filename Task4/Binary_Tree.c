#include "Binary_Tree.h"


void menu()
{
    printf("1.Add the new child of tree 2. Print tree 0.Close the programm");
    printf("\n>_");
}

void add_child(Binary_Tree** tree_, int d_)
{

    if (*tree_ == NULL)
    {
        Binary_Tree* tmp = (Binary_Tree*)malloc(sizeof(Binary_Tree));
        tmp->data = d_;
        *tree_ = tmp;
        (*tree_)->left_child = NULL;
        (*tree_)->right_child = NULL;
    } else
    {
        Binary_Tree* current = *tree_;
        if (d_ <= current->data)
        {
            add_child(&(current->left_child), d_);
        } else if (d_ >= current->data)
        {
            add_child(&(current->right_child), d_);
        }
    }
}

int print_tree(Binary_Tree* root_, int check_)
{
    if (!root_) return 0;
    check_++;

    print_tree(root_->left_child, check_);

    for (int i = 0; i < check_; i++) printf("  ");
    printf("%d\n", root_->data);

    print_tree(root_->right_child, check_);
    
    check_--;
    return 0;
    
}