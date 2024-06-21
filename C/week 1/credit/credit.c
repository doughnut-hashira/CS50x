#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int i;
int a = 0;
long k;
int q[20];

void digit(int p, long c);

int main(void)
{
    long credit = get_long("Number: ");
    for (i = 20; i > 0; i--)
    {
        int c = ((credit % (long) pow(10, i)) - (credit % (long) pow(10, i - 1))) /
                (long) pow(10, i - 1);
        if (c != 0)
        {
            k = i;
            i = -777;
        }
    }
    digit(k, credit);

    if (a % 10 == 0)
    {
        if (q[k] == 4 && (k == 13 || k == 16))
        {
            printf("VISA\n");
        }
        else if (q[k] == 5 &&
                 (q[k - 1] == 1 || q[k - 1] == 2 || q[k - 1] == 3 || q[k - 1] == 4 ||
                  q[k - 1] == 5) &&
                 k == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (q[k] == 3 && (q[k - 1] == 4 || q[k - 1] == 7) && k == 15)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

void digit(int p, long c)
{
    for (int z = 1; z <= p; z++)
    {
        q[z] = ((c % (long) pow(10, z)) - (c % (long) pow(10, z - 1))) / (long) pow(10, z - 1);
        if (z % 2 == 0)
        {
            if (2 * q[z] >= 10)
            {
                a += ((2 * q[z] % 100 - (2 * q[z]) % 10) / 10) + ((2 * q[z]) % 10);
            }
            else
            {
                a += 2 * q[z];
            }
        }
        else
        {
            a += q[z];
        }
    }
}
