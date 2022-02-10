#include <stdio.h>
#include <stdlib.h>
#include "user_interface.h"

void print_prompt();
void add_user();
void get_user_name();
void delete_user();
void resize_library();

void print_user(user_id id, char *name, char *email) {
    printf("User %i, Name: %s, E-Mail: %s\n", id, name, email);
}

void user_interface() {
    users_initialize_table(50);

    char selection;
    while (1) {
        print_prompt();
        scanf(" %c", &selection);
        switch (selection) {
            case 'a':
            case 'A':
                add_user();
                break;
            case 'l':
            case 'L':
                users_printall();
                break;
            case 'n':
            case 'N':
                get_user_name();
                break;
            case 'd':
            case 'D':
                delete_user();
                break;
            case 'r':
            case 'R':
                resize_library();
                break;
            default:
                printf("Unknown option \"%c\"\n", selection);
        }
        printf("-----------------------------------\n");
    }
}

void print_prompt() {
    printf("Please chose what you want to do:\n");
    printf("a: Add a new user\n");
    printf("l: List current users\n");
    printf("n: Get a single user's name\n");
    printf("d: Delete a user\n");
    printf("r: Resize the user library\n");
    printf("> ");
}

void add_user() {
    char *name = (char*) malloc(50);
    char *email = (char*) malloc(50);
    printf("Creating a new user...\n");
    printf("User's name> ");
    scanf("%50s", name);
    printf("User's email> ");
    scanf("%50s", email);

    user_id id = users_add(name, email);
    if (id == -1) {
        free(name);
        free(email);
        printf("Could not add user due to missing space!\n");
    } else {
        printf("Added user %s and assigned ID %i!\n", name, id);
    }
}

void get_user_name() {
    int id;
    printf("Getting a user's name!\n");
    printf("User's ID> ");
    scanf("%i", &id);

    char *usr_name = users_get_name(id);
    if (!usr_name) {
        printf("That user could not be found!\n");
    } else {
        printf("The user with ID \"%i\" has is named \"%s\"!\n", id, usr_name);
    }
}

void delete_user() {
    int id;
    printf("Deleting a user!\n");
    printf("User's ID> ");
    scanf("%i", &id);

    users_delete(id);
}

void resize_library() { 
    int size;
    printf("Resizing the library!\n");
    printf("New size> ");
    scanf("%i", &size);

    users_resize(size);
}
