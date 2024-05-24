/*
** EPITECH PROJECT, 2023
** cat()
** File description:
** Dose the same thing as CAT in the shell
*/

#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../include/my.h"

void read_single(void)
{
    const int MAX_SIZE = 30000;
    char *string;
    int file = open(string, O_RDONLY);
    char buffer[MAX_SIZE];

    for (int bytes_to_read = read(0, buffer, MAX_SIZE);
    bytes_to_read > 0;
    bytes_to_read = read(0, buffer, MAX_SIZE)) {
        my_putstr(buffer);
        buffer[0] = '\0';
    }
}

int display_error(char *file, int errnumber)
{
    my_putstr(file);
    switch (errnumber) {
        case 2:
            my_putstr("no such file or directory");
            break;
        case 21:
            my_putstr("is a directory");
            break;
        default:
            my_putstr("error not known");
            break;
    }
    return errnumber;
}

int check_error(char **argv, int index, int errnumber, int *quit)
{
    if (errnumber != 0) {
        *quit = 1;
        return display_error(argv[index], errnumber);
    }
}

int read_files(int argc, char **argv)
{
    const int MAX_SIZE = 30000;
    int file;
    char buffer[MAX_SIZE];
    int quit = 0;
    int rd;

    for (int i = 1; i < argc || quit != 1; i++) {
        file = open(argv[i], O_RDONLY);
        buffer[MAX_SIZE];
        check_error(argv, i, errno, &quit);
        for (rd = read(file, buffer, 1); rd > 0; rd = read(file, buffer, 1)) {
            check_error(argv, i, errno, &quit);
            my_putstr(buffer);
        }
        rd = 0;
        check_error(argv, i, errno, &quit);
        my_putstr(buffer);
        close(file);
        check_error(argv, i, errno, &quit);
    }
}

int main(int argc, char **argv)
{
    if (argc <= 1)
        read_single();
    else
        read_files(argc, argv);
    return 0;
}
