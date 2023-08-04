#include "One_link_list.h"

void menu(int* ans_, One_link_list** head_list)
{
    int data = 0;
    do
    {
        printf("1.Add into head 2.Add into tail 3.Delete from head\n");
        printf("4.Delete from tail 5.Printf from head 6.Print from tail\n");
        printf("7.Fill list random value 8.Clean all list 9.Back to main menu\n");
        printf(">_");
        scanf("%d", ans_);

        switch (*ans_)
        {
        case 1:
            printf("Enter data for list:\n>_");
            scanf("%d", &data);
            push_head(head_list, data);
            break;
        case 2:
            printf("Enter data for list:>_");
            scanf("%d", &data);
            push_tail(head_list, data);
            break;
        case 3:
            pop_head(head_list);
            break;
        case 4:
            pop_tail(head_list);
            break;
        case 5:
            print_from_head(*head_list);
            break;
        case 6:
            print_from_tail(*head_list);
            break;
        case 7:
            fill_random(head_list);
            break;
        case 8:
            deep_clean(head_list);
            *head_list = NULL;
            break;
        case 9:
            break;
        default:
            printf("Please, enter correct value!!\n\n");
            break;
        }
        
    } while (*ans_ != 9);
    
}

void push_head(One_link_list** list_, int d_)
{
    One_link_list* tmp = (One_link_list*)malloc(sizeof(One_link_list));
    tmp->data = d_;

    tmp->next = *list_;
    *list_ = tmp;
}

void push_tail(One_link_list** list_, int d_)
{
    if(*list_ == NULL)
    {
        push_head(list_, d_);
    } else
    {
        One_link_list* tmp, *prev;

        tmp = (One_link_list*)malloc(sizeof(One_link_list));
        tmp->data = d_;

        prev = *list_;

        for (;prev->next != NULL;)
        {
            prev = prev->next;
        }

        prev->next = tmp;
        tmp->next = NULL;
        
        
    }
    
}

void pop_head(One_link_list** list_)
{
    One_link_list* tmp = (*list_)->next;
    free(*list_);
    *list_ = tmp;
}

void pop_tail(One_link_list** list_)
{
    One_link_list* p;
    p = *list_;

    for (;;)
    {
        if (p->next->next == NULL)
        {
            free(p->next);
            p->next = NULL;
            break;
        } else
        {
            p = p->next;
        }
    }
}

int print_from_head(One_link_list* list_)
{
    if (list_ == NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    

    for (;list_->next != NULL;)
    {
        printf("%d \n\n", list_->data);
        list_ = list_->next;
    }
    printf("%d \n\n", list_->data);
    
    return 0;
}

int print_from_tail(One_link_list* list_)
{
    if (list_ == NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    
    One_link_list* tmp = list_;
    for (; tmp->next != NULL;)
    {
        print_from_tail(tmp->next);
        break;
    }
    
    printf("%d \n\n",tmp->data);
    
    return 0;
}

void fill_random(One_link_list** list_)
{
    int numbers_of_notes = DEFAULT__;
    int user_change = 0;
    int ans = 0;
    printf("You'll have 10 notes default. Do you wanna change this number?");
    do
    {
        printf("Enter 1(yes) or 2(no)\n");
        printf(">_");
        scanf("%d", &ans);
        switch (ans)
        {
        case 1:
            printf("Enter the numers\n");
            printf(">_");
            scanf("%d", &user_change);
            numbers_of_notes = user_change;
            break;
        case 2:
            break;
        default:
            printf("Please, enter the correct answer!\n\n");
            break;
        }
        
    } while (ans != 1 && ans != 2);

    for (int i = 0; i < numbers_of_notes; i++)
    {
        int data = (rand() % (100 - 50 + 1)) + 50;
        push_head(list_, data);
        printf("1\n");
    }
}

int deep_clean(One_link_list** list_)
{
    One_link_list* tmp = *list_;

    if (tmp == NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    

    for (; tmp->next != NULL;)
    {
        deep_clean(&tmp->next);
        free(tmp);
        break;
    }
    
    return 0;
}