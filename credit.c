#include <cs50.h>
#include <stdio.h>

bool isOddDigit = false;
int sum = 0;
bool isMasterCard = false;
bool isAmericanExpress = false;
bool isVisa = false;
int digits = 1;
bool isValid = false;
int tempSum;

int main(void) 
{
    long cardNumber = get_long("What is your credit card number?:");
    long test = cardNumber;
    printf("%ld\n", test);
    while (test >= 10L)
    {
        digits += 1;
        if (test <= 99L)
        {
            if (test >= 51 && test <= 55)
            {
                isMasterCard = true;
                printf("\nnumber between 51 and 55 inclusive");
            }
            else if (test == 34 || test == 37)
            {
                isAmericanExpress = true;
                printf("\nhas 34 or 37");
            }
        }
        if(isOddDigit == true)
        {
            tempSum = ((test % 10) * 2);
            while (tempSum >= 10)
            {
                sum += (tempSum % 10);
                tempSum /= 10;
            }
            sum += tempSum;
            test /= 10;
            isOddDigit = false;
        }
        else
        {
            sum += (test % 10);
            test /= 10;
            isOddDigit = true;
        }
        printf("\ntest value: %ld", test);
        printf("\nsum: %d", sum);
    }
    if (isOddDigit == true)
    {
        sum += (test * 2);
    }
    else 
    {
        sum += test;
    }
    
    printf("%d digits long", digits);
    printf("final sum: %d", sum);
    
    if (test == 4)
    {
        if ((sum % 10) == 0)
        {
            if (digits == 13 || digits == 16)
            {
                isValid = true;
                printf("VISA\n");
            }
            
        }
    }
    if (isAmericanExpress == true)
    {
        if ((sum % 10) == 0)
        {
            if (digits == 15)
            {
                isValid = true;
                printf("\nAMEX");
            }
        }
    }
    if (isMasterCard == true)
    {
        if ((sum % 10) == 0)
        {
            if (digits == 16)
            {
                isValid = true;
                printf("\nMASTERCARD");
            }
        }
    }
    if (isValid == false)
    {
        printf("INVALID\n");
    }
    
    
}