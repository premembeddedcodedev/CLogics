#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char ***t = malloc(sizeof(char) * 1);           // one pointer
    int i, j;

    char s[1][3][2] = {{"he", "ll", 0}};

    printf("%s\n", s[0][0]);

    for( i = 0; i < 1; ++i )
    {
        t[i] = malloc(sizeof(char) * (argc - 1));       // not including program name
        for( j = 0; j < argc - 1; ++j )
        {
            t[i][j] = calloc(strlen(argv[j + 1]) + 1, sizeof(char));        // +1 for '\0'
        }
    }

    strncpy(t[0][0], argv[1], strlen(argv[1]));
    printf("%s\n", t[0][0]);

    return 0;
}
