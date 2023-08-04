#include "Main_function.h"



void main_menu()
{
    printf("Choose the list!\n");
    printf("1.First linked list 2.Second linked list 3.Union lists\n");
    printf("4.Cross lists 5.Find difference of lists 0.Close the programm\n");

}

void union_list(One_link_list** first_, One_link_list** second_, One_link_list** _union_)
{
    One_link_list* p_s, *p_f, *such_el;
    int count = 0;

    such_el = NULL;

    p_s = *second_;
    p_f = *first_;

    //You need to make a full this solution
    for (;p_f->next != NULL;)
    {
        for (;p_s->next != NULL;)
        {
            if (p_s->data != p_f->data)
            {
                push_tail(_union_, p_s->data);
                p_s = p_s->next;
            } else
            {
                p_s = p_s->next;
            }            
        }
        p_s = *second_;
        p_f = p_f->next;
    }
    
    print_from_head(*_union_);
    
}

void cross_list(One_link_list** first_, One_link_list** second_, One_link_list** _cross_)
{
    One_link_list* p_f, *p_s;
    p_f = *first_;
    p_s = *second_;

    for (;p_f->next != NULL;)
    {
        for (;p_s->next != NULL;)
        {
            if (p_s->data == p_f->data)
            {
                push_tail(_cross_, p_f->data);
                p_s = p_s->next;
            } else
            {
                p_s = p_s->next;
            }
            
        }
        p_s = *second_;
        p_f = p_f->next;
    }
    
    print_from_head(*_cross_);
}

void less_list(One_link_list** first_, One_link_list** second_, One_link_list** _less_)
{
    One_link_list* p_f, *p_s;
    p_f = *first_;
    p_s = *second_;
    int count = 0;

    for (;p_f->next != NULL;)
    {
        for (;p_s->next != NULL;)
        {
            if (p_f->data == p_s->data)
            {
                count++;
                p_s = p_s->next;
            } else
            {
                p_s = p_s->next;
            }
        }

        if (count == 0)
        {
            push_tail(_less_, p_f->data);
        } else
        {
            count = 0;
        }
        p_s = *second_;
        p_f = p_f->next;
        
    }
    print_from_head(*_less_);
}