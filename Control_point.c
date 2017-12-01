#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check(const char *s)
{
    int i = 0;
    while (s[i+1] != '\0')
    {
        i+=1;
    }
    int l = i;
    if ( (s[i] < 'A') && (s[i] > 'Z'))
        {
            return 0;
        }
    for (i = 0; i < l; i++)
    {
        if (s[i] == s[l])
        {
            return 0;
        }
    }
    return 1;
}

void rule1(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if ( (s[i] >= 'A') && (s[i] < 'Z'))
        {
            s[i]++;
        }
        if (s[i] == 'Z')
        {
            s[i] = 'A';
        }
        i += 1;
    }

}
int main()
{
    char mas[101] = {'\0'};
    scanf("%s", &mas);
    printf("%s\n", mas);
    printf("%d\n", check(mas));
    if (check(mas) == 1)
    {
        rule1(mas);
    }
    printf("itog %s\n", mas);
    return 0;
}
