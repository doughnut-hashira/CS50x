// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 200;

// Hash table
node *table[N];

unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int Hash = hash(word);
    for (node *ptr = table[Hash]; ptr != NULL; ptr = ptr->next)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long hash_value = 0;
    int c;
    int length = 0;

    // Calculate the sum of ASCII values of the characters and track the length of the word
    while ((c = *word++))
    {
        hash_value += toupper(c);
        length++;
    }

    // Combine the length of the word with the hash value
    hash_value += length;

    // Apply modulus to fit the hash value within a specific range
    return hash_value % 200;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *words = fopen(dictionary, "r");
    if (words == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];

    while (fscanf(words, "%s", word) != EOF)
    {
        node *new_word = malloc(sizeof(node));
        if (new_word == NULL)
        {
            return false;
        }

        strcpy(new_word->word, word);
        new_word->next = NULL;
        unsigned int Hash = hash(word);

        if (table[Hash] == NULL)
        {
            table[Hash] = new_word;
        }
        else
        {
            for (node *ptr = table[Hash]; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = new_word;
                    break;
                }
            }
        }
        word_count++;
    }
    fclose(words);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        while (ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }
    }
    return true;
}
