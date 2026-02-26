#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool anagram_check(char *Word1, char *Word2)
{
    char *ptrStr = Word1;
    int Tab[256] = {0};

    if (strlen(Word1) == strlen(Word2))
    {
        while (*ptrStr)
        {
            Tab[*ptrStr]++;
            ptrStr++;
        }

        ptrStr = Word2;
        while (*ptrStr)
        {
            Tab[*ptrStr]--;
            ptrStr++;
        }

        for (int i = 0; i < 256; i++)
        {
            if (Tab[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main()
{
    //Проверка условия длины
//    char W1[1000] = "123";
//    char W2[1000] = "3214";
    //Вывод: Words are not anagram!

    //Проверка подходящих слов
//    char W1[1000] = "dxdwd";
//    char W2[1000] = "xwddd";
    //Вывод: Words are anagram!

//    //Проверка при W1 и W2 = "";
    char W1[1000] = "";
    char W2[1000] = "";
//   Вывод: Words are anagram!

    bool flag = anagram_check(W1, W2);

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
