#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int main(void) {
    int input;
    Exhibit* head = NULL;

    while (1) {
        printf("Menu\n1 - Create new zoo\n2 - Add exhibit\n3 - Add animal\n4 - Remove animal\n5 - Remove exhibit\n6 - Exit\n");
        scanf("%d", &input);

        if (input == 1) {
            int num_of_exhibits;
            Exhibit* current;

            printf("How many exhibits would you like to start with? > ");
            scanf("%d", &num_of_exhibits);

            for (int i = 0; i < num_of_exhibits; i++) {
                char name[20];
                int cap;
                
                printf("Enter exhibit name > ");
                scanf("%s", name);
                printf("Enter exhibit capacity > ");
                scanf("%d", &cap);

                current = create_new_exhibit(name, cap);
                insert_exhibit_at_front(&head, current);
                head = current;
            }

            print_exhibits(head); 
        }
        
        else if (input == 2) {
            Exhibit* current = NULL;
            char name[40];
            int cap;

            printf("Enter exhibit name > ");
            scanf("%s", name);
            printf("Enter exhibit capacity > ");
            scanf("%d", &cap);

            current = create_new_exhibit(name, cap);
            insert_exhibit_at_front(&head, current);
            head = current;

            print_exhibits(head);
        }
        else if (input == 3) {
            char name[40];
            int age;
            char species[20];
            char exhibit[40];
            Animal *new_animal;

            printf("Enter animal name > ");
            scanf("%s", name);
            printf("Enter animal age > ");
            scanf("%d", &age);
            printf("Enter animal species > ");
            scanf("%s", species);
            printf("Enter animal's exhibit > ");
            scanf("%s", exhibit);


            new_animal = create_new_animal(name, age, species);
            insert_animal_at_front(&head, exhibit, new_animal);
            
            print_exhibits(head); 
        }
        else if (input == 4) {
            char name[40];
            char exhibit[40];

            printf("Enter animal name > ");
            scanf("%s", name);
            printf("Enter exhibit name > ");
            scanf("%s", exhibit);
            printf("Found the exhibit! now let's delete the animal\n");

            delete_animal(head, exhibit, name);

            print_exhibits(head);
        }
        else if (input == 5) {
            char name[40];
            printf("Enter exhibit name > ");
            scanf("%s", name);

            delete_exhibit(&head, name);

            print_exhibits(head);
        }
        else if (input == 6) {
            printf("Emptying the Zoo.\n");
            delete_all(&head);

            print_exhibits(head);
            return(0);
        }
        else {
            printf("Select an option from the menu.\n");
        }
    }
    
    return(0);
}