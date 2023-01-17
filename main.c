/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** main
*/

#include "navy.h"   

void handler(__attribute__((unused))int __sig, \
__attribute__((unused)) sighandler_t handler)
{
    player.connected = 1;
}

void init_player(void) {
    player.pid_j2 = 0;
    player.connected = 0;
}

void display_pid(void) {
    printf("my_pid: %d\n", getpid());
}

void player_one(void) {
    display_pid();
    printf("waiting for enemy connection...\n");
    pause();
    player.pid_j2 = get_j2_pid();

    kill(player.pid_j2, SIGUSR2);
}

void player_two(char *pid) {
    display_pid();
    player.pid_j2 = my_getnbr(pid);

    kill(player.pid_j2, SIGUSR1);
    printf("waiting for connection confirmation...\n");
    pause();
    if (player.connected == 1) {
        printf("successfully connected\n\n");
    } else {
        printf("Bad connection\n");
    }

}

int main(int argc, char **argv) {
    struct sigaction act;

    act.sa_sigaction = &sig_handler;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);

    init_player();
    sigaction(SIGUSR1, &act, NULL);

    if (argc == 1) {
        player_one();
    } else if (argc == 2) {
        player_two(argv[1]);
    } else {
        return 84;
    }
}
