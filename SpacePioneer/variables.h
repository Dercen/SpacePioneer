#define ANSI_COLOR_RED     "\x1b[91m"
#define ANSI_COLOR_GREEN   "\x1b[92m"
#define ANSI_COLOR_YELLOW  "\x1b[93m"
#define ANSI_COLOR_BLUE    "\x1b[94m"
#define ANSI_COLOR_MAGENTA "\x1b[95m"
#define ANSI_COLOR_CYAN    "\x1b[96m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ENDER              "\n|:> "
#define ss                 ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET
#define repeat(n)          for (int i = 0; i < n; i++)
#define decision(q, a, b, c) switch (d(q, a, b, c))
#define deca(q, c) switch (da(q, c))
char name[100];
char cplnt[100];
int fuel=0;
int hsje=0;
int ammo=0;
bool qcg=false;
char ans[100];
int cash = 500;
int stage = 0;
char shp[100];
int r;
int prcnt=0;
int health=10;
int fuch=0;

void die() {
printf("You died. Good job.\n");
getch();
exit(1);
}

int random(int a) {
r = rand() % a+1;
return r;
}

void randencounter(int b) {
    if (b==1) {
        while(1) {
            printf("You've encountered space bandits! Do you want to:\n\na: Shoot them\nb: Run away\nc: Give them what they want\n\n" ENDER);
            scanf("%s", ans);
            if (strcmp(ans, "a") == 0) {
                int k = random(10);
                if (ammo >= k) {
                    printf("You shot the bandits.\n");
                    ammo -= k;
                    break;
                }
                else {
                    printf("You shot at the bandits, but you ran out of ammo!\n");
                    ammo = 0;
                    health -= 1;
                    break;
                }
            }
            else if (strcmp(ans, "b") == 0) {
                printf("You ran away, but you were hit in the leg on the way out.\n");
                health-=1;
                break;
            }
            else if (strcmp(ans, "c") == 0) {
                printf("You gave them some of your money.\n");
                cash -= random(cash/2);
                health -= 1;
                break;
            }
            system("cls");
        }
    }
    if (b==2) {
        printf("Your ship got hit by an asteroid.\n");
        health -= 1;
    }
    if (b==3) {
        while(1) {
            printf("You've encountered an asteroid belt. Do you want to:\n\na: Go through it\nb: Go around it\nc: Blast your way through it\n\n" ENDER);
            scanf("%s", ans);
            if (strcmp(ans, "a") == 0) {
                int k = random(10);
                if (3 >= k) {
                    printf("You got through unharmed.\n");
                    break;
                }
                else {
                    printf("You took some damage getting through the belt.\n");
                    health -= 1;
                    break;
                }
            }
            else if (strcmp(ans, "b") == 0) {
                printf("You went around it, but it took awhile.\n");
                fuel-=random(fuel/8);
                break;
            }
            else if (strcmp(ans, "c") == 0) {
                printf("You blasted through it.\n");
                ammo -= random(ammo/6);
                break;
            }
            system("cls");
        }
    }
    if (b==4) {
        printf("You found an abandoned ship.\n");
        fuel+=random(50);
        cash+=random(50);
        ammo+=random(50);
    }
    if (b==5) {
        if (hsje>0)
        {
            printf("You blew an HSJE.\n");
            hsje-=1;
        }
        else
        {
            printf("You found a 1915 nickel.\n");
            cash+=100;
        }
    }
}

void fly(int f) {
        while(prcnt != f) {
            Sleep(500);
            prcnt+=1;
            fuch=random(5);
            if ((fuel>=fuch) && (qcg==false)) {
                fuel-=fuch;
            }
            else if ((fuel<fuch) && (qcg==false))
            {
                printf("You ran out of fuel! Your QCG has been activated.\nYour ship will take damage until you buy more fuel.\n");
                fuel=0;
                qcg=true;
                getch();
                system("cls");
            }
            else if ((fuel>0) && (qcg==true))
            {
                printf("Disabling QCG...\n");
                qcg=false;
                getch();
                system("cls");
            }
            else if ((fuel==0) && (qcg==true))
            {
                health-=1;
            }
            system("cls");
            if (health<=0) {
                die();
            }
            printf("[");
            repeat(prcnt) {
                printf("o");
            }
            repeat(f-prcnt) {
                printf(" ");
            }
            printf("]");
            printf("\nHealth: %d\nFuel: %d\nHSJE: %d\nAmmo: %d\nCash: %d\n", health, fuel, hsje, ammo, cash);
            if (random(10)==1) {
                system("cls");
                randencounter(random(5));
                getch();
            }
        }
        system("cls");
}

void shop(float p) {
        char a;
        int fc = ceil(5*p);
        int hsjec = ceil(200*p);
        int ac = ceil(5*p);
        while(true){
            printf("Welcome to my shop! What do you need?\n\n");
            printf("a)Fuel: have %d, costs $%d for 10\nb)Hyperspace Jump Engines: have %d, costs $%d for 1\nc)Ammo: have %d, costs $%d for 10\n\nCash: %d\n\n\nPress 'g' when you are finished.\n" ENDER, fuel, fc, hsje, hsjec, ammo, ac, cash);
            a = getch();
            if ((a=='a') && (cash >= fc)) {
                cash -= fc;
                fuel += 10;
                system("cls");
            }
            else if ((a=='b') && (cash >= hsjec)) {
                cash -= hsjec;
                hsje += 1;
                system("cls");
            }
            else if ((a=='c') && (cash >= ac)) {
                cash -= ac;
                ammo += 10;
                system("cls");
            }
            else if (a=='g') {
                printf("Thanks, and have a nice day!\n");
                break;
            }
            else {
                system("cls");
            }
        }
}

int d(char question[], char choice1[], char choice2[], char choice3[]){//decition with 3 choices
    char a;
    while(true){
        printf(question);
        printf("\na)%s \nb)%s \nc)%s \n\n" ENDER, choice1, choice2, choice3);
        a = getch();
        if(a == 'a'){
            return 1;
            break;
        }else if(a == 'b'){
            return 2;
            break;
        }else if(a == 'c'){
            return 3;
            break;
        }else{
            system("cls");
        }
    }
}

int da(char question[], char choices[][]){//decition with any number of choices(currently untesed) 
    //choices is an array of strings
    //will start at 0 instead of 1
    char a;
    const char[27] index = "abcdefghijklmnopqrstuvwxyz";
    while(true){
        printf(question);
        printf("\na)%s \nb)%s \nc)%s \n\n" ENDER, choice1, choice2, choice3);
        a = getch();
        for(int i = 0; i < sizeof(choices)/sizeof(choices[0]); i++){
            if(a == index[i]){
                return i;
            }
        }else{
            system("cls");
        }
    }
}

