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
int health=100;

void clrscr(){
        system("cls");
}

void die() {
printf("You died. Good job.\n");
getch();
exit(1);
}

int random(int a) {
int r = rand() % a+1;
return r;
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
                clrscr();
            }
            else if ((a=='b') && (cash >= hsjec)) {
                cash -= hsjec;
                hsje += 1;
                clrscr();
            }
            else if ((a=='c') && (cash >= ac)) {
                cash -= ac;
                ammo += 10;
                clrscr();
            }
            else if (a=='g') {
                printf("Thanks, and have a nice day!\n");
                break;
            }
            else {
                clrscr();
            }
        }
}

int d(char question[], char choice1[], char choice2[], char choice3[]){
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
            clrscr();
        }
    }
}

void randencounter(int b) {
    if (b==1) {
            int k = random(10);
            decision("You've encountered space bandits! Do you want to:", "Shoot them", "Run away", "Give them what they want"){
            case 1:
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
            case 2:
                printf("You ran away, but you were hit in the leg on the way out.\n");
                health-=1;
                break;
            case 3:
                printf("You gave them some of your money.\n");
                cash -= random(cash/2);
                health -= 1;
                break;
            }
            clrscr();
    }
    if (b==2) {
        printf("Your ship got hit by an asteroid.\n");
        health -= 1;
    }
    if (b==3) {
            int k = random(10);
            decision("You've encountered an asteroid belt. Do you want to:", "Go through it", "Go around it", "Blast your way through it"){
            case 1:
                if (3 >= k) {
                    printf("You got through unharmed.\n");
                    break;
                }
                else {
                    printf("You took some damage getting through the belt.\n");
                    health -= 1;
                    break;
                }
            case 2:
                printf("You went around it, but it took awhile.\n");
                fuel-=random(fuel/8);
                break;
            case 3:
                printf("You blasted through it.\n");
                ammo -= random(ammo/6);
                break;
            }
            clrscr();
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
    getch();
    clrscr();
}

void fly(int f) {
        int prcnt=0;
        int fuch=0;
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
                clrscr();
            }
            else if ((fuel>0) && (qcg==true))
            {
                printf("Disabling QCG...\n");
                qcg=false;
                getch();
                clrscr();
            }
            else if ((fuel==0) && (qcg==true))
            {
                health-=1;
            }
            clrscr();
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
                clrscr();
                randencounter(random(5));
                getch();
            }
        }
        clrscr();
}

void ending() {
    int cr=0;
    printf("You head back home, and are rewarded with everything you could of ever wanted. Life, is good.\n\n\n\n\nTHE END");
    getch();
    clrscr();
    while(true){
            if (cr==0) {
                printf(ss, "CREDITS");
            }
            if ((cr>=1) && (cr<4)) {
                printf("\n");
            }
            if (cr==4) {
                printf("Code - Zachery Woodruff");
            }
            if ((cr>=5) && (cr<7)) {
                printf("\n");
            }
            if (cr==7) {
                printf("Code - Cody Toone");
            }
            if ((cr>=8) && (cr<10)) {
                printf("\n");
            }
            if (cr==10) {
                printf("Code - Gage Wilson");
            }
            if ((cr>=11) && (cr<13)) {
                printf("\n");
            }
            if (cr==13) {
                printf("Code And Story - Shandon Holm");
            }
            if ((cr>=14) && (cr<16)) {
                printf("\n");
            }
            if (cr==16) {
                printf("Code And Story - Trystan Rousseau");
            }
            if ((cr>=17) && (cr<19)) {
                printf("\n");
            }
            if (cr==19) {
                printf("Code And Sound Design - Gabriel Cortez");
            }
            if ((cr>=20) && (cr<30)) {
                printf("\n");
            }
            if (cr==30) {
                printf("Thanks for playing!");
                break;
            }
        cr++;
        Sleep(300);
    }
    getch();
    exit(1);
}
