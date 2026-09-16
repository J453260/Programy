#include <stdio.h>

int next_p(char *a, int n)
{
    int i = n - 2, j = n - 1;
    while (i >= 0 && a[i] >= a[i + 1]) i--;
    if (i < 0) return 0;
    while (a[j] <= a[i]) j--;

    char t = a[i];
    a[i] = a[j];
    a[j] = t;

    for (i++, j = n - 1; i < j; i++, j--)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    return 1;
}

int main()
{
    int t, k;
    if (scanf("%d", &t) != 1) return 0;
    while (t--)
    {
        if (scanf("%d", &k) != 1) continue;
        char s[27];
        for (int i = 0; i < k; i++) s[i] = 'a' + i;
        s[k] = '\0';

        do
        {
            puts(s);
        }
        while (next_p(s, k));
    }
    return 0;
}
