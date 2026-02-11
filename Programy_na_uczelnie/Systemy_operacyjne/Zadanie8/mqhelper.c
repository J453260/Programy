//implementacja funkcji

#include "mqhelper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

struct mq_attr default_attr =
{
    .mq_flags = 0,
    .mq_maxmsg = DEFAULT_MQ_MAXMSG,
    .mq_msgsize = DEFAULT_MQ_MSGSIZE,
    .mq_curmsgs = 0
};

int CreateQueue(const char *name, struct mq_attr *attr, mqd_t *qd)
{
    *qd = mq_open(name, O_CREAT | O_EXCL | O_RDWR, 0644, attr);
    return (*qd == (mqd_t)-1) ? 0 : 1;
}

int OpenQueue(const char *name, int flags, mqd_t *qd)
{
    *qd = mq_open(name, flags);
    return (*qd == (mqd_t)-1) ? 0 : 1;
}

int CloseQueue(mqd_t qd)
{
    return mq_close(qd) == -1 ? 0 : 1;
}

int RemoveQueue(const char *name)
{
    if (mq_unlink(name) == -1 && errno != ENOENT)
        return 0;
    return 1;
}

int SendMessage(mqd_t qd, const char *msg)
{
    return mq_send(qd, msg, strlen(msg) + 1, 0) == -1 ? 0 : 1;
}

ssize_t ReceiveMessage(mqd_t qd, char *buffer, size_t size)
{
    ssize_t bytes = mq_receive(qd, buffer, size, NULL);
    return bytes == -1 ? -1 : bytes;
}
