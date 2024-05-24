/*
** EPITECH PROJECT, 2024
** endians.c
** File description:
** endians
*/

#include "asm.h"

void write_big_endian_magic(int fd, int value, header_t *header)
{
    unsigned char bytes[4];

    bytes[0] = (value >> 24) & 0xFF;
    bytes[1] = (value >> 16) & 0xFF;
    bytes[2] = (value >> 8) & 0xFF;
    bytes[3] = value & 0xFF;
    write(fd, bytes, sizeof(bytes));
}

void write_big_endian_4bit(int fd, int value, header_t *header)
{
    unsigned char bytes[4];

    bytes[0] = (value >> 24) & 0xFF;
    bytes[1] = (value >> 16) & 0xFF;
    bytes[2] = (value >> 8) & 0xFF;
    bytes[3] = value & 0xFF;
    write(fd, bytes, sizeof(bytes));
    header->prog_size += sizeof(bytes);
}

void write_big_endian_2bit(int fd, int value, header_t *header, int write_prog)
{
    unsigned char bytes[2];

    bytes[0] = (value >> 8) & 0xFF;
    bytes[1] = value & 0xFF;
    write(fd, &bytes, sizeof(bytes));
    if (write_prog == 1)
        header->prog_size += sizeof(bytes);
}
