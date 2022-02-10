typedef int user_id;

// initializes a global user table with the given capacity
void users_initialize_table(int capacity);

// add user to the global table, return user's ID
// if no space in table left: do nothing and return -1
user_id users_add(char *name, char *email);

// print all users to stdout
void users_printall();

// return user's name
// if ID does not exist: return null pointer
char *users_get_name(user_id id);

// ---------------------------OPTIONAL--------------------------------

// optional: for fast teams
// remove user from user table
// potentially: fill "hole" in user table (shift all entries)
// free memory from deleted user object (including char pointers)
// user ids of other users should not change
// if user not in table: do nothing
void users_delete(user_id id);

// optional: for really fast teams
// resize table to keep track of more users or fewer
// all users should be kept in the table, with the same IDs
// if new capacity is not enough for number of users, do nothing
void users_resize(int new_capacity);
