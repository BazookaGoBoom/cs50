#include <cs50.h>
#include <stdio.h>

int height=0;
int main(void)
{
    while (!(height <= 8 && height >= 1))
    {
        height = get_int("Height:");
    }
    for (int y = 1; y < height + 1; y++)
    {
        for (int x=1; x < height + 1; x++)
        {
            if (x < height + 1 - y)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        for (int brick=0; brick < y; brick++)
        {
            printf("#");
        }
        printf("\n");
    }
}