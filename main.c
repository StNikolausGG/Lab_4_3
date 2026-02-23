#include <stdio.h>
#include <string.h>

int main()
{
    char W1[1000] = "комар";
    char W2[1000] = "корма";

    int Tab1[256] = {0};
    int Tab2[256] = {0};
    if (strlen(W1) == strlen(W2))
    {
        while (*W1)
        {
            Tab1[*W1]++;
        }
        while (*W2)
        {
            Tab2[*W2]++;
        }

    }
    else
    {
        printf("Words are not anagram!");
    }
    return 0;
}
