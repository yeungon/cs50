#include<stdio.h>
#include <cs50.h>

/*https://reference.cs50.net/cs50/get_int*/

// https://manual.cs50.net/style#line-length

int main(void)
{
    int height;

    height = get_int("Height: ");

    if (height > 0 && height <= 23)
    {
            for (int i = 0; i < height; i++)
            {
                /*print the space first, the number of space depends on the height*/
                for (int j = 1; j < height - i; j++)
                {
                    printf(" ");
                }

                /*print the hash*/
                for (int k = 0; k <= i; k++)
                {
                    printf("#");
                }

                /*print the middle space == gap*/
                printf("  ");

                /*print the right hash that depends on the height*/

                for (int l = 0; l <= i; l++)
                {
                    printf("#");
                }

                /*print the new line*/
                printf("\n");
            }
    }

}