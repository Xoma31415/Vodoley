#include <stdio.h>
#include <stdlib.h>

int a, b, c, R;
int solution_of_task(int, int, int, int);
// void print_barrel(int, int, int);

int main ()
{
    //Find solution in hand and write the algorithm
    printf("Enter the capacity for smaller barrel\n>_");
    scanf("%d", &a);

check_middle:
    printf("Enter the capacity for middle barrel\n>_");
    scanf("%d", &b);
    while (a > b)
    {
        goto check_middle;
    }

check_biggest:
    printf("Enter the capacity for biggest barrel\n>_");
    scanf("%d", &c);
    while (b > c || a > c)
    {
        goto check_biggest;
    }

    int current_liters_for_smaller = 0;
    int current_litters_for_middle = 0;
    int current_litters_for_biggest = c;

    int count = 0;

    //Maybe, It needs more variables and pointers
    //for campare values in barrels

    printf("Enter the capacity that you want to find\n>_");
    scanf("%d", &R);
    solution_of_task(current_liters_for_smaller, current_litters_for_middle, current_litters_for_biggest, count);

    system("PAUSE");

    return 0;
}


int solution_of_task(int a_, int b_, int c_, int count_)
{

    for (; b_ != b;)
    {
        c_ = c_ - (a - a_);
        a_ = a;
        count_++;
        if (c_ == R)
        {
            printf("%d) There are %d liters in smaller barrel, %d liters in middle barrel, %d liters in biggest barrel\n", count_, a_, b_, c_);
            printf("The task is completed\n");
            return 0;
        }

        printf("%d) %d liters in smaller, %d liters in middle, %d liters in biggest\n", count_, a_, b_, c_);

        for (;a_ != 0;a_--)
        {
            if (b_ == b)
            {
                break;
            }

            b_++;
        }
        count_++;
        printf("%d) %d liters in smaller, %d liters in middle, %d liters in biggest\n", count_, a_, b_, c_);
    }
     
    c_ = c_ + b_;
    b_ = 0;
    count_++;
    printf("%d) %d liters in smaller, %d liters in middle, %d liters in biggest\n", count_, a_, b_, c_);
    if (a_ != 0)
    {
        b_ = a_;
        a_ = 0;

        count_++;
        printf("%d) %d liters in smaller, %d liters in middle, %d liters in biggest\n", count_, a_, b_, c_);
    }
    
    solution_of_task(a_, b_, c_, count_);
}

// void print_barrels(int a_, int b_, int c_)
// {
//     return 0;
// }
// printf("%d) %d liters in smaller, %d liters in middle, %d liters in biggest\n", count_, a_, b_, c_);