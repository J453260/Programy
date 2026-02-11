#ifndef SEMAFORY_H
#define SEMAFORY_H

#include <semaphore.h>
#include <sys/stat.h>

int sema_open_create(const char* name, int oflag, mode_t mode, unsigned int value, sem_t** sem_out);
int sema_open_existing(const char* name, sem_t** sem_out);
int sema_wait(sem_t* sem);
int sema_post(sem_t* sem);
int sema_close(sem_t* sem);
int sema_unlink(const char* name);

#endif
