#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void wypisz_id(const char *typ)
{
    printf("[%s] PID: %d, PPID: %d, UID: %d, GID: %d, PGID: %d\n", typ, getpid(), getppid(), getuid(), getgid(), getpgrp());
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        pid_t pid = fork();

        if (pid < 0) // Sprawdzenie błędu fork()
        {
            perror("Błąd fork()");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) // Kod wykonywany przez proces potomny
        {
            wypisz_id("Potomny");
            exit(i + 1); // Każdy potomek zwraca inny kod zakończenia
        }
    }

    // Proces macierzysty czeka na wszystkie potomki i sprawdza ich status
    for (int i = 0; i < 3; i++)
    {
        int status;
        pid_t finished_pid = wait(&status);

        if (WIFEXITED(status)) // Sprawdzenie, czy potomek zakończył się normalnie
        {
            printf("Proces potomny (PID = %d) zakończył się poprawnie, kod: %d\n",
                   finished_pid, WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status)) // Sprawdzenie, czy proces został zakończony sygnałem
        {
            printf("Proces potomny (PID = %d) został zakończony sygnałem: %d\n", finished_pid, WTERMSIG(status));
        }
    }

    // Proces macierzysty wypisuje swoje identyfikatory
    wypisz_id("Macierzysty");

    return 0;
}
