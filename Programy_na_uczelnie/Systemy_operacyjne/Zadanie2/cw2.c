#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        perror("Niepoprawna ilość argumentow. Wpisz nazwę programu, który ma zostać dodatkowo uruchomiony.\n");
        exit(1);
    }

    for (int i = 0; i < 3; i++)
    {
        switch (fork())
        {
        case -1:
            perror("Błąd fork");
            exit(1);

        case 0:
            // Proces potomny
            printf("Proces potomny (PID: %d) wykona program wypisujacy ID procesow.\n", getpid());
            execlp(argv[1], argv[1], (char *)NULL);
            perror("Błąd execlp"); // To się wykona tylko, jeśli execlp się nie powiedzie
            exit(2);

        default:
            // Proces macierzysty
            printf("Proces macierzysty (PID: %d) czeka na zakończenie procesu potomnego\n", getpid());
            int status;
            pid_t pid = wait(&status);

            if (WIFSIGNALED(status))
            {
                printf("Proces potomny (PID: %d) zakończył się sygnałem: %d\n", pid, WTERMSIG(status));
            }
            else
            {
                printf("Proces potomny (PID: %d) zakończył się w sposób inny niż przez sygnał.\n", pid);
            }
        }
    }
    return 0;
}
