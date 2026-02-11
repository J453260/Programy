#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void wypisz_info(const char *typ)
{
    printf("[%s] PID: %d, PPID: %d, PGID: %d\n", typ, getpid(), getppid(), getpgrp());
}

int main()
{
    FILE *plik = fopen("Wyniki.txt", "w");
    if (plik == NULL)
    {
        perror("Blad otwierania pliku");
        return 1;
    }
    printf("Proces macierzysty (PID: %d) startuje\n", getpid());

    for (int i = 0; i < 3; i++)
    {
        pid_t pid = fork();

        if (pid < 0)
        {
            perror("Błąd fork()");
            return 1;
        }

        if (pid == 0)
        {
            // Proces potomny śpi proporcjonalnie do generacji
            sleep(i + 1);
            fprintf(plik, "[Potomny] PID: %d, PPID: %d, PGID: %d\n", getpid(), getppid(), getpgrp());
            exit(0);
        }
    }

    // Proces macierzysty czeka najdłużej, aby zakończyć się jako ostatni
    sleep(4);
    wypisz_info("Macierzysty - koniec");
    fclose(plik);
    return 0;
}
