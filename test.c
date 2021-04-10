#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>
void            test_strdup(char *str)
{
    char *str1 = strdup(str);
    char *str2 = ft_strdup(str);
    printf("std: %s \n", str1);
    printf("nasm: %s \n", str2);
    free(str1);
    free(str2);
}
#define BUFSIZE 1000000
void            test_read(void)
{
    size_t std_ln;
    size_t nasm_ln;
    int fd;
    char buf[BUFSIZE];
    printf("Test №1\n");
    fd = open("rd_test", O_RDONLY);
    std_ln = read(fd, buf, 30);
    printf("std sum of bytes read: %zd\n", std_ln);
    printf("std line read: %s \n", buf);
    bzero(buf, BUFSIZE);
    close(fd);
    fd = open("rd_test", O_RDONLY);
    nasm_ln = ft_read(fd, buf, 30);
    printf("nasm sum of bytes read: %zd\n", std_ln);
    printf("nasm line read  %s \n", buf);
    close(fd);
    printf("Test №2\n");
    fd = open("read_test", O_RDONLY);
    std_ln = read(fd, buf, 10000);
    printf("std sum of bytes read: %zd\n", std_ln);
    printf("std line read: %s \n", buf);
    bzero(buf, BUFSIZE);
    close(fd);
    fd = open("rd_test", O_RDONLY);
    nasm_ln = ft_read(fd, buf, 10000);
    printf("nasm sum of bytes read: %zd\n", std_ln);
    printf("nasm line read %s \n", buf);
    close(fd);
    printf("Test №3\n");
    errno = 0;
    std_ln = read(-1, buf, 10000);
    printf("std sum of bytes read: %zd\n", std_ln);
    perror("Std read set erno to");
    errno = 0;
    nasm_ln = ft_read(-1, buf, 10000);
    printf("nasm sum of bytes read: %zd\n", std_ln);
    perror("Std read set erno to");
    printf("Test №4\n");
    bzero(buf, BUFSIZE);
    fd = open("read_test", O_RDONLY);
    std_ln = read(fd, buf, 0);
    printf("std sum of bytes read: %zd\n", std_ln);
    printf("std line read: %s \n", buf);
    bzero(buf, BUFSIZE);
    close(fd);
    fd = open("rd_test", O_RDONLY);
    nasm_ln = ft_read(fd, buf, 0);
    printf("nasm sum of bytes read: %zd\n", std_ln);
    printf("nasm line read  %s \n", buf);
    close(fd);
    printf("Test №5\n");
    bzero(buf, BUFSIZE);
    fd = open("rd_test", O_RDONLY);
    std_ln = read(fd, buf, 1);
    printf("std sum of bytes read: %zd\n", std_ln);
    printf("std line read: %s \n", buf);
    bzero(buf, BUFSIZE);
    close(fd);
    fd = open("read_test", O_RDONLY);
    nasm_ln = ft_read(fd, buf, 1);
    printf("nasm sum of bytes read: %zd\n", std_ln);
    printf("nasm line read %s \n", buf);
    close(fd);
    printf("Test №5\n");
    bzero(buf, BUFSIZE);
    fd = open("read_test", O_RDONLY);
    std_ln = read(fd, buf, -1);
    printf("std sum of bytes read: %zd\n", std_ln);
    printf("std line read: %s \n", buf);
    bzero(buf, BUFSIZE);
    close(fd);
    fd = open("rd_test", O_RDONLY);
    nasm_ln = ft_read(fd, buf, -1);
    printf("nasm sum of bytes read: %zd\n", std_ln);
    printf("nasm line read %s \n", buf);
    close(fd);
    printf("Test №6\n");
    errno = 0;
    std_ln = read(200, buf, 10000);
    printf("std sum of bytes read: %zd\n", std_ln);
    perror("Std read set erno to");
    errno = 0;
    nasm_ln = ft_read(200, buf, 10000);
    printf("nasm sum of bytes read: %zd\n", std_ln);
    perror("Std read set erno to");
    printf("Test №7\n");
    bzero(buf, BUFSIZE);
    std_ln = read(0, buf, 10);
    printf("std sum of bytes read: %zd\n", std_ln);
    printf("std line read: %s\n", buf);
    bzero(buf, BUFSIZE);
    nasm_ln = ft_read(0, buf, 10);
    printf("nasm sum of bytes read: %zd\n", std_ln);
    printf("nasm line read: %s \n", buf);
}
void test_write(void)
{
    char *line = "Hello world\n";
    int fd;
    write(1, "Expected: ", 10);
    write(1, line, 12);
    write(1, "Received: ", 10);
    ft_write(1, line, 12);
    write(1, "empty_line\n", 13);
    write(1, "Expected:\n", 10);
    write(1, "", 1);
    write(1, "\n", 1);
    write(1, "Received:\n", 10);
    ft_write(1, "", 1);
    ft_write(1, "\n", 1);
    write(1, "Write to file. Check test.txt\n", 30);
    fd = open("test.txt", O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR);
    ft_write(fd, line, 12);
    write(fd, line, 12);
    close(fd);
    errno = 0;
    write(-1, line, 12);
    perror("Std write set erno to");
    errno = 0;
    ft_write(-1, line, 12);
    perror("Nasm ft_write set erno to");
    close(fd);
}
void test_strcmp(char *dst, char *src)
{
    int std_ln;
    int nasm_ln;
    std_ln = strcmp(dst, src);
    nasm_ln = ft_strcmp(dst, src);
    printf("Expected: %d\n", std_ln);
    printf("Received: %d\n", nasm_ln);
}
void test_strcpy(char *test_ln)
{
    char destptr[10000];
    char *std_ln;
    char *nasm_ln;
    std_ln = ft_strcpy(destptr, test_ln);
    nasm_ln = strcpy(destptr, test_ln);
    printf("Expected:_%s_\n", std_ln);
    printf("Received:_%s_\n", nasm_ln);
}
void test_ft_strlen(char *test_str)
{
    size_t std_ln;
    size_t asm_ln;
    std_ln = strlen(test_str);
    asm_ln = ft_strlen(test_str);
    printf("std: %zu, nasm %zu\n", std_ln, asm_ln);
}
int main(void)
{
    char bigline[] = "Calling conventions are a scheme for how functions receiveparameters from their caller and how they return a result. Returning a value from a function.";
    printf("---------------------ft_strlen---------------------------------\n");
    test_ft_strlen("");
    test_ft_strlen("Hello world");
    test_ft_strlen(bigline);
    printf("---------------------ft_strcpy---------------------------------\n");
    test_strcpy("Hello");
    test_strcpy("Hello world; test1; test2; test3; test4; test5");
    test_strcpy("");
    test_strcpy(bigline);
    printf("---------------------ft_strcpm---------------------------------\n");
    test_strcmp("Hello", "");
    test_strcmp("", "World");
    test_strcmp("Hello", "Hel");
    test_strcmp("Hel", "Hello");
    test_strcmp("", "");
    test_strcmp("Hello", "Hello");
    test_strcmp(bigline, bigline);
    test_strcmp(" ", "");
    test_strcmp("Helloo", "Hello");
    test_strcmp("", " ");
    test_strcmp("Hello", "Helloo");
    printf("----------------------ft_write---------------------------------\n");
    test_write();
    printf("----------------------ft_read_---------------------------------\n");
    test_read();
    printf("----------------------ft_strdup_-------------------------------\n");
    test_strdup("Hello");
    test_strdup("");
    test_strdup(bigline);
    return (0);
}