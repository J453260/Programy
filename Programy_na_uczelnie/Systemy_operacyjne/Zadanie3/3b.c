#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

void SignalInfo(int status)
{
    if (WIFSIGNALED(status))
    {
        int sig_num = WTERMSIG(status);
        const char *sig_name = strsignal(sig_num);
        printf("Proces zakończony przez sygnał %d: %s\n", sig_num, sig_name);
    }
}

int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        printf("Wprowadzono zbyt mala liczbe argumentow.\n");
        exit(1);
    }
    pid_t pid = fork();
    switch (pid)
    {
    case -1:
        perror("Błąd fork");
        exit(1);

    case 0:
        // Proces potomny
        printf("Proces potomny (PID: %d) uruchomi program %s.\n", getpid(), argv[1]);
        execlp(argv[1], argv[1], argv[2], argv[3], (char *)NULL);
        perror("Błąd execlp"); // To się wykona tylko, jeśli execlp się nie powiedzie
        exit(2);

    default:
        // Proces macierzysty
        printf("Proces macierzysty (PID: %d) uruchomił proces potomny %d.\n", getpid(), pid);

        sleep(2);

        if(kill(pid, 0) == 0)
        {
            printf("Proces potomny o PID: %d istnieje.\n", pid);
            if (kill(pid, SIGKILL) == 0)
            {
                printf("Wysłano sygnał SIGKILL do procesu potomnego (PID: %d)\n", pid);
            }
            else
            {
                perror("Błąd kill");
            }
        }
        else
        {
            printf("Proces potomny o PID: %d nie istnieje.", pid);
        }

        int status;
        wait(&status);
        SignalInfo(status);
        printf("Proces macierzysty kończy działanie.\n");
    }
    return 0;
}
