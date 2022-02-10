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
    // TODO handle error when ID not used
    //TODO how do I free the char pointers separately
    // find user at the index
    int index;
    for(int i = 0; i < usersIndex; i++)
    {
        if(users[i].ID == id)
        {
            // break out of the loop if ID is found
            i = index;
            break;
        }
        else index = -1;
    }

    if(index == -1)
    {
        return;
    }

    // shift all users on the right side of the selected user to the left
    for(int i = index; i < usersIndex-1; i++)
    {
        users[i].email = users[i+1].email;
        users[i].name = users[i+1].name;
        users[i].ID = users[i+1].ID;
    }

    // allocate new mem. with size -1 and free the old memory
    // store current array in temp pointer (with allocated space)
    // free old users
    // allocate mem with size-1 for users
    // copy temp into users
    // update index and capacity

}

void users_resize(int new_capacity)
{
}


