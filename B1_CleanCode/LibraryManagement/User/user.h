#ifndef USER_H
#define USER_H

#define MAX_USERS 50
#define LENGHT_NAME 100
#define MAX_BORROW_BOOKS 10

#define USER_ERROR_LIST(X) \
    X(USER_SUCCESS_ADD, "User added successfully.") \
    X(USER_ADD_FAILED_FULL, "ERROR: Cannot add new user - library user list is full.") \
    X(USER_EDIT_FAILED_NOT_FOUND, "ERROR: Cannot edit user - user not found in the library.") \
    X(USER_SUCCESS_EDIT, "User information updated successfully.") \
    X(USER_DELETE_FAILED_NOT_FOUND, "ERROR: Cannot delete user - user not found in the library.") \
    X(USER_DELETE_FAILED_BORROWING, "ERROR: Cannot delete user - user currently has borrowed books.") \
    X(USER_SUCCESS_DELETE, "User deleted successfully.") \
    X(USER_SEARCH_NOT_FOUND, "Search user not found.") \
    X(USER_SEARCH_OK, "") \
    X(USER_BORROWING_SHOW_NOT_FOUND, "ERROR: There is no user borrowing book.") \
    X(USER_BORROWING_SHOW_OK, "")

typedef enum {
#define X(code, msg) code,
    USER_ERROR_LIST(X)
#undef X
    USER_ERROR_COUNT
} UserRetCode_t;

typedef struct {
    int id;
    char name[LENGHT_NAME];
    int borrowedBooks[MAX_BORROW_BOOKS];
    int borrowedCount; 
} User_t;

/**
 * @brief   Adds a new user to the library system.
 * @param   users The array of users in the library.
 * @param   count Pointer to the current number of users in the library. This will be updated if the user is added successfully.
 * @return  UserRetCode_t indicating the result of the operation.
 *
 * @details  This function inserts a new user entry into the library system.
 *           Return USER_SUCCESS_ADD if the user is added successfully, or USER_ADD_FAILED_FULL if the library user list is full.
 */
UserRetCode_t addUser(User_t users[], int *count);

/**
 * @brief   Updates information of an existing user in the library system.
 * @param   users The array of users in the library.
 * @param   count The current number of users in the library.
 * @return  UserRetCode_t indicating the result of the operation.
 *
 * @details  This function allows updating the information of an existing user in the library system.
 *           Return USER_SUCCESS_EDIT if the user information is updated successfully, or USER_EDIT_FAILED_NOT_FOUND if the user is not found in the library.
 */
UserRetCode_t editUser(User_t users[], int count);

/**
 * @brief   Deletes a user from the library system.
 * @param   users The array of users in the library.
 * @param   count Pointer to the current number of users in the library. This will be updated if the user is deleted successfully.
 * @return  UserRetCode_t indicating the result of the operation.
 *
 * @details  This function removes a user entry from the library system.
 *           Return USER_SUCCESS_DELETE if the user is deleted successfully, USER_DELETE_FAILED_NOT_FOUND if the user is not found in the library, or USER_DELETE_FAILED_BORROWING if the user currently has borrowed books.
 */
UserRetCode_t deleteUser(User_t users[], int *count);

/**
 * @brief   Returns a descriptive error message for a given user-related error code.
 * @param   code Error code defined in UserRetCode_t.
 * @return  void.
 */
const char* userRetCodeToString(UserRetCode_t code);
#endif /* USER_H */