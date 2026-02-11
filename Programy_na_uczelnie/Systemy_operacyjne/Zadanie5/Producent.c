#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if(argc < 5)
    {
        printf("Błąd: Podano zbyt małą liczbę argumentów.\n");
    }

    /*
    argv[0] plik
    argv[1] Dane1.txt
    argv[3] liczba losowa
    argv[4] rozmiar bufora
    */

    int PlikWejsciowy = open(argv[2], O_RDONLY);
    int fifo_fd = open(argv[1], O_WRONLY);

    int buf_size = atoi(argv[4]);
    char buf[buf_size];
    int n;

    while ((n = read(PlikWejsciowy, buf, buf_size)) > 0)
    {
        write(fifo_fd, buf, n);
        const char *msg = "Producent dodał dane do bufora.\n";
        write(1, msg, strlen(msg));
        sleep(atoi(argv[3]));
    }

    close(PlikWejsciowy);
    close(fifo_fd);
    return 0;
}
