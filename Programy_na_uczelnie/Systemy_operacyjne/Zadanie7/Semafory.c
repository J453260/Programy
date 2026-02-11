#include "semafory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int sema_open_create(const char* name, int oflag, mode_t mode, unsigned int value, sem_t** sem_out)
{
    sem_t* sem = sem_open(name, oflag, mode, value);
    if (sem == SEM_FAILED)
    {
        perror("sem_open (create)");
        return 0;
    }
    *sem_out = sem;
    return 1;
}

int sema_open_existing(const char* name, sem_t** sem_out)
{
    sem_t* sem = sem_open(name, 0);
    if (sem == SEM_FAILED)
    {
        perror("sem_open (existing)");
        return 0;
    }
    *sem_out = sem;
    return 1;
}

int sema_wait(sem_t* sem)
{
    if (sem_wait(sem) == -1)
    {
        perror("sem_wait");
        return 0;
    }
    return 1;
}

int sema_post(sem_t* sem)
{
    if (sem_post(sem) == -1)
    {
        perror("sem_post");
        return 0;
    }
    return 1;
}

int sema_close(sem_t* sem)
{
    if (sem_close(sem) == -1)
    {
        perror("sem_close");
        return 0;
    }
    return 1;
}

int sema_unlink(const char* name)
{
    if (sem_unlink(name) == -1)
    {
        perror("sem_unlink");
        return 0;
    }
    return 1;
}
