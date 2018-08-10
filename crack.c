#define _XOPEN_SOURCE
#include <unistd.h>
#include<stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>


int main(int argc, string argv[])
{

    if (argc != 2)
    {

        printf("Usage: ./crack hash\n");
        return 1;
    }

    /*Get the salt from the input hash*/
    char *hash = argv[1];

    char salt[3];
    salt[0] = hash[0];
    salt[1] = hash[1];


    char *chucai = "abcdefghijklmnopqrstuvxyzwABCDEFGHIJKLMNOPQRSTUVXYZW";

    /*although the password has only 5 characters,
    we need to allocate 6 spaces in the memory, the last one is for \0 that ends the string*/

    char password[6];

    // char *vidu = crypt("acd", "50");

    // printf("hash là: %s\n", vidu);

    // printf("hash nhập vào là: %s\n", hash);

    // printf("salt là: %s\n", salt);

    // exit(0);

    int soluot = 0;

    /*Handling the password with 1 characters*/

    for (int i = 0; i < 52; i++)
    {

        password[0] = chucai[i];
        password[1] = '\0';

        soluot++;

        printf("%d\n", soluot);

        if (strcmp(crypt(password, salt), hash) == 0)
        {
            printf("\n");
            printf("Password decrypted: %s\n", password);
            exit(0);
        }

    }


    /*Handling the password with 2 characters*/

    for (int i = 0; i < 52; i++)
    {
        soluot++;
        for (int k = 0; k < 52; k++)
        {

            password[0] = chucai[i];
            password[1] = chucai[k];
            password[2] = '\0';

            soluot++;
            printf("%d\n", soluot);

            if (strcmp(crypt(password, salt), hash) == 0)
            {
                printf("\n");
                printf("Password decrypted: %s\n", password);
                exit(0);
            }

        }
    }

    /*Handling the password with 3 characters*/

    for (int i = 0; i < 52; i++)
    {
        soluot++;
        for (int k = 0; k < 52; k++)
        {
            soluot++;
            for (int l = 0; l < 52 ; l++)
            {

                password[0] = chucai[i];
                password[1] = chucai[k];
                password[2] = chucai[l];
                password[3] = '\0';

                soluot++;
                printf("%d\n", soluot);

                int ketqua = strcmp(crypt(password, salt), hash);

                if (ketqua == 0)
                {
                    printf("\n");
                    printf("Password decrypted: %s\n", password);
                    exit(0);
                }

            }
        }
    }

    // if(strcmp(password, "ace") == 0)
    // {
    //     printf("đã tìm thấy password");
    //     exit(0);
    // }

    // if(strlen(password) > 3){

    //     printf("tạm dừng chương trình \n");

    //     // printf("%s\n", crypt(password, salt));

    //     // int ketqua = strcmp(crypt("acd", salt), "50gnUxd7SZwbs");

    //     // printf("Kết qủa: %d", ketqua);

    //     exit(0);
    // }

    /*Handling the password with 4 characters*/

    for (int i = 0; i < 52; i++)
    {
        soluot++;
        for (int k = 0; k < 52; k++)
        {
            soluot++;
            for (int l = 0; l < 52 ; l++)
            {
                soluot++;
                for (int m = 0; m < 52; m++)
                {
                    password[0] = chucai[i];
                    password[1] = chucai[k];
                    password[2] = chucai[l];
                    password[3] = chucai[m];
                    password[4] = '\0';

                    soluot++;
                    printf("%d\n", soluot);

                    if (strcmp(crypt(password, salt), hash) == 0)
                    {
                        printf("\n");
                        printf("Password decrypted: %s\n", password);
                        exit(0);
                    }

                }
            }
        }
    }

    /*Handling the password with 5 characters*/

    for (int i = 0; i < 52; i++)
    {
        soluot++;
        for (int k = 0; k < 52; k++)
        {
            soluot++;
            for (int l = 0; l < 52 ; l++)
            {
                soluot++;
                for (int m = 0; m < 52; m++)
                {
                    soluot++;
                    for (int n = 0; n < 52; n++)
                    {
                        password[0] = chucai[i];
                        password[1] = chucai[k];
                        password[2] = chucai[l];
                        password[3] = chucai[m];
                        password[4] = chucai[n];
                        password[5] = '\0';

                        soluot++;
                        printf("%d\n", soluot);

                        if (strcmp(crypt(password, salt), hash) == 0)
                        {
                            printf("\n");
                            printf("Password decrypted: %s\n", password);
                            exit(0);
                        }
                    }
                }
            }
        }
    }

    printf("\n");

    printf("Password is not found");

    return 0;
}