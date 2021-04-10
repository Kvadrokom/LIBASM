# ifndef LIBASM_H
#define LIBASM_H

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int		ft_strlen(char *str);

int     ft_write(int fd, void *buf, int count);

int     ft_read(int fd, char *buf, size_t count);

char    *ft_strcpy(char *destptr, const char *srcptr);

int     ft_strcmp(const char *string1, const char *string2);

char    *ft_strdup(const char *str);

#endif