#ifndef ONE_LINK_LIST_H

#define ONE_LINK_LIST_H

#endif

#include "Main_function.h"


int main()
{
    One_link_list* head_first = NULL;
    One_link_list* head_second = NULL;
    One_link_list* union_ = NULL;
    One_link_list* cross_ = NULL;
    One_link_list* less_ = NULL;

    int ans = 0;

    do
    {
        main_menu();
        printf(">_");
        scanf("%d", &ans);

        switch (ans)
        {
        case 1:
            ans = 0;
            menu(&ans, &head_first);
            break;
        case 2:
            ans = 0;
            menu(&ans, &head_second);
            break;
        case 3:
            union_list(&head_first, &head_second, &union_);
            break;
        case 4:
            cross_list(&head_first, &head_second, &cross_);
            break;
        case 5:
            less_list(&head_first, &head_second, &less_);
            break;
        case 0:
            printf("Good bye, user!\n");
            system("PAUSE");
            break;
        default:
            printf("Please, enter correct value!\n\n");
            break;
        }


    } while (ans != 0);
    

    return 0;
}