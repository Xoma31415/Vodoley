#include "Binary_Tree.h"



int main()
{
    Binary_Tree* root = NULL;
    int answer = 0;
    int data = 0;
    int check = 0;

    do
    {
        menu();
        scanf("%d", &answer);

        switch (answer)
        {
        case 1:
            printf("Enter the value of data:\n>_");
            scanf("%d", &data);
            add_child(&root, data);
            break;
        case 2:
            print_tree(root, check);
            break;
        case 0:
            printf("Good bye, user!\n");
            system("PAUSE");
            break;
        
        default:
            printf("Please, enter correct answer!\n");
            break;
        }

    } while (answer != 0);
    

    return 0;
}