#include <stdio.h>
#include <stdbool.h>

int ddfind(char *str, int *mas)
{
    if (str && mas)
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
        return 0;
    }
    return 1;
}

int main()
{
    char S[1000] = "hello,broddther,dd,  ,is,dgood.";
    int mas[1000] = {-1};
    int rez = ddfind(S, mas);
    int i = 0;
    while (mas[i] != 0)
    {
        for (int k = mas[i]; k < mas[i] + mas[i+1]; k++)
        {
            printf("%c", S[k]);
        }
        printf(" ");
        i += 2;
    }


    return 0;
}
