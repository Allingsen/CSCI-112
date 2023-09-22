#include <stdio.h>
#include "lab6.h"

int main(int argc, char* argv[]) {
    character fighter_1;
    character fighter_2;
    strcpy(fighter_1.name, argv[1]);
    fighter_1.xp = atoi(argv[2]);
    fighter_1.hp = atoi(argv[3]);

    strcpy(fighter_2.name, argv[4]);
    fighter_2.xp = atoi(argv[5]);
    fighter_2.hp = atoi(argv[6]);
    fight(&fighter_1, &fighter_2);
    return(0);
}