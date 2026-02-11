//deklaracje funkcji

#ifndef MQHELPER_H
#define MQHELPER_H

#include <mqueue.h>
#include <stdbool.h>

#define DEFAULT_MQ_MAXMSG 10
#define DEFAULT_MQ_MSGSIZE 256
#define SERVER_QUEUE_NAME "/server_queue"

extern struct mq_attr default_attr;

int CreateQueue(const char *name, struct mq_attr *attr, mqd_t *qd);
int OpenQueue(const char *name, int flags, mqd_t *qd);
int CloseQueue(mqd_t qd);
int RemoveQueue(const char *name);
int SendMessage(mqd_t qd, const char *msg);
ssize_t ReceiveMessage(mqd_t qd, char *buffer, size_t size);

#define CheckError(cond, msg) \
    do { if (cond) { perror(msg); exit(EXIT_FAILURE); } } while (0)

#endif
