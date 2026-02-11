#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void wypisz_info(const char *typ)
{
    printf("[%s] PID: %d, PPID: %d, PGID: %d\n", typ, getpid(), getppid(), getpgrp());
    fflush(stdout);
}

int main()
{
    printf("Proces macierzysty: PID=%d, PGID=%d\n", getpid(), getpgrp());
    fflush(stdout);
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
            sleep(1);
            if (setpgid(0, 0) == -1)
            {
                perror("Blad setpgid()");
                exit(1);
            }  // Ustawia PGID równy PID (staje się liderem własnej grupy)
            printf("Proces potomny: PID=%d, PPID=%d, PGID=%d\n", getpid(), getppid(), getpgrp());
            exit(0);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        wait(NULL);
    }

    printf("Proces macierzysty (po zmianie grupy potomnego): PID=%d, PGID=%d\n", getpid(), getpgrp());
    fflush(stdout);
    return 0;
}
