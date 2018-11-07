#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>
#include <limits.h>

enum { NUM_OF_PROC = 3 };

int
main(void)
{
    for (int i = 0; i < NUM_OF_PROC; ++i) {
        if (!fork()) {
            char s[CHAR_BIT + 1];
            int num;
            read(0, s, sizeof(s));
            s[CHAR_BIT] = 0;
            sscanf(s, "%d", &num);
            printf("%d %d\n", i + 1, num * num);
            fflush(stdout);
            break;
        }
    }
    for (int i = 0; i < NUM_OF_PROC; i++) {
        wait(NULL);
    }
    return 0;
}