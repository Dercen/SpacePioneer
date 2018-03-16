void story () {
    if (stage == 0)
    {
        printf("The galaxy is at war. Supreme Psychiatric Chounselor Imkay Ongjay Unay has been in control\nof the most vital natural resource in the galaxy,"\
               " Japanese White Rice, for 42 years.\nHowever, General Lil Pump of the BOIS, wants the savory flavor of the rice for himself, and he"\
               "\ntraffics it through wormholes dug by only the finest of garden worms.");
        getch();
        clrscr();
        printf("Imkay Ongjay Unay knows about the stealing of his rice though, and wants to put a stop to it.\nSo, he loaded up a bomber ship filled with"\
               " TESLAs and Algebra books. None of the BOIS knew\nwhat these things were, but when they were dropped on the city of Chicastop, they were"\
               "\ndevestating.");
        getch();
        clrscr();
        printf("Now you, " ss " of the BOIS army, must stop them. You have been given 500 galactic credits to\nbuy yourself some gear. Head on over to the shop and prepare"\
               " yourself for the long journey ahead.\n", name);
        getch();
        clrscr();
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
        clrscr();
        stage=1;
    }
    if (stage == 1)
    {
        shop(1);
        getch();
        clrscr();
        stage=2;
    }
    if (stage == 2)
    {
        printf("You get onto your ship, and take off to go fight Imkay.");
        getch();
        clrscr();
        fly(10);
        stage=3;
    }
    if (stage == 3)
    {
        printf("You have arrived at Weeblantia. The Japanese use this planet to genetically engineer\nreal life anime characters.");
        getch();
        clrscr();
        printf("You head into the local shop.");
        getch();
        clrscr();
        shop(1.2);
        clrscr();
        printf("As you walk out of the shop, you are confronted by a guard.\nHe sees the patch you wear on your shirt, which\nis the insignia of the BOIS.\n");
        getch();
        printf("You are not allowed here! The Japanese white rice belongs to\nthe Japanese, and you will never get any!");
        getch();
        clrscr();
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
                clrscr();
                die();
                break;
            }
        case 2:
            k = random(cash/4);
            printf("You offer the guard $%d, he takes it and lets you go.", k);
            cash-=k;
            getch();
            clrscr();
            break;
        case 3:
            printf("You just killed millions of people and will probably have to do a war crimes trial.\nOn the good side though, you did get some cash.");
            cash+=100;
            getch();
            clrscr();
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
            clrscr();
            decision("You walk into the facility, sneakily.\nYou see a guard walk up behind him, and...", "Karate chop him", "Shoot him", "Sneak by him")
            {
            case 1:
                if (random(10) >= 3) {
                    printf("The guard turns around and shoots you.");
                    getch();
                    clrscr();
                    die();
                    break;
                }
                else {
                    printf("You successfully knock out the guard, and steal some of his money.");
                    cash+=random(100);
                    getch();
                    clrscr();
                    break;
                }
            case 2:
                if (ammo >= 1) {
                    printf("You use your silencer on your gun and take out the guard silently.");
                    ammo-=1;
                    getch();
                    clrscr();
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
                    clrscr();
                }
            }
            break;
        case 2:
            clrscr();
            printf("You run in, guns blazing.\n");
            getch();
            clrscr();
            printf("Two security guards see you and open fire.");
            getch();
            clrscr();
            if (random(10) <= 3) {
                printf("You fire a few shots at them, but you get hit yourself! But the wound\nisn't major, and you manage to take out the guards.");
                health--;
            }
            else {
                printf("You manage to take them out though without problem.");
            }
            getch();
            clrscr();
            break;
        case 3:
            clrscr();
            printf("You hide your BOIS patch, and start walking through the building like you\nwork there. You experience no problems whatsoever.");
            getch();
            clrscr();
        }
        printf("You've made it into the facility. There is a rocket that will take you to the Imkay system.\nYou hop in and take off.");
        getch();
        clrscr();
        Sleep(500);
        PlaySound(TEXT("sound\\explosion.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(250);
        printf("Your rocket got to the Imkay system, but you crashed in the outer reaches of it.\nLooks like you will have to get to the main planet in your own ship.");
        getch();
        clrscr();
        if (hsje >= 1) {
            printf("You just remembered, you have an HSJE! You can use it to instantly get to\nthe home-planet of Imkay!");
            getch();
            clrscr();
            decision("Use your HSJE to get to the home-planet?", "No", "Yes", "Double Yes") {
        case 1:
            stage = 5;
            break;
        case 2:
        case 3:
            stage = 7;
            break;
            }
        }
        else {
            stage = 5;
        }
        fly(10);
    }
    if (stage == 5)
    {
        printf("You are 2 planets away from Imkay.\nOn the planet you are currently on, there is a shop.\nYou check it out.");
        getch();
        clrscr();
        shop(.8);
        clrscr();
        fly(12);
        stage=6;
    }
    if (stage == 6)
    {
        printf("You stop 1 planet away from the home-planet.\nThis planet houses the reinforcements for Imkay's Army.");
        getch();
        clrscr();
        decision("You have to take care of this problem so you don't\nhave to deal with it later.", "Bombard the planet", "Bribe the planet", "Personally walk up to every person on the planet and stab them individually") {
        case 1:
            if (ammo >= random(150)) {
                printf("It takes A LOT of ammo, but you end up taking out the entire planet. Good job.");
                getch();
                clrscr();
                break;
            }
            else {
                printf("You don't have the ammo to do this, and the people you didn't kill\nbefore you ran out of ammo have shot you down.");
                getch();
                clrscr();
                die();
                break;
            }
        case 2:
            if (cash >= random(150)) {
                printf("It takes A LOT of cash, but you end up bribing the entire planet. Good job.");
                getch();
                clrscr();
                break;
            }
            else {
                printf("You don't have the cash to do this, and the people end up deciding\nto kill you.");
                getch();
                clrscr();
                die();
                break;
            }
        case 3:
            if (1 == random(15)) {
                printf("Despite the incredible odds, you actually manage to kill everyone.\nGood job I guess.");
                getch();
                clrscr();
                break;
            }
            else {
                printf("This was a really bad decision.");
                getch();
                clrscr();
                die();
                break;
            }
        }
        printf("With the planet taken care of, you move on to the home-planet.");
        getch();
        clrscr();
        fly(10);
        stage=7;
    }
    if (stage == 7)
    {
        printf("The planet is actually a lot calmer than you expected.");
        getch();
        clrscr();
        printf("You ask a local the directions to Imkay's palace.");
        getch();
        clrscr();
        printf("\"Oh yeah, that bum? His palace is over there.\" He points towards the east\nwhere you see a large majestic palace.");
        getch();
        clrscr();
        printf("\"Be careful if you plan on going there, he says he's expecting visitors.\nHe says they want to take his rice or something.\"");
        getch();
        clrscr();
        printf("...");
        Sleep(1000);
        clrscr();
        stage=8;
    }
    if (stage == 8)
    {
        decision("You encounter Imkay. What do you do?", "Shoot him", "Attempt to capture him", "Offer him money in exchange for his rice") {
        case 1:
            stage = 9;
            clrscr();
            break;
        case 2:
            stage = 10;
            clrscr();
            break;
        case 3:
            stage = 11;
            clrscr();
            break;
        }
    }
    if (stage==9) {
        if ((random(10) >= 3) && (ammo >= 1)) {
            printf("You shoot Imkay.\nHe falls to the ground, dead.\n\nYou win!");
            getch();
            clrscr();
            ending();
        }
        else {
            printf("Imkay laughs. He pulls his gun out faster than you, and shoots you right between the eyes.");
            getch();
            clrscr();
            printf("\"You were never meant to have the legendary Japanese White Rice. You have lost!\"");
            getch();
            clrscr();
            die();
        }

    }
    if (stage==10) {
        if (random(10) >= 5) {
            printf("You dodge a shot fired by Imkay, and get within tackling distance.\nYou take him down and handcuff him.\nYou win.");
            getch();
            clrscr();
            ending();
        }
        else {
            printf("Imkay laughs. He shoots you right between the eyes.");
            getch();
            clrscr();
            printf("\"You were never meant to have the legendary Japanese White Rice. You have lost!\"");
            getch();
            clrscr();
            die();
        }
    }
    if (stage==11) {
        printf("\"You kill almost all of my men, and break into my house, and alls you want is a good\ndeal on my rice? No.\"\nImkay shoots you.");
        die();
    }
    if (stage==12) {
        ending();
    }
}
