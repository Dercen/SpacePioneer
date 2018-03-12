#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <stdarg.h>
#include <math.h>
#include "variables.h"
#include "story.h"

int main (int argc, char const *argv[]) {
srand (time(NULL));
PlaySound(TEXT("sound\\main.wav"), NULL,SND_ASYNC);
printf("Welcome to Space Pioneer! Press any key to begin.");
getch();
system("cls");// flip
while(true) {
    printf("What is the name of your character?" ENDER);
    scanf("%s", name);
    system("cls");
    question:
    printf("So your name is " ss ". Is this correct?" ENDER, name);
    scanf("%s", ans);
    *ans = tolower(*ans);
    if ((strcmp(ans, "yes") == 0) || (strcmp(ans, "no") == 0)) {
        if (strcmp(ans, "yes") == 0)
            break;
        if (strcmp(ans, "no") == 0)
            system("cls");
    }
    else {
        system("cls");
        goto question;
    }
}
system("cls");
story();
return 0;
}
//helllllp;
