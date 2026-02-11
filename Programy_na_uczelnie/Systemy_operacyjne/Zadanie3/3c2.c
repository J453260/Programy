#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

void ignoruj_sygnal(int sig)
{
    printf("Proces %d ignoruje sygnał %d (%s)\n", getpid(), sig, strsignal(sig));
}

int main()
{
    signal(SIGINT, ignoruj_sygnal);

    char arg1[10], arg2[10];
    for(int i=1; i<=3; i++)
    {
        pid_t pid = fork();

        switch(pid)
        {
        case -1:
            perror("Błąd fork()");
            exit(0);

        case 0:
            sprintf(arg1, "%d", 2);  // konwertuje liczbę 2 na string
            sprintf(arg2, "%d", i);  // konwertuje zmienną i na string
            execlp("./3a", "3a", arg1, arg2, (char *)NULL); //i dla różnych opcji
            perror("Błąd execlp");
            exit(1);
        }
    }

    int status;
    for (int i = 1; i <= 3; i++)
    {
        pid_t pid = wait(&status);
        if (WIFSIGNALED(status))
        {
            printf("Proces %d zakończony przez sygnał %d\n", pid, WTERMSIG(status));
        }
        else
        {
            printf("Proces %d zakończony normalnie.\n", pid);
        }
    }
    return 0;
}
