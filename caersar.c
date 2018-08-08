/**cs50 credit - week1
*@author Vuong Nguyen me@vuongnguyen.net
*/

#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include <string.h>
#include <ctype.h>


//https://docs.cs50.net/2018/x/psets/2/caesar/caesar.html#tl-dr
int main(int argc, string argv[])
{

    if (argc != 2)
    {

        printf("Usage: ./caesar k\n");

        return 1;
    }

    /*Get the argument index 1 */
    string argument_truyen_vao = argv[1];

    /*Convert to integer*/
    int chuyensangso = atoi(argument_truyen_vao);

    if (chuyensangso < 0)
    {
        printf("Usage: ./caesar k\n");

        return 1;
    }


    //printf("key là %d", chuyensangso);


    string s = get_string("plaintext: ");

    // string abc = "abc test";
    // printf("chuỗi %c \n", abc[0] + 1);

    // printf("chuỗi %d \n", abc[0]);

    // printf("chuỗi %d \n", abc[0] + 1);


    int leng = strlen(s);

    printf("ciphertext: ");

    /*Make sure that k always less than 26, dùng toàn tử chia hết*/
    chuyensangso = chuyensangso % 26;

    for (int i = 0; i < leng; i++)
    {

        if (islower(s[i]))
        {
            /*nếu tổng vượt quá 122, thì trừ đi 26 để quay lui lại bảng*/
            if (s[i] + chuyensangso > 122)
            {
                printf("%c", (s[i] + chuyensangso - 26));
            }
            else
            {
                printf("%c", (s[i] + chuyensangso));
            }
        }
        else if (isupper(s[i]))
        {
            /*nếu tổng vượt quá 90, là chữ hoa, thì trừ đi 26 để quay lui lại bảng*/
            if (s[i] + chuyensangso > 90)
            {
                printf("%c", (s[i] + chuyensangso - 26));
            }
            else
            {
                printf("%c", (s[i] + chuyensangso));
            }
        }
        else
        {
            printf("%c", s[i]);
        }


        //https://reference.cs50.net/ctype/islower

    }

    printf("\n");


    return 0;
}
