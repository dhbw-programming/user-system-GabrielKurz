#include "user_system.h"
#include <stdio.h>
#include <stdlib.h>
#include ".assignment/dhbw.h"
#include ".assignment/user_interface.h"

// AVAILABLE HERE: Function print_user(id, name, email) to print a single user
// Make sure to write empty functions for ALL functions in the header (also optional ones),
// otherwise the program will not compile

user *users;
int usersCapacity, usersIndex;

void users_initialize_table(int capacity)
{
    users = (user*) malloc(sizeof(user) * capacity);
    usersCapacity = capacity;
    usersIndex = 0;
}

user_id users_add(char *name, char *email)
{
    if(usersIndex < usersCapacity)
    {
        users[usersIndex].name = name;
        users[usersIndex].email = email;
        users[usersIndex].ID = usersIndex;
        usersIndex++;
        return users[usersIndex-1].ID;
    }
    else
    {
        return -1;
    }
}

void users_printall()
{
    for(int i = 0; i < usersIndex; i++)
    {
        print_user(users[i].ID, users[i].name, users[i].email);
    }
}

char *users_get_name(user_id id)
{
    for(int i = 0; i < usersIndex; i++)
    {
        if(users[i].ID == id)
        {
            return users[i].name;
        }
    }
    return NULL;
}

void users_delete(user_id id)
{
}

void users_resize(int new_capacity)
{
}


