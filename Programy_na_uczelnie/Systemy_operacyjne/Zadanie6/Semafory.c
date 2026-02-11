#include "Semafory.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // O_CREAT, O_EXCL
#include <sys/stat.h>   // mode_t
#include <semaphore.h>
#include <errno.h>
#include <string.h>

#define CheckError(expr, msg) \
    if ((expr) == -1) { \
        perror(msg); \
        exit(EXIT_FAILURE); \
    }

sem_t* sema_open(const char* name, int oflag, mode_t mode, unsigned int value)
{
    sem_t* sem = sem_open(name, oflag, mode, value);
    if (sem == SEM_FAILED)
    {
        fprintf(stderr, "sem_open (create) failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return sem;
}

sem_t* sema_open_existing(const char* name)
{
    sem_t* sem = sem_open(name, 0);
    if (sem == SEM_FAILED)
    {
        fprintf(stderr, "sem_open (existing) failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return sem;
}

void sema_wait(sem_t* sem)
{
    CheckError(sem_wait(sem), "sem_wait");
}

void sema_post(sem_t* sem)
{
    CheckError(sem_post(sem), "sem_post");
}

void sema_close(sem_t* sem)
{
    CheckError(sem_close(sem), "sem_close");
}

void sema_unlink(const char* name)
{
    CheckError(sem_unlink(name), "sem_unlink");
}
