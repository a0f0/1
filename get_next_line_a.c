#include "get_next_line.h"

char *get_next_line(int fd)
{
    int x, rd = 0;
    char c;

    if (BUFFER_SIZE <= 0)
        return (NULL);
    char *buf = malloc(100000); // check before the current BUFFER_SIZE and then malloc
    while ((rd = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
    {
        buf[x++] = c;
        if (c == '\n')
            break;
    }
    buf[x] = '\0';
    if (rd == -1 || x == 0 || (!buf[x - 1] && !rd))
        return (free(buf), NULL);
    return (buf);
}
