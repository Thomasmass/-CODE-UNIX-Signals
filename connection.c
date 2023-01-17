/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** connection
*/

#include "navy.h"

void sig_handler(int signal, siginfo_t *siginfo, \
__attribute__((unused))void *context)
{
    pid_t sender_pid = siginfo->si_pid;
    player.pid_j2 = sender_pid;
    kill(sender_pid, signal);
    signal++;
}

pid_t get_j2_pid(void)
{
    struct sigaction act;

    act.sa_sigaction = &sig_handler;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);

    sigaction(SIGUSR1, &act, NULL);
    while (player.pid_j2 == 0);
    printf("enemy connected\n\n");
    return (player.pid_j2);
}
