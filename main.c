#include <stdio.h>
#include <stdbool.h>

int ddfind(char *str, int *mas)
{
    if (str)
    {
        char *ptrStr = str;
        char *startStr = str;
        int cnt = 0;
        int ind = 0;
        int *index = &ind;
        bool flag = true;

        while (*ptrStr && flag)
        {
            if (*ptrStr == 'd')
            {
                cnt++;
            }
            if (*ptrStr == ',' || *ptrStr == '.')
            {
                int length = ptrStr - startStr;
                if (cnt == 2)
                {
                    *mas = *index;
                    mas++;
                    *mas = length;
                    mas++;
                }
                startStr = ptrStr + 1;
                *index += length + 1;
                cnt = 0;
                if (*ptrStr == '.') flag = false;
            }
            ptrStr++;
        }
        if (cnt == 2)
        {
            int length = ptrStr - startStr;
            *mas = *index;
            mas++;
            *mas = length;
            mas++;
        }
        return 0;
    }
    return 1;
}

int main()
{
    char S[1000] = "Hello,worldd!,hello worldd.";
    //char S[1000] = "dont , drozd, triddd.";
//    char S[1000] = "cyr test and special symb: @@абдзфщалdфлоп.";
//    char *S = NULL;
    //char S[1000] = "hello, sir! I have not roots.";
    int mas[1000] = {-1};
    printf("Initial str: %s\n", S);
    int rez = ddfind(S, mas);
    if (!rez)
    {
        printf("Words with double d: ");
        int i = 0;
        while (mas[i] != 0 || mas[i+1] != 0)
        {
            for (int k = mas[i]; k < mas[i] + mas[i+1]; k++)
            {
                printf("%c", S[k]);
            }
            printf(" ");
            i += 2;
        }
    }
    else
    {
        printf("Received null address!");
    }

    return 0;
}
