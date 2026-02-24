#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char W1[1000] = "dxdwd";
    char W2[1000] = "xwddd";
    char *ptrStr = W1;
    bool flag = true;

    int Tab1[256] = {0};
    int Tab2[256] = {0};

    if (strlen(W1) == strlen(W2))
    {
        while (*ptrStr)
        {
            Tab1[*ptrStr]++;
            ptrStr++;
        }

        ptrStr = W2;
        while (*ptrStr)
        {
            Tab2[*ptrStr]++;
            ptrStr++;
        }

        for (int i = 0; i < 256; i++)
        {
            if (Tab1[i] != Tab2[i])
            {
                flag = false;
            }
        }
    }

    else
    {
        flag = false;
    }

    if (flag)
    {
        printf("Words are anagram!\n");
    }

    else
    {
        printf("Words are not anagram!\n");
    }

    return 0;
}
