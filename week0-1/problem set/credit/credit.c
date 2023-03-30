#include <cs50.h>
#include <stdio.h>

long get_number(void);
bool is_valid(long number);
void check_type(bool valid);
long card_number;

int main(void)
{
    // get the card number input from the user
    card_number = get_number();

    // check if the card number satisfies luhn's algorithm
    bool validation = is_valid(card_number);

    // check the card type
    check_type(validation);
}

void check_type(bool valid)
{
    if (valid)
    {
        long visa = card_number;
        long amex = card_number;
        long master = card_number;

        // calculate the length of card number
        int length = 0;
        do
        {
            card_number = card_number / 10;
            length++;
        }
        while (card_number > 0);

        // check for VISA
        while (visa >= 10)
        {
            visa = visa / 10;
        }
        if (visa == 4 && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else if (length < 13)
        {
            printf("INVALID\n");
        }

        // check for AMEX
        amex = amex / 10000000000000;
        if ((amex == 37 || amex == 34) && length == 15)
        {
            printf("AMEX\n");
        }
        else if (amex > 34 && amex < 37)
        {
            printf("INVALID\n");
        }

        // check for MASTERCARD
        master = master / 100000000000000;
        if ((master == 51 || master == 52 || master == 53 || master == 54 || master == 55) && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (master > 55)
        {
            printf("INVALID\n");
        }
    }
}

bool is_valid(long number)
{
    // get the even placed numbers from right to left
    int num2 = number % 10; // 7
    int num4 = (number % 1000) / 100; // 5
    int num6 = (number % 100000) / 10000; // 3
    int num8 = (number % 10000000) / 1000000; // 1
    int num10 = (number % 1000000000) / 100000000; // 8
    int num12 = (number % 100000000000) / 10000000000; // 6
    int num14 = (number % 10000000000000) / 1000000000000; // 4
    int num16 = (number % 1000000000000000) / 100000000000000; // 2

    // sum even placed numbers
    int even_total = num2 + num4 + num6 + num8 + num10 + num12 + num14 + num16;

    // get the odd placed numbers and multiply them by two
    int num1 = (number % 100 / 10) * 2; // 6
    int num3 = (number % 10000 / 1000) * 2; // 4
    int num5 = (number % 1000000 / 100000) * 2; // 2
    int num7 = (number % 100000000 / 10000000) * 2; // 9
    int num9 = (number % 10000000000 / 1000000000) * 2; // 7
    int num11 = (number % 1000000000000 / 100000000000) * 2; // 5
    int num13 = (number % 100000000000000 / 10000000000000) * 2; // 3
    int num15 = (number % 10000000000000000 / 1000000000000000) * 2; // 1

    // sum the digits
    num1 = (num1 % 100 / 10) + (num1 % 10);
    num3 = (num3 % 100 / 10) + (num3 % 10);
    num5 = (num5 % 100 / 10) + (num5 % 10);
    num7 = (num7 % 100 / 10) + (num7 % 10);
    num9 = (num9 % 100 / 10) + (num9 % 10);
    num11 = (num11 % 100 / 10) + (num11 % 10);
    num13 = (num13 % 100 / 10) + (num13 % 10);
    num15 = (num15 % 100 / 10) + (num15 % 10);

    // total of multiplied and digit summed odd numbers
    int odd_total = num1 + num3 + num5 + num7 + num9 + num11 + num13 + num15;

    // sum of even and odd digits
    int total = even_total + odd_total;

    // if it satisfies luhn's algorithm it returns true, otherwise the number is invalid
    if (total % 10 == 0)
    {
        return true;
    }
    else
    {
        printf("INVALID\n");
        return false;
    }
}

long get_number(void)
{
    long n;
    // asks the user for input as long as input is less than zero
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);
    return n;
}