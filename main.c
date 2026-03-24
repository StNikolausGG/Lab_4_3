#include <stdio.h>
#include <stdbool.h>

int ddfind(char *str, int *mas, int len)
{
    if (str)
    {
        char *ptrStr = str;
        char *startStr = str;
        int cnt = 0;
        int para = 0;
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
                if (cnt == 2 && 2 + para * 2 <= len)
                {
                    *mas = *index;
                    mas++;
                    *mas = length;
                    mas++;
                    para++;
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
//    char S[1000] = "Hello,worldd!,hello worldd.";
    //char S[1000] = "dont , drozd, triddd.";
//    char S[1000] = "cyr test and special symb: @@абдзфщалdфлоп.";
//    char *S = NULL;
    //char S[1000] = "hello, sir! I have not roots.";
    //char S[1000] = "hi, hello and world";
    char S[1000] = "dausdygf. dddaaa";
    int mas[1000] = {-1};
    int len = sizeof (mas)/sizeof (mas[0]);
    printf("Initial str: %s\n", S);
    int rez = ddfind(S, mas, len);
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
