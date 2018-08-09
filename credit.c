/**cs50 credit - week1
*@author Vuong Nguyen me@vuongnguyen.net
*/

#include<stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{

    long long creditcard = 0;

    do
    {
        creditcard = get_long_long("Enter your credit card number: ");
    }
    while
    (
        creditcard <= 0
    );

    long long creditcardnumber = creditcard;

    //convert from integer to char
    char str[16];

    sprintf(str, "%llu", creditcard);

    char firstnumber = str[0];
    char secondnumber = str[1];

    // printf("số đầu là %c \n", firstnumber);
    // printf("số đầu là %d \n", firstnumber);
    // printf("số thứ hai là %c \n", secondnumber);
    // printf("số thứ hai là %d \n", secondnumber);


    int leng = strlen(str);

    if ((leng != 13 && leng != 15 && leng != 16) || (firstnumber != 51 && firstnumber != 52 && firstnumber != 53))
    {

        printf("INVALID\n");
        exit(0);
    }

    if (firstnumber == 53)
    {
        /*comparison using char value*/
        if (secondnumber != 49 && secondnumber != 50 && secondnumber != 51 && secondnumber != 52 && secondnumber != 53)
        {
            printf("INVALID\n");
            exit(0);
        }

    }

    if (firstnumber == 51)
    {
        /*comparison using char value*/
        if (secondnumber != 52 && secondnumber != 55)
        {
            printf("INVALID\n");
            exit(0);
        }

    }


    /*an array*/
    int number[leng];

    //printf("chiều dài chuỗi%d \n", leng);

    for (int i = 0; i < leng; i++)
    {

        /*Get the seperated number, turn into array */
        number[i] = creditcardnumber % 10;

        /*devided to 10*/
        creditcardnumber = creditcardnumber / 10;

        //printf("số xuôi %d\n", number[i]);
    }


    /*GET THE OTHER NUMBER: PLUS 2 AND SUM*/

    int sole[leng];
    int tongsosole = 0;
    int vidutong = 0;
    int sotamthoi;
    for (int i = 1; i < leng; i = i + 2)
    {

        sole[i] = number[i] * 2;

        sotamthoi = sole[i] % 10 + sole[i] / 10;

        vidutong = vidutong + sotamthoi;

        tongsosole++;

        //printf("số lẻ %d\n", sole[i]);

    }

    //printf("tổng số lẻ, tính từ index 1 %d \n", vidutong);

    /*GET THE REMANING NUMBER BY SUM*/

    int soconlai[leng];
    int tongsoconlai = 0;

    for (int i = 0; i < leng; i = i + 2)
    {
        soconlai[i] = number[i];
        tongsoconlai = tongsoconlai + soconlai[i];
    }

    //printf("tổng số, tính từ index 0 còn lại%d", tongsoconlai);


    int finalnumber = vidutong + tongsoconlai;


    if (finalnumber % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (leng == 15)
        {
            printf("AMEX\n");
        }
        else if (leng == 13)
        {
            printf("VISA\n");
        }
        else
        {
            if (firstnumber == 52)
            {
                printf("VISA\n");
            }
            else
            {
                printf("MASTERCARD\n");
            }
        }

    }



    // credit: https://cs50.stackexchange.com/questions/22910/pset-1-credit-card-help-needed

    return 0;

}