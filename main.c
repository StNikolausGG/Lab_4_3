#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int anagram_check(char *Word1, char *Word2)
{
    if (Word1 && Word2)
    {
        if (strlen(Word1) == strlen(Word2))
        {
            char *ptrStr = Word1;
            int Tab[256] = {0};

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
                    return 1;
                }
            }
            return 0;
        }
        else
        {
            return 1;
        }
    }
    return 2;

}

int main()
{
    //Базовая проверка подходящих слов
//    char W1[1000] = "12345";
//    char W2[1000] = "51423";
    //Вывод: Words are anagram!

    //Базовая проверка подходящих слов с повторяющимися символами
//    char W1[1000] = "aabbcc";
//    char W2[1000] = "abcabc";
    //Вывод: Words are anagram!

    //Проверка условия длины
//    char W1[1000] = "123";
//    char W2[1000] = "3214";
    //Вывод: Words are not anagram!

//    //Проверка при W1 и W2 = "";
//    char W1[1000] = "";
//    char W2[1000] = "";
//   Вывод: Words are anagram!

    //Проверка нулевых адресов
//    char *ptr1 = Null;
//    char *ptr2 = Null;
    //Вывод: Received null address!

    //Проверка нулевого адреса
//    char W1[1000] = "123";
//    char *ptr2 = Null;
    //Вывод: Received null address!

    //Ошибка кириллицы
    char W1[1000] = "о";
    char W2[1000] = "я";
    //Вывод: Words are anagram!

    int flag = anagram_check(W1, W2);

    if (flag == 0)
    {
        printf("Words are anagram!\n");
    }

    else if (flag == 1)
    {
        printf("Words are not anagram!\n");
    }

    else if (flag == 2)
    {
        printf("Received null address!\n");
    }

    return 0;
}
