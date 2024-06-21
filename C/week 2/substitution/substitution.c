#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int cheaks(int m, string key1[]);
int cipher[26];

int main(int p, string key[])
{
    // cheaks for the key
    if (cheaks(p, key))
    {
        return 1;
    }
    // crate the ciphercode
    int no = strlen(key[1]);
    for (int i = 0; i < no; i++)
    {
        if (key[1][i] >= 'A' && key[1][i] <= 'Z')
        {
            cipher[i] = (int) key[1][i] - (65 + i);
        }
        else if (key[1][i] >= 'a' && key[1][i] <= 'z')
        {
            cipher[i] = (int) key[1][i] - (97 + i);
        }
    }
    // take planetext and creat ciphertext
    string pt = get_string("plaintext: ");
    if (pt == NULL)
    {
        return 1;
    }
    int len = strlen(pt);
    char ct[len];
    for (int x = 0; x < len; x++)
    {
        for (int y = 0; y < 26; y++)
        {
            if (y == pt[x] - 65)
            {
                ct[x] = pt[x] + cipher[y];
            }
            else if (y == pt[x] - 97)
            {
                ct[x] = pt[x] + cipher[y];
            }
            if (!isalpha(pt[x]))
            {
                ct[x] = pt[x];
            }
        }
    }
    printf("ciphertext:");
    for (int position = 0; position < len; position++)
    {
        printf("%c", ct[position]);
    }
    printf("\n");
}

int cheaks(int m, string key1[])
{
    if (m == 1)
    {
        return 1;
    }
    int n = strlen(key1[1]);
    for (int a = 0; a < n; a++)
    {
        if (!isalpha(key1[1][a]))
        {
            printf("./substitution Key\n");
            return 1;
        }
    }
    if (n != 26 && m == 1)
    {
        printf("Key must contain 26 letters\n");
        return 1;
    }
    if ((n != 26 && m != 1) || (n == 26 && m > 2))
    {
        printf("./substitution Key\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (key1[1][i] == key1[1][j] || key1[1][i] - key1[1][j] == 32 ||
                key1[1][i] - key1[1][j] == -32)
            {
                return 1;
            }
        }
    }
    return 0;
}
