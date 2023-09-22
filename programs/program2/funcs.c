#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


// exhibit funcs

void print_exhibits(Exhibit* head) {
    Exhibit* temp = head;
    
    printf("THE ZOO\n");
    if (temp == NULL) {
        printf("The zoo is empty.\n");
    }

    while (temp != NULL) {
        printf("%s Exhibit (%d animal capacity)\n", temp->name, temp->capacity);
        if (temp->animal_head == NULL) {
            printf("No Animals.\n");
        }
        else {
            print_animals(temp->animal_head);
        }
        temp = temp->next;
    }
}


Exhibit* create_new_exhibit(char name[], int capacity) {
    Exhibit* new_exhibit;

    new_exhibit = malloc(sizeof(Exhibit));

    strcpy(new_exhibit->name, name);
    new_exhibit->capacity = capacity;
    new_exhibit->next = NULL;
    new_exhibit->animal_head = NULL;

    return new_exhibit;
}


void insert_exhibit_at_front(Exhibit** head, Exhibit *e) {
    e->next = *head;
    head = &e;
}

void delete_exhibit(Exhibit** head, char name[]) {
    Exhibit *temp = *head;
    Exhibit *prev = *head;


    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (strcmp(temp->name, prev->name) == 0) {
                *head = temp->next;
                free(temp);
            }
            else {
                prev->next = temp->next;
                free(temp);
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void delete_all(Exhibit** head) {
    Exhibit *temp = *head;
    Animal *ani = temp->animal_head;

    while (temp != NULL) {
        while (ani != NULL) {
            temp->animal_head = ani;
            free(temp->animal_head);
            ani = ani->next;
        }
        *head = temp->next;
        free(*head);
        temp = temp->next;
    }
}


// animal funcs

void insert_animal_at_front(Exhibit** head, char name[], Animal* n) {
    Exhibit *temp = *head;
    int counter = 0;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            Animal *num = temp->animal_head;
            while (num != NULL) {
                counter++;
                num = num->next;
            }
            if (counter >= temp->capacity) {
                printf("Exhibit is already at capacity!\n");
            }
            else {
                n->next = temp->animal_head;
                temp->animal_head = n;
                
            }
        }
        temp = temp->next;
    }   
}

Animal* create_new_animal(char name[], int age, char species[]) {
    Animal* new_animal;

    new_animal = malloc(sizeof(Animal));

    strcpy(new_animal->name, name);
    new_animal->age = age;
    strcpy(new_animal->species, species);
    new_animal->next = NULL;

    return new_animal;
}

void print_animals(Animal* head) {
    Animal *temp = head;

    while (temp != NULL) {
        printf("%s (%s, age %d)->", temp->name, temp->species, temp->age);
        temp = temp->next;
    }
    printf("\n");
}

void delete_animal(Exhibit* head, char name[], char animal_name[]) {
    Exhibit *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            Animal *num = temp->animal_head;
            Animal *prev = temp->animal_head;
            while (num != NULL) {
                if (strcmp(num->name, animal_name) == 0) {
                    if (num == temp->animal_head) {
                        free(temp->animal_head);
                        temp->animal_head = (num->next);
                        if (temp->animal_head != NULL) {
                            (temp->animal_head)->next = (num->next)->next;
                        }
                        
                    }
                    else {
                        Animal *next = num->next;
                        Animal * old_head = temp->animal_head;
                        temp->animal_head = num;
                        prev->next = next;
                        free(temp->animal_head);
                        temp->animal_head = old_head;
                    }
                    return;
                }
                prev = num;
                num = num->next;
            }
        }
        temp = temp->next;
    }
}

// other funcs
