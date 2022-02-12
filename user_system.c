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
    //TODO see https://stackoverflow.com/questions/13877546 for freeing char pointers

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
    // this handles the case where the user ID is not used
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
    user* temp = (user*)malloc(sizeof(user) * usersCapacity);
    
    // store current array in temp pointer (with allocated space)

    // if the array is not fully filled up the garbage date will still be copied over into the temp array
    // this doesn't matter as we can still write to the memory there
    for(int i = 0; i < usersIndex-1; i++)
    {
        temp[i].name = users[i].name;
        temp[i].email = users[i].email;
        temp[i].ID = users[i].ID;
    }

    // free old charpointers watch out for index 0 as this will free users itself
    free(&users[index].name);
    free(&users[index].email);
    
    // free users
    free(users);

    //set users equal to temp as temp will disappear after this function is run
    users = temp;
    // usersIndex mustnt be updated as this may lead to two users having the same ID
    // the problem with this approach is that we will not be able to write to the usersIndex -1
    // and the last member will be duplicated because we copied the whole array into the new one (aforementioned garbage data)
}

void users_resize(int new_capacity)
{

}


