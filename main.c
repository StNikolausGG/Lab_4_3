#include <stdio.h>
#include <stdbool.h>

int ddfind(char *str, int *index)
{
    if (str)
    {
        char *ptrStr = str;
        int cnt = 0;
        int k = 0;
        bool flag = true;

        while (*ptrStr && flag)
        {
            if (*ptrStr == 'd')
            {
                cnt++;
            }
            if (*ptrStr == ',' || *ptrStr == '.')
            {
                if (cnt == 2)
                {
                    index[k] = k;
                    index[k+1] = ptrStr - str;
                    k += 2;
                }
                str = ptrStr + 1;
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
    char S[1000] = "hello,broddther,dd, That , is,dgood,       d    d      .  ";
    int index[1000] = {-1};
    int rez = ddfind(S, index);

    return 0;
}
