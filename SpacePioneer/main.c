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
if (random(50)==1) {
    PlaySound(TEXT("sound\\hiddensong.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
else {
    PlaySound(TEXT("sound\\main.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
decision("Welcome to Space Pioneer!", "New Game", "Select Stage", "Exit") {
case 1:
    break;
case 2:
    while (true) {
        clrscr();
        printf("Type your stage:\n" ENDER);
        scanf("%d", &stage);
        if (stage > 12) {
            stage=0;
            printf("Invalid stage.");
            getch();
            clrscr();
        }
        else {
            clrscr();
            break;
        }
    }
    break;
case 3:
    exit(1);
    break;
}
clrscr();
PlaySound(NULL, NULL, SND_APPLICATION);
while(true) {
    printf("What is the name of your character?" ENDER);
    scanf("%s", name);
    clrscr();
    question:
    printf("So your name is " ss ". Is this correct?" ENDER, name);
    scanf("%s", ans);
    *ans = tolower(*ans);
    if ((strcmp(ans, "yes") == 0) || (strcmp(ans, "no") == 0)) {
        if (strcmp(ans, "yes") == 0)
            break;
        if (strcmp(ans, "no") == 0)
            clrscr();
    }
    else {
        clrscr();
        goto question;
    }
}
clrscr();
story();
return 0;
}
