#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    //argv[0] = ./3c2
    //argv[1] = ./3c2
    if(argc < 2)
    {
        perror("Wprowadzono zbyt mala liczbe argumentow.\n");
        exit(1);
    }
    pid_t pid = fork();
    switch(pid)
    {
    case -1:
        perror("Błąd fork");
        exit(1);

    case 0:
        //proces potomny
        setpgid(0, 0);
        printf("Proces potomny jest liderem swojej grupy procesow PID: %d, PGID: %d\n", getpid(), getpgid(0));
        execlp(argv[1], argv[1], (char *)NULL);
        perror("Błąd execlp");  // Jeśli execlp się nie powiedzie
        exit(1);

    default:
        printf("Proces macierzysty PID: %d\n", getpid());
        sleep(2);
        printf("Wysyłam SIGINT do grupy %d\n", pid);
        kill(-pid, SIGINT);  // Wysyłamy sygnał do całej grupy
        int status;
        pid_t pid2 = wait(&status);
        if (WIFSIGNALED(status))
        {
            int sig_num = WTERMSIG(status);
            printf("Lider grupy %d zakończony przez sygnał %d (%s)\n", pid2, sig_num, strsignal(sig_num));
        }
        else
        {
            printf("Lider grupy %d zakończony normalnie.\n", pid2);
        }
    }

    return 0;
}
