#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // dla fork()
#include <sys/types.h>  // dla pid_t

int main()
{
    pid_t pid = getpid();
    pid_t ppid = getppid();
    uid_t uid = getuid();
    gid_t gid = getgid();
    pid_t pgid = getpgrp();

    printf("UID: %d\n", uid);
    printf("GID: %d\n", gid);
    printf("PID: %d\n", pid);
    printf("PPID: %d\n", ppid);
    printf("PGID: %d\n", pgid);

    return 0;
}
