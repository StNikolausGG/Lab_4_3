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
            Tab[(unsigned char)*ptrStr] = true;
            flag = true;
            ptrStr++;
        }

        if (!flag) return 1;

        char *newStr = Word1;
        ptrStr = Word1;

        while (*ptrStr)
        {
            if (!Tab[(unsigned char)*ptrStr])
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
    //Проверка базового функционала
    char S1[1000] = "acdhgkb";
    char S2[1000] = "abd";
    //Вывод: Compressed S1: chgk

    //Передача нулевого адреса
    //char S1[1000] = "test";
    //char *S2 = NULL;
    //Вывод: Received null address!

    //Пустая строка фильтра S2
    //char S1[1000] = "hello";
    //char S2[1000] = "";
    //Вывод: S2 is empty, no compression. S1: hello

    //Полное удаление всех символов
    //char S1[1000] = "abc";
    //char S2[1000] = "abc";
    //Вывод: Compressed S1:

    //Нет совпадений
    //char S1[1000] = "xyz";
    //char S2[1000] = "abc";
    //Вывод: Compressed S1: xyz

    //Кириллица
//    char S1[1000] = "йок";
//    char S2[1000] = "кой";
    //Вывод: Compressed S1:

    //Кириллица + латиница
//    char S1[1000] = "abcйокef";
//    char S2[1000] = "aкойe";
    //Вывод: Compressed S1:

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
        printf("Received null address!\n");
    }

    return 0;
}
