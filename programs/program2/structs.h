typedef struct Animal {
    char name[40];
    int age;
    char species[20];
    struct Animal *next;
} Animal;

typedef struct Exhibit {
    char name[40];
    int capacity;
    struct Exhibit *next;
    struct Animal *animal_head;
} Exhibit;

