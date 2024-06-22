#include <iostream>
#include <cmath>

#define MAX 16

int _key(int len, int *key, int *digits);
int identify(int len, int *digits);

using std::cout;

int main(void)
{
    long credit;
    int key;
    int digits[MAX];
    int roll = 0;

    cout << "Number: ";
    std::cin >> credit;

    int len = ceil(log(credit)/log(10));
    if (len > MAX)
    {
        cout << "INVALID" << "\n";
        return 1;
    }

    long temp = credit;

    while(temp > 0)
    {
        digits[roll] = temp % 10;
        temp /= 10;
        roll++;
    }

    key = _key(len, &key, digits);
    if (key % 10 == 0)
    {
        if(identify(len, digits))
        {
            return 3;
        }
    }
    else
    {
        printf("INVALID\n");
        return 2;
    }
    return 0;
}

int _key(int len, int *key, int *digits)
{
    for (int i = 0; i < len; i++)
    {
        if (i % 2)
        {
            if (digits[i] > 4)
            {
                *key += ((2 * digits[i] % 100 - (2 * digits[i]) % 10) / 10) +
                        ((2 * digits[i]) % 10);
            }
            else
            {
                *key += 2 * digits[i];
            }
        }
        else
        {
            *key += digits[i];
        }
    }
    return *key;
}

int identify(int len, int *digits)
{

    if ((len == 13 || len == 16) && digits[len - 1] == 4)
    {
        printf("VISA\n");
    }
    else if (len == 16 && digits[15] == 5 &&
             (digits[14] == 1 || digits[14] == 2 || digits[14] == 3 || digits[14] == 4 ||
              digits[14] == 5))
    {
        printf("MASTERCARD\n");
    }
    else if (len == 15 && digits[14] == 3 && (digits[13] == 4 || digits[13] == 7))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
        return 3;
    }
    return 0;
}
