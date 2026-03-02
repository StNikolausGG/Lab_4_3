#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int string_compress(char *Word1, char *Word2)
{
    if (Word1 && Word2)
    {
        bool Tab[256] = {false};
        bool flag = false;
        char *ptrStr = Word2;

        while(*ptrStr)
        {
            Tab[*ptrStr] = true;
            flag = true;
            ptrStr++;
        }

        if (!flag) return 1;

        char *newStr = Word1;
        ptrStr = Word1;

        while (*ptrStr)
        {
            if (!Tab[*ptrStr])
            {
                *newStr = *ptrStr;
                newStr++;
            }
            ptrStr++;
        }
        *newStr = '\0';

        return 0;
    }
    return 2;
}


int main()
{
    char S1[1000] = "aabbcdhgkl";
    char S2[1000] = "abd";
    char *test = NULL;

    printf("Uncompressed S1: %s\n", S1);
    printf("S2: %s\n", S2);

    int z = string_compress(S1, S2);

    if (z == 0)
    {
        printf("Compressed S1: %s\n", S1);
    }
    else if (z == 1)
    {
        printf("S2 is empty, no compression. S1: %s\n", S1);
    }
    else
    {
        printf("One of arguments contains null address\n");
    }

    return 0;
}
