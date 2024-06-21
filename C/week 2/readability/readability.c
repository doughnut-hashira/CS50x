#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int indexx(int l, int w, int s);
int nletters(string a, int b);
int sentence(string a, int b);
int word(string a, int b);

int main(void)
{
    string text = get_string("Text : ");
    int length = strlen(text);
    // no of letters
    int letters = nletters(text, length);
    // number of words
    int words = word(text, length);
    // number of sentences
    int sentences = sentence(text, length);
    // use the formula
    int index = indexx(letters, words, sentences);
    // Grades
    printf("%i,%i,%i\n",letters, words, sentences);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int nletters(string a, int b)
{
    int count = 0;
    for (int i = 0; i < b; i++)
    {
        if (isalpha(a[i]))
        {
            count += 1;
        }
    }
    return count;
}

int word(string a, int b)
{
    int count = 1;
    for (int i = 0; i < b; i++)
    {
        if (isspace(a[i]))
        {
            count += 1;
        }
    }
    return count;
}

int sentence(string a, int b)
{
    int count = 0;
    for (int i = 0; i < b; i++)
    {
        if (a[i] == '!' || a[i] == '?' || a[i] == '.')
        {
            count += 1;
        }
    }
    return count;
}

int indexx(int l, int w, int s)
{
    int index = 0;
    int L = ((float) l / w) * 100;
    int S = ((float) s / w) * 100;
    float n = ((0.0588 * L) - (0.296 * S) - 15.8);
    float x = n - (int) n;

    if (x != 0)
    {
        if (x >= 0.55)
        {
            index = n - x + 1;
        }
        else
        {
            index = n;
        }
    }
    else
    {
        index = n;
    }
    return index;
}
