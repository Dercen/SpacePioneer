
void story () {
    if (stage == 0)
    {
        printf("The galaxy is at war. Supreme Psychiatric Chounselor Imkay Ongjay Unay has been in control\nof the most vital natural resource in the galaxy,"\
               " Japanese White Rice, for 42 years.\nHowever, General Lil Pump of the BOIS, wants the savory flavor of the rice for himself, and he"\
               "\ntraffics it through wormholes dug by only the finest of garden worms.");
        getch();
        system("cls");
        printf("Imkay Ongjay Unay knows about the stealing of his rice though, and wants to put a stop to it.\nSo, he loaded up a bomber ship filled with"\
               " TESLAs and Algebra books. None of the BOIS knew\nwhat these things were, but when they were dropped on the city of Chicastop, they were"\
               "\ndevestating.");
        getch();
        system("cls");
        printf("Now you, " ss " of the BOIS army, must stop them. You have been given 500 galactic credits to\nbuy yourself some gear. Head on over to the shop and prepare"\
               " yourself for the long journey ahead.\n", name);
        getch();
        system("cls");
        printf("                                 .---.`                                    ````                     \n\
                                 y---:///////////::::---------::::://///+/+///s                     \n\
                                 y..................-------------.............y                     \n\
                                 s-...........................................y                     \n\
                                 :o...................STORE...................y                     \n\
                                  h...........................................y                     \n\
                                  y...........................................y                     \n\
                                  y...............:::::::::::---.............-y                     \n\
                                  y..............-NNNNNNNNNNNmmmo............-y                     \n\
                                  y..............-MMMMMMMMMMMMMMh............-y                     \n\
                                  y..............-MMMMMMMMMMMMMMh............-y                     \n\
                                  y..............+MMMMMMMMMMMMMMs............-y                     \n\
                                  y..............yMMMMMMMMMMMMMM+............-y                     \n\
                                  h..............yMMMMMMMMMMMMMM:............-y                     \n\
    ``.--:::--``                  h........----:/yhhhyoooooooooo///+//:-----.-y                     \n\
`-//::-.````..::://:-.````````````h-:/+/+//:::-.`                    `.-::::/+y:-.```               \n\
--                 `.--::::::::::::-.`                                         `..-:::////:::::::://");
        getch();
        system("cls");
        stage=1;
    }
    if (stage == 1)
    {
        shop(1);
        getch();
        system("cls");
        stage=2;
    }
    if (stage == 2)
    {
        printf("You get onto your ship, and take off to go fight Imkay.");
        getch();
        system("cls");
        fly();
        stage=3;
    }
    if (stage == 3)
    {
        printf("You have arrived at Weeblantia. The Japanese use this planet to genetically engineer\nreal life anime characters.");
        getch();
        system("cls");
        printf("You head into the local shop.");
        getch();
        system("cls");
        shop(1.2);
        system("cls");
        printf("As you walk out of the shop, you are confronted by a guard.\nHe sees the patch you wear on your shirt, which\nis the insignia of the BOIS.\n");
        getch();
        printf("You are not allowed here! The Japanese white rice belongs to\nthe Japanese, and you will never get any!");
        getch();
        system("cls");
        while(true){
            printf("The guard pulls out a pistol and aims it at you. What do you do?\n\na: Quickdraw your pistol and shoot the guard\nb: Bribe the guard\nc: Run away, activating the planet's self destruct sequence on the way out.\n\n");
            scanf("%s", ans);
            system("cls");
            if (strcmp(ans, "a") == 0) {
                int k = random(10);
                if (k<=3) {
                    printf("You shot the guard, and got away.");
                    ammo--;
                    break;
                }
                else {
                    printf("You tried to pull a gun on someone who already had their gun out. You\nget shot first and die.\n");
                    system("cls");
                    getch();
                    die();
                }
            }
            else if (strcmp(ans, "b") == 0){
                int k = random(cash/4);
                printf("You offer the guard $%d, he takes it and lets you go.", k);
                cash-=k;
            }
        }

    }
}
