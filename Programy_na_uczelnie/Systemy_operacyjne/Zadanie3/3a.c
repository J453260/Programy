#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void Obsluga(int sig)
{
    printf("Obsluzylem sygnal SIGINT %d\n", sig);
    sleep(1);
    signal(SIGINT, SIG_DFL);
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Wpisano za malo argumentow.");
        exit(0);
    }
    printf("1) Domyslna operacja\n");
    printf("2) Ignorowanie sygnalu\n");
    printf("3) Przechwycenie i wlasna obsluga sygnalu\n");
    int numer_sygnalu = atoi(argv[1]);

    switch(atoi(argv[2]))
    {
    case 1:
        printf("Uruchomiony. Naciśnij Ctrl + C, aby zakończyć proces (domyślne zachowanie SIGINT).\n");
        pause();
        break;

    case 2:
        signal(numer_sygnalu, SIG_IGN);

        printf("Program uruchomiony. Spróbuj nacisnąć Ctrl + C - nie zakończy działania!\n");
        pause();
        break;

    case 3:
        signal(numer_sygnalu, Obsluga);
        printf("Nacisnij Ctrl + C\n");
        pause();
        break;

    default:
        printf("Niepoprawny argument! Wybierz 1, 2 lub 3.\n");
        exit(1);
    }

    return 0;
}
