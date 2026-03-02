#ifndef UILTILS_H
#define UILTILS_H

#include "../Book/book.h"
#include "../User/user.h"

#define MENU_LIST(X) \
    X(MENU_MAIN,   "PROGRAM MANAGE THE LIBRARY", mainMenuItems) \
    X(MENU_BOOK,   "BOOK MANAGEMENT MENU",       bookMenuItems) \
    X(MENU_USER,   "USER MANAGEMENT MENU",       userMenuItems) \
    X(MENU_BORROW, "BORROW / RETURN MANAGEMENT MENU", borrowMenuItems) \
    X(MENU_SEARCH, "SEARCH & DISPLAY MENU",      searchMenuItems)

typedef enum {
    #define DEFINE_ENUM(name, title, items) name,
    MENU_LIST(DEFINE_ENUM)
    MENU_LAST
    #undef DEFINE_ENUM
} MenuType_t;

/**
 * @brief   Displays all the books in the library.
 * @param   books   Array of Book_t structures. 
 * @param   n       The number of books in the library.
 * @return  void.
 * @details Prints a formatted list of all books in the library and their information.
 */
void showBooks(Book_t books[], int n);

/**
 * @brief   Displays all the users in the library.
 * @param   users   Array of User_t structures.
 * @param   n       The number of users in the library.
 * @return  void.
 * @details Prints a formatted list of all users in the library and their information.
 */
void showUsers(User_t users[], int n);

/**
 * @brief   Displays all the books currently borrowed by users.
 * @param   books   Array of Book_t structures.
 * @param   n       The number of books in the library.
 * @return  BookRetCode_t indicating the result of the operation.
 * @details Lists all books that are currently marked as borrowed
 */
BookRetCode_t showBorrowedBooks(Book_t books[], int n);

/**
 * @brief   Displays all the users who are currently borrowing books.
 * @param   users   Array of User_t structures.
 * @param   n       The number of users in the library.
 * @return  UserRetCode_t indicating the result of the operation.
 * @details Show users who have at least one borrowed book. 
 */
UserRetCode_t showBorrowingUsers(User_t users[], int n);

/**
 * @brief   Searches for a book in the library based on user input.
 * @param   books   Array of Book_t structures.
 * @param   n       The number of books in the library.
 * @return  BookRetCode_t indicating the result of the search operation.
 * @details Prompts the user to enter search criteria (e.g., title, author) and searches for matching books in the library. 
 *          Returns BOOK_SEARCH_OK if a matching book is found, or BOOK_SEARCH_NOT_FOUND if no matches are found.
 */
BookRetCode_t searchBook(Book_t books[], int n);

/**
 * @brief   Searches for a user in the library based on user input.
 * @param   users   Array of User_t structures.
 * @param   n       The number of users in the library.
 * @return  UserRetCode_t indicating the result of the search operation.
 * @details Prompts the user to enter search criteria (e.g., name, ID) and searches for matching users in the library. 
 *          Returns USER_SEARCH_OK if a matching user is found, or USER_SEARCH_NOT_FOUND if no matches are found.
 */
UserRetCode_t searchUser(User_t users[], int n);

/**
 * @brief   Displays the menu options for a given menu type.
 * @param   type    The type of menu to display (e.g., main menu, book management menu).
 * @return  void.
 * @details Prints the menu options corresponding to the specified menu type.
 */
void showMenu(MenuType_t type);

#endif // UILTILS_H