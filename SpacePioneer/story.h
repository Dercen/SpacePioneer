
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
        fly(10);
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
        system("cls");
        printf("You are not allowed here! The Japanese white rice belongs to\nthe Japanese, and you will never get any!");
        getch();
        system("cls");
        int k;
        decision("The guard pulls out a pistol and aims it at you. What do you do?", "Quickdraw your pistol and shoot the guard", "Bribe the guard", "Run away, activating the planet's self destruct sequence on the way out.")
        {
        case 1:
            k = random(10);
            if (k<=3) {
                printf("You shot the guard, and got away.");
                ammo--;
                break;
            }
            else {
                printf("You tried to pull a gun on someone who already had their gun out. You\nget shot first and die.\n");
                getch();
                system("cls");
                die();
                break;
            }
        case 2:
            if (cash != 0) {
                k = random(cash/4);
                printf("You offer the guard $%d, he takes it and lets you go.", k);
                cash-=k;
            }
            else {
                printf("You don't have any money, and the guard shoots you.");
                die();
            }
            getch();
            system("cls");
            break;
        case 3:
            printf("You just killed millions of people and will probably have to do a war crimes trial.\nOn the good side though, you did get some cash.");
            cash+=100;
            getch();
            system("cls");
            break;
        }
        fly(20);
        stage=4;
    }
    if (stage == 4)
    {
        decision("You have reached an enemy research facility. What do you do?", "Sneaky approach", "Loud approach", "Casual approach")
        {
        case 1:
            system("cls");
            decision("You walk into the facility, sneakily.\nYou see a guard walk up behind him, and...", "Karate chop him", "Shoot him", "Sneak by him")
            {
            case 1:
                if (random(10) >= 3) {
                    printf("The guard turns around and shoots you.");
                    getch();
                    system("cls");
                    die();
                    break;
                }
                else {
                    printf("You successfully knock out the guard, and steal some of his money.");
                    cash+=random(100);
                    getch();
                    system("cls");
                    break;
                }
            case 2:
                if (ammo >= 1) {
                    printf("You use your silencer on your gun and take out the guard silently.");
                    ammo-=1;
                    getch();
                    system("cls");
                    break;
                }
                else {
                    printf("You don't have any ammo in your pistol, and because of this your\ngun makes a loud clicking noise. The guard turns around and shoots you.");
                    getch();
                    die();
                    break;
                }
            case 3:
                if (random(20) >= 3) {
                    printf("The guard notices you and shoots you.");
                    getch();
                    die();
                    break;
                }
                else {
                    printf("You successfully sneak by.");
                    getch();
                    system("cls");
                }
            }
            break;
        case 2:
            system("cls");
            printf("You run in, guns blazing.\n");
            getch();
            system("cls");
            printf("Two security guards see you and open fire.");
            getch();
            system("cls");
            if (random(10) <= 3) {
                printf("You fire a few shots at them, but you get hit yourself! But the wound\nisn't major, and you manage to take out the guards.");
                health--;
            }
            else {
                printf("You manage to take them out though without problem.");
            }
            getch();
            system("cls");
            break;
        case 3:
            system("cls");
            printf("You hide your BOIS patch, and start walking through the building like you\nwork there. You experience no problems whatsoever.");
            getch();
            system("cls");
            break;
        }

    }
}
