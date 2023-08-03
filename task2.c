#include <stdio.h>
#include <stdlib.h>

int solution_of_task(int, int, int, int);
//Displays pics of solution this task
// void print_barrel(int, int, int);

int main ()
{
    int a, b, c, R;

    printf("Enter the capacity for smaller barrel\n>_");
    scanf("%d", &a);

    do
    {
        printf("Enter the capacity for middle barrel\n>_");
        scanf("%d", &b);
    } while (a > b);
    
    do
    {
        printf("Enter the capacity for biggest barrel\n>_");
        scanf("%d", &c);

    } while (b > c || a > c);

    printf("Enter the capacity that you want to find\n>_");
    scanf("%d", &R);
    solution_of_task(a, b, c, R);

    system("PAUSE");

    return 0;
}


int solution_of_task(int a_, int b_, int c_, int R_)
{
    //The number of step
    //Change variables by array later
    int count = 0;
    int current_liters_for_smaller = 0;
    int current_litters_for_middle = 0;
    int current_litters_for_biggest = c_;

    do
    {
        //The middle barrel make to fill full
        for (;current_litters_for_middle != b_;)
        {
            current_litters_for_biggest = current_litters_for_biggest - (a_ - current_liters_for_smaller);
            current_liters_for_smaller = a_;
            count++;
            if (current_litters_for_biggest == R_)
            {
                printf("%d) There are %d liters in smaller barrel, %d liters in middle barrel, %d liters in biggest barrel\n", count, current_liters_for_smaller, current_litters_for_middle, current_litters_for_biggest);
                printf("The task is completed\n");
                return 0;
            }

            printf("%d) There are %d liters in smaller barrel, %d liters in middle barrel, %d liters in biggest barrel\n", count, current_liters_for_smaller, current_litters_for_middle, current_litters_for_biggest);

            for (; current_liters_for_smaller != 0; current_liters_for_smaller--)
            {
                if (current_litters_for_middle == b_)
                {
                    break;
                }

                current_litters_for_middle++;
            }
            count++;
            printf("%d) There are %d liters in smaller barrel, %d liters in middle barrel, %d liters in biggest barrel\n", count, current_liters_for_smaller, current_litters_for_middle, current_litters_for_biggest);
        }

        //Fill biggest barrel by middle barrel
        current_litters_for_biggest = current_litters_for_biggest + current_litters_for_middle;
        current_litters_for_middle = 0;
        count++;
        printf("%d) There are %d liters in smaller barrel, %d liters in middle barrel, %d liters in biggest barrel\n", count, current_liters_for_smaller, current_litters_for_middle, current_litters_for_biggest);
        if (current_liters_for_smaller != 0)
        {
            //if it need, make to free smaller by middle
            current_litters_for_middle = current_liters_for_smaller;
            current_liters_for_smaller = 0;

            count++;
            printf("%d) There are %d liters in smaller barrel, %d liters in middle barrel, %d liters in biggest barrel\n", count, current_liters_for_smaller, current_litters_for_middle, current_litters_for_biggest);
        }

    } while (1);
    

    // for (; b_ != b;)
    // {
    //     c_ = c_ - (a - a_);
    //     a_ = a;
    //     count_++;
    //     if (c_ == R)
    //     {
    //         printf("%d) There are %d liters in smaller barrel, %d liters in middle barrel, %d liters in biggest barrel\n", count_, a_, b_, c_);
    //         printf("The task is completed\n");
    //         return 0;
    //     }

    //     printf("%d) %d liters in smaller, %d liters in middle, %d liters in biggest\n", count_, a_, b_, c_);

    //     for (;a_ != 0;a_--)
    //     {
    //         if (b_ == b)
    //         {
    //             break;
    //         }

    //         b_++;
    //     }
    //     count_++;
    //     printf("%d) %d liters in smaller, %d liters in middle, %d liters in biggest\n", count_, a_, b_, c_);
    // }
     
    // c_ = c_ + b_;
    // b_ = 0;
    // count_++;
    // printf("%d) %d liters in smaller, %d liters in middle, %d liters in biggest\n", count_, a_, b_, c_);
    // if (a_ != 0)
    // {
    //     b_ = a_;
    //     a_ = 0;

    //     count_++;
    //     printf("%d) %d liters in smaller, %d liters in middle, %d liters in biggest\n", count_, a_, b_, c_);
    // }
    
    // solution_of_task(a_, b_, c_, count_);
}

// void print_barrels(int a_, int b_, int c_)
// {
//     return 0;
// }
// printf("%d) %d liters in smaller, %d liters in middle, %d liters in biggest\n", count_, a_, b_, c_);