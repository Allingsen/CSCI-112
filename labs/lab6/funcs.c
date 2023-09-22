#include <stdio.h>
#include <string.h>
#include <math.h>
#include "lab6.h"

void fight(character *f_1, character *f_2) {
    printf("### LET'S FIGHT ###\n");
    printf("%s (%d XP, %d HP) vs %s (%d XP, %d HP)\n", 
            f_1->name, f_1->xp, f_1->hp, f_2->name, f_2->xp, f_2->hp);
    if (f_1->xp == f_2->xp) {
        printf("Its a tie!\n");
    }
    else if (f_1->xp > f_2->xp) {
        int damage = (f_1->xp - f_2->xp);
        int xp_gain = floor(log10(f_1->xp));
        
        f_1->xp = f_1->xp + xp_gain;
        f_2->xp = 1.5 * f_2->xp;
        f_2->hp = f_2->hp - damage;

        printf("%s does %d damage to %s\n", f_1->name, damage, f_2->name);
    }
    else if (f_2->xp > f_1->xp) {
        int damage = (f_2->xp - f_1->xp);
        int xp_gain = floor(log10(f_2->xp));
        
        f_2->xp = f_2->xp + xp_gain;
        f_1->xp = 1.5 * f_1->xp;
        f_1->hp = f_1->hp - damage;

        printf("%s does %d damage to %s\n", f_2->name, damage, f_1->name);
    }

    printf("\nResult is:\n");
    if (f_1-> hp <= 0) {
        strcat(f_1->name, " (deceased)");
    }
    else if (f_2-> hp <= 0) {
        strcat(f_2->name, " (deceased)");
    }
   
    printf("%s (%d XP, %d HP)\n", f_1->name, f_1->xp, f_1->hp);
    printf("%s (%d XP, %d HP)\n", f_2->name, f_2->xp, f_2->hp);
    
}