#include "ultils.h"
#include <stdio.h>
#include <string.h>

void showBooks(Book_t books[], int n)
{
    printf("ID\tTitle\tAuthor\tStatus\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t%s\t%s\n", books[i].id, books[i].title, books[i].author, books[i].isBorrowed ? "Borrowed" : "Available");
    }
}

void showUsers(User_t users[], int n)
{
    printf("ID\tName\tBorrowed Books\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t", users[i].id, users[i].name);
        for (int j = 0; j < users[i].borrowedCount; j++)
        {
            printf("%d ", users[i].borrowedBooks[j]);
        }
        printf("\n");
    }
}

BookRetCode_t showBorrowedBooks(Book_t books[], int n)
{
    int found = 0;
    printf("ID\tTitle\tAuthor\n");
    for (int i = 0; i < n; i++)
    {
        if (books[i].isBorrowed)
        {
            printf("%d\t%s\t%s\n", books[i].id, books[i].title, books[i].author);
            found = 1;
        }
    }
    return found ? BOOK_BORROWED_SHOW_OK : BOOK_BORROWED_SHOW_NOT_FOUND;
}

UserRetCode_t showBorrowingUsers(User_t users[], int n)
{
    int found = 0;
    printf("ID\tName\n");
    for (int i = 0; i < n; i++)
    {
        if (users[i].borrowedCount > 0)
        {
            printf("%d\t%s\n", users[i].id, users[i].name);
            found = 1;
        }
    }
    return found ? USER_BORROWING_SHOW_OK : USER_BORROWING_SHOW_NOT_FOUND;
}

BookRetCode_t searchBook(Book_t books[], int n)
{
    char keyword[MAX_LEN_TITLE];
    printf("Enter book title or author to search: ");
    scanf(" %[^\n]", keyword);
    int found = 0;
    printf("ID\tTitle\tAuthor\tStatus\n");
    for (int i = 0; i < n; i++)
    {
        if (strstr(books[i].title, keyword) || strstr(books[i].author, keyword))
        {
            printf("%d\t%s\t%s\t%s\n", books[i].id, books[i].title, books[i].author, books[i].isBorrowed ? "Borrowed" : "Available");
            found = 1;
        }
    }
    return found ? BOOK_SERCH_OK : BOOK_SERCH_NOT_FOUND;
}

UserRetCode_t searchUser(User_t users[], int n)
{
    char keyword[LENGHT_NAME];
    printf("Enter user name to search: ");
    scanf(" %[^\n]", keyword);
    int found = 0;
    printf("ID\tName\n");
    for (int i = 0; i < n; i++)
    {
        if (strstr(users[i].name, keyword))
        {
            printf("%d\t%s\n", users[i].id, users[i].name);
            found = 1;
        }
    }
    return found ? USER_SEARCH_OK : USER_SEARCH_NOT_FOUND;
}

void showMenu(MenuType_t type)
{
    switch (type)
    {
        case MENU_MAIN:
            printf("=== Main Menu ===\n");
            printf("1. Manage Books\n");
            printf("2. Manage Users\n");
            printf("3. Exit\n");
            break;

        case MENU_BOOK:
            printf("=== Book Management Menu ===\n");
            printf("1. Add Book\n");
            printf("2. Edit Book\n");
            printf("3. Delete Book\n");
            printf("4. Borrow/Return Book\n");
            printf("5. Show All Books\n");
            printf("6. Search Book\n");
            printf("7. Back to Main Menu\n");
            break;

        case MENU_USER:
            printf("=== User Management Menu ===\n");
            printf("1. Add User\n");
            printf("2. Edit User\n");
            printf("3. Delete User\n");
            printf("4. Show All Users\n");
            printf("5. Search User\n");
            printf("6. Back to Main Menu\n");
            break;

        default:
            printf("Invalid Menu Type!\n");
            break;
    }
}