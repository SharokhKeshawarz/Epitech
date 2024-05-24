/*
** EPITECH PROJECT, 2024
** signal
** File description:
** signal
*/

#include "../include/proto.h"

void printing_message(void)
{
    my_putstr("My position :\n");
    my_putstr("enemy position :\n");
}

int main_signal_usr2(int nb_pid)
{
    struct sigaction act;
    int pid_t = getpid();

    kill(nb_pid, SIGUSR2);
    my_printf("My pid is : %d\n", pid_t);
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = my_putstr("Connection etablished.");
    sigaction(SIGUSR2, &act, NULL);
    my_putstr("Successfully connected.\n");
    printing_message();
    my_putstr("Waiting for ennemy's attack...");
    pause();
}

int com_etablished_usr1(int sig, siginfo_t *siginfo, void *context)
{
    int tmp = siginfo->si_pid;

    my_putstr("Connection success.\n\n");
    printing_message();
    my_putstr("Position for missile : ");
    pause();
}

int main_signal_usr1(void)
{
    struct sigaction act;
    int pid_t = getpid();

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = com_etablished_usr1;
    my_printf("My pid is : %d\n", pid_t);
    my_putstr("Connection is running...\n");
    sigaction(SIGUSR2, &act, NULL);
    pause();
}
