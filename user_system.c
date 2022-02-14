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
        // had to change this function to work with users_delete()
            
        // compares all available indexes with all currently used numbers in ascending order
        // as soon as the two are equal the number is already used, if not 
        int isEqual = 0;
        for(int i = 0; i <= usersIndex; i++)
        {
            for(int j = 0; j <= usersIndex; j++)
            {
                if(i != users[j].ID)
                        isEqual = i;
                else
                {
                    isEqual = -1;
                    break;
                }
            }
            if(isEqual != -1)
            {
                users[usersIndex].ID = i;
                break;
            }
        }
            
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
            index = i;
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

    // allocate new memory
    user *temp = (user*)malloc(sizeof(user) * usersCapacity);
    
    // store current array in temp pointer (with allocated space)
    // dont copy the whole array as we dont want to duplicate the last arrayIndex's value
    for(int i = 0; i < usersIndex-1; i++)
    {
        temp[i].name = users[i].name;
        temp[i].email = users[i].email;
        temp[i].ID = users[i].ID;
    }

    // free all old charpointers
    // we should free from first place to 0, as this will free users itself
    for(int i = usersCapacity-1; i >= usersIndex; i--)
    {
        free(users[i].email);
        free(users[i].name);
    }
    
    // free users (dont really know if this is necessary as i free the name a index 0 which is equal to users itself)
    free(users);

    //set users equal to temp to get pointer to the new array
    users = temp;

    // decrease usersIndex by one as there is one less user in the array now
    usersIndex--;
    // is it safe to not free temp? I think it should work if we just free users at the end, not really sure
}

void users_resize(int new_capacity)
{
    // check if the size fits
    if(usersIndex > new_capacity)
        return;

    // allocate memory with the new size
    user *temp = (user*)malloc(sizeof(user) * new_capacity);

    // copy the contents into the new array
    for(int i = 0; i < usersIndex; i++)
    {
        temp[i].name = users[i].name;
        temp[i].email = users[i].email;
        temp[i].ID = users[i].ID;
    }

    // free the charpointers
    for(int i = usersCapacity-1; i >= usersIndex; i--)
    {
        free(users[i].email);
        free(users[i].name);
    }

    // free the old array
    free(users);

    users = temp;
    usersCapacity = new_capacity;
}


