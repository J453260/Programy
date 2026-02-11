#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        printf("Błąd: Podano zbyt małą liczbę argumentów.\n");
        exit(1);
    }

    /*
    argv[0] - plik
    argv[1] - FIFO_NAME
    argv[2] - Dane1.txt
    argv[3] - losowa liczba 2
    argv[4] - rozmiar bufora
    */

    int PlikWyjsciowy = open(argv[2], O_WRONLY, 0644);
    int fifo_fd = open(argv[1], O_RDONLY);
    if (PlikWyjsciowy == -1 || fifo_fd == -1)
    {
        perror("Błąd otwarcia pliku/FIFO");
        exit(1);
    }

    int buf_size = atoi(argv[4]);
    char buf[buf_size];
    int n;

    while ((n = read(fifo_fd, buf, buf_size)) > 0)
    {
        write(PlikWyjsciowy, buf, n);
        const char *msg = "Konsument odebrał: ";
        write(1, msg, strlen(msg));
        write(1, buf, n);
        write(1, "\n", 1);
        sleep(atoi(argv[4]));
    }

    close(PlikWyjsciowy);
    close(fifo_fd);
    return 0;
}
