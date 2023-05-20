#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countVowels(char str[])
{
    int count = 0;
    char ch;

    for (int i = 0; i < strlen(str); i++)
    {
        ch = tolower(str[i]);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            count++;
        }
    }

    return count;
}
int main()
{
    char ch[20];
    printf("Enter a String to count number of vowlels : ");
    scanf("%s", ch);

    int result = countVowels(ch);

    printf("Total vowels in %s is : %d \n", ch, result);
}