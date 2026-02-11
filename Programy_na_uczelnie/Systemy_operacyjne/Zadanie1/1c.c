#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void wypisz_id(const char *typ)
{
    printf("[%s] PID: %d, PPID: %d\n", typ, getpid(), getppid());
    fflush(stdout);
}

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Błąd fork()");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)    // Proces potomny
    {
        sleep(2);  // Opóźnienie, aby dać czas na zakończenie macierzystego
        wypisz_id("Osierocony potomny");
        exit(0);
    }
    else      // Proces macierzysty
    {
        wypisz_id("Macierzysty");
        exit(0);  // Natychmiast kończymy macierzysty proces
    }

    return 0;
}
