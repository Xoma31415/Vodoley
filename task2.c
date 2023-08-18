#include <stdio.h>
#include <stdlib.h>

int solution_of_task(int, int, int, int);

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

    
    do
    {
        printf("Enter the capacity that you want to find\n>_");
        scanf("%d", &R);
    } while (R < c);
    


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
            if (a_ > current_litters_for_biggest)
            {
                for (;current_litters_for_biggest != 0;)
                {
                    current_liters_for_smaller++;
                    current_litters_for_biggest--;
                }

                printf("%d) There are %d liters in smaller barrel, %d liters in middle barrel, %d liters in biggest barrel\n", count, current_liters_for_smaller, current_litters_for_middle, current_litters_for_biggest);

                break;
            }
            
            if (current_litters_for_biggest == R_ || current_litters_for_middle == R_)
            {
                printf("%d) There are %d liters in smaller barrel, %d liters in middle barrel, %d liters in biggest barrel\n", count, current_liters_for_smaller, current_litters_for_middle, current_litters_for_biggest);
                printf("The task is completed\n");
                return 0;
            }

            current_litters_for_biggest = current_litters_for_biggest - (a_ - current_liters_for_smaller);
            current_liters_for_smaller = a_;
            count++;

            if (current_litters_for_biggest == R_ || current_litters_for_middle == R_)
            {
                printf("%d) There are %d liters in smaller barrel, %d liters in middle barrel, %d liters in biggest barrel\n", count, current_liters_for_smaller, current_litters_for_middle, current_litters_for_biggest);
                printf("The task is completed\n");
                return 0;
            }

            // printf("lol\n"); 
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
            // printf("lol\n");
            if (current_litters_for_biggest == R_ || current_litters_for_middle == R_)
            {
                printf("%d) There are %d liters in smaller barrel, %d liters in middle barrel, %d liters in biggest barrel\n", count, current_liters_for_smaller, current_litters_for_middle, current_litters_for_biggest);
                printf("The task is completed\n");
                return 0;
            }
            printf("%d) There are %d liters in smaller barrel, %d liters in middle barrel, %d liters in biggest barrel\n", count, current_liters_for_smaller, current_litters_for_middle, current_litters_for_biggest);
        }

        //Fill biggest barrel by middle barrel
        current_litters_for_biggest = current_litters_for_biggest + current_litters_for_middle;
        current_litters_for_middle = 0;
        count++;
        // printf("lol\n");
        printf("%d) There are %d liters in smaller barrel, %d liters in middle barrel, %d liters in biggest barrel\n", count, current_liters_for_smaller, current_litters_for_middle, current_litters_for_biggest);
        if (current_liters_for_smaller != 0)
        {
            //if it need, make to free smaller by middle
            current_litters_for_middle = current_liters_for_smaller;
            current_liters_for_smaller = 0;

            count++;
            // printf("lol\n");
            printf("%d) There are %d liters in smaller barrel, %d liters in middle barrel, %d liters in biggest barrel\n", count, current_liters_for_smaller, current_litters_for_middle, current_litters_for_biggest);
        }

    } while (1);
    

}