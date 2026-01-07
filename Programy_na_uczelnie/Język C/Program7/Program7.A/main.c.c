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
    while(tekst[i]!='\0')
    {
        Znaki++;
        i++;
    }

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

int main(int argc, int *argv[])
{
    if (argc < 2)
    {
        printf("Uzycie: %s <tekst_domyslny>\n", argv[0]);
        return 1; // Zakończ program z kodem błędu
    }
    char tekst[] = "przykladowy tekst\n"; //tekst do CzytajTekst
    FILE *wp;
    wp=fopen("dane.txt", "w");
    if (wp == NULL)
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

    int zk=CzytajTekst(wp, tekst2, max);
    printf("Do drugiej tablicy zostalo dopisane %d znakow.\n", zk);

    fclose(wp);

    char skad[100];
    while (getchar() != '\n');
    printf("Podaj tekst do skopiowania: ");
    fgets(skad, sizeof(skad), stdin);

    char dokad[100];

    int max2=100;
    int l=KopiujTekst(skad, dokad, max);

    printf("Funkcja kopiujaca przekopiowala %d znakow.\n \n", l);

    char tekst3[1000];
    printf("Podaj tekst do trzeciej tablicy. Jesli chcesz zakonczyc wpisywanie, napisz KONIEC: \n");
    char linia[100];   // Bufor na pojedynczą linię
    while (1)
    {
        fgets(linia, sizeof(linia), stdin);
        if (strcmp(linia, "KONIEC\n") == 0)  // Jeśli użytkownik wpisze 'END', przerywamy pętlę
        {
            break;
        }

        // Sprawdzamy, czy po dodaniu nowej linii nie przekroczymy rozmiaru tekst3
        if (strlen(tekst3) + strlen(linia) >= sizeof(tekst3) - 1)
        {
            printf("Przekroczono maksymalny rozmiar tekstu! Odcinam nadmiar.\n");
            strncat(tekst3, linia, sizeof(tekst3) - strlen(tekst3) - 1);  // Dodanie tylu znaków, ile się zmieści
            break;
        }

        strcat(tekst3, linia);  // Dodanie nowej linii do tablicy tekst3
    }
    int Znaki2=WszystkieZnaki(tekst3);
    printf("Wszystkie znaki w tablicy tekst: %d \n", Znaki2);

    int cz =CzarneZnaki(tekst3);
    printf("Wszystkie czarne znaki w tablicy tekst3: %d \n", cz);

    int ln=Linie(tekst3);
    printf("Liczba linii w tablicy 'tekst': %d \n", ln);

    int sl=Slowa(tekst3);
    printf("Liczba slow w tablicy 'tekst3': %d \n", sl);

    int Z=strlen(tekst);
    fputs(tekst, wp);
    fprintf(wp, "%d\n", Z);

    free(tekst2);
    return 0;
}
