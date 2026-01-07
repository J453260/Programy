#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int WypiszTekst(FILE *wp, char tekst[])
{
    int Znaki=strlen(tekst);
    fputs(tekst, wp);
    fprintf(wp, "%d\n", Znaki);
    return Znaki;
}

int CzytajTekst(FILE *wp, char tekst2[], int max)
{
    int dlugosc = 0;
    char c;
    int licznik=0;
    while ((c = fgetc(wp)) != EOF && dlugosc < max)
    {
        tekst2[dlugosc] = c;
        dlugosc++;
        licznik++;
    }
    tekst2[dlugosc] = '\0';
    return licznik;
}

int KopiujTekst(char skad[], char dokad[], int max)
{
    int licznik = 0;
    int i = 0;

    for (i = 0; i < max && skad[i] != '\0'; i++)
    {
        dokad[i] = skad[i];
        licznik++;
    }

    dokad[i] = '\0';
    return licznik;
}

int WszystkieZnaki(char tekst[])
{
    int Znaki=0;
    int i=0;
    do
    {
        Znaki++;
        i++;
    }
    while(tekst[i]!='\0');

    if(tekst[i-1]=='\n')
    {
        Znaki-=1;
    }
    return Znaki;
}

int CzarneZnaki(char tekst[])
{
    int licznik=0;
    for(int i=0; tekst[i] != '\0'; i++)
    {
        if(tekst[i] != ' ' && tekst[i] != '\t' && tekst[i] != '\n')
        {
            licznik++;
        }
    }
    return licznik;
}

int Linie(char tekst[])
{
    int Licznik=0;
    for(int i=0; tekst[i] != '\0'; i++)
    {
        if(tekst[i]=='\n')
        {
            Licznik++;
        }
    }

    if((tekst[strlen(tekst) - 1])!='\n')
    {
        Licznik+=1;
    }
    return Licznik;
}

int Slowa(char tekst[])
{
    int licznik=0, Wsl=0;
    for(int i=0; tekst[i] != '\0'; i++)
    {
        if(tekst[i]==' ')
        {
            Wsl=0;
        }
        else
        {
            // Jeśli napotkamy znak, który nie jest spacją, sprawdzamy, czy to początek nowego słowa
            if (!Wsl)
            {
                licznik++; // Nowe słowo
                Wsl = 1;  // Ustawiamy flagę, że jesteśmy w słowie
            }
        }
    }


    return licznik;
}

int main()
{
    char tekst[] = "przykladowy tekst\n"; //tekst do CzytajTekst
    FILE *wp;
    FILE *dane2 = fopen("dane2.txt", "r");
    FILE *wyj = fopen("wyjscie.txt", "w");
    wp=fopen("dane.txt", "w");
    if (wp == NULL)
    {
        perror("Blad otwarcia pliku");
        exit(EXIT_FAILURE);
    }

    if (dane2 == NULL)
    {
        perror("Blad otwarcia pliku");
        exit(EXIT_FAILURE);
    }

    if (wyj == NULL)
    {
        perror("Blad otwarcia pliku");
        exit(EXIT_FAILURE);
    }

    int Znaki;
    Znaki = WypiszTekst(wp, tekst);
    printf("Tekst zostal zapisany do pliku 'dane.txt'.\n");
    printf("Tekst zawiera %d znakow.\n", Znaki);
    fclose(wp);
    int max;
    printf("Ile znakow chcesz wstawic do drugiej tablicy: ");
    scanf("%d", &max);
    char *tekst2 = (char *)malloc((max + 1) * sizeof(char));

    wp=fopen("dane.txt", "r");
    if (wp == NULL)
    {
        perror("Blad otwarcia pliku");
        exit(EXIT_FAILURE);
    }

    char tekst3[10000];
    int Znaki2=CzytajTekst(dane2, tekst3, sizeof(tekst3));

    int zk=CzytajTekst(wp, tekst, max);
    fprintf(wyj, "Do drugiej tablicy zostalo dopisane %d znakow.\n", zk);
    fprintf(wyj, "Wczytano %d znakow\n", Znaki2);
    fprintf(wyj, "Wszystkie znaki: %d\n", WszystkieZnaki(tekst3));
    fprintf(wyj, "Czarne znaki: %d\n", CzarneZnaki(tekst3));
    fprintf(wyj, "Liczba linii: %d\n", Linie(tekst3));
    fprintf(wyj, "Liczba slow: %d\n", Slowa(tekst3));

    fclose(wp);
    fclose(dane2);
    fclose(wyj);

    free(tekst2);
    return 0;
}
