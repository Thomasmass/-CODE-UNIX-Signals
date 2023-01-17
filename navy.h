/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** navy
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stddef.h>
#include <ucontext.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>

// ce type def est pour le signal handler
typedef void (*sighandler_t)(int);


// cette structure est une structure en global qui nous servira tout le long de l'activité
typedef struct player_s
{
    int pid_j2;
    int connected;
} player_t;

static player_t player;

// va chercher ton getnbr et met le dans utility.c
int my_getnbr(char const *str);

// function dans connection.c qui va nous permettre de récupérer le pid du joueur 2
pid_t get_j2_pid(void);

void sig_handler(int signal, siginfo_t *siginfo, \
__attribute__((unused))void *context);
