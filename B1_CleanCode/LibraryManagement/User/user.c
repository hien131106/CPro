#include "user.h"
#include <stdio.h>

UserRetCode_t addUser(User_t users[], int *count)
{
    if (*count >= MAX_USERS) {
        return USER_ADD_FAILED_FULL;
    }
    User_t newUser;
    printf("Enter user ID: ");
    scanf("%d", &newUser.id);
    printf("Enter user name: ");
    scanf(" %[^\n]", newUser.name);
    newUser.borrowedCount = 0; 
    users[*count] = newUser;
    (*count)++;
    return USER_SUCCESS_ADD;
}

UserRetCode_t editUser(User_t users[], int count)
{
    int id;
    printf("Enter user ID to edit: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++)
    {
        if (users[i].id == id)
        {
            printf("Enter new user name: ");
            scanf(" %[^\n]", users[i].name);
            return USER_SUCCESS_EDIT;
        }
    }
    return USER_EDIT_FAILED_NOT_FOUND;
}

UserRetCode_t deleteUser(User_t users[], int *count)
{
    int id;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++)
    {
        if (users[i].id == id)
        {
            if (users[i].borrowedCount > 0)
            {
                return USER_DELETE_FAILED_BORROWING;
            }
            for (int j = i; j < *count - 1; j++)
            {
                users[j] = users[j + 1];
            }
            (*count)--;
            return USER_SUCCESS_DELETE;
        }
    }
    return USER_DELETE_FAILED_NOT_FOUND;
}

const char* userRetCodeToString(UserRetCode_t code)
{
    switch (code) 
    {
        #define X(code, msg) case code: return msg;
        USER_ERROR_LIST(X)
        #undef X
        default: return "Invalid error";
    }
}
