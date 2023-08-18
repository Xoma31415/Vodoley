#include "Main_function.h"



void main_menu()
{
    printf("Choose the list!\n");
    printf("1.First linked list 2.Second linked list 3.Union lists\n");
    printf("4.Cross lists 5.Find difference of lists 0.Close the programm\n");

}

int union_list(One_link_list** first_, One_link_list** second_, One_link_list** _union_)
{
    if (*first_ == NULL || *second_ == NULL)
    {
        printf("This Operation is impossible!\n");
        return 0;
    }

    One_link_list* p_s = *second_;
    One_link_list* p_f = *first_;
    int count = 0;

    for (;p_f->next != NULL;)
    {
        push_tail(_union_, p_f->data);
        p_f = p_f->next;
    }
    
    p_f = *first_;

    for (;p_s->next != NULL;)
    {
        for (;p_f->next != NULL;)
        {
            if (p_f->data == p_s->data) count++;
            p_f = p_f->next;
        }

        if (count == 0) push_tail(_union_, p_s->data);
        p_f = *first_;
        p_s = p_s->next;      
        
    }
    
   
    
    print_from_head(*_union_);
    deep_clean(_union_);
    *_union_ = NULL;

    return 0;
    
}

int cross_list(One_link_list** first_, One_link_list** second_, One_link_list** _cross_)
{
    if (*first_ == NULL || *second_ == NULL)
    {
        printf("This Operation is impossible!\n");
        return 0;
    }

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
    deep_clean(_cross_);
    *_cross_ = NULL;

    return 0;
}

int less_list(One_link_list** first_, One_link_list** second_, One_link_list** _less_)
{
    if (*first_ == NULL || *second_ == NULL)
    {
        printf("This Operation is impossible!\n");
        return 0;
    }

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
    deep_clean(_less_);
    *_less_ = NULL;

    return 0;
}