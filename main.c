#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *line;
    
    line = get_next_line(0);  // Lee de stdin
    printf("Linea: %s", line);
    free(line);
    
    return (0);
}