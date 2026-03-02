#include "book.h"
#include <stdio.h>
BookRetCode_t addBook(Book_t books[], int *n)
{
    if (*n >= MAX_BOOKS) {
        return BOOK_ADD_FAILED_FULL;
    }
    Book_t newBook;
    printf("Enter book ID: ");
    scanf("%d", &newBook.id);
    printf("Enter book title: ");
    scanf(" %[^\n]", newBook.title);
    printf("Enter book author: ");
    scanf(" %[^\n]", newBook.author);
    newBook.isBorrowed = 0; 
    books[*n] = newBook;
    (*n)++;
    return BOOK_SUCCESS_ADD;
}

BookRetCode_t editBook(Book_t books[], int n)
{
    int id;
    printf("Enter book ID to edit: ");
    scanf("%d", &id);
    for (int i = 0; i < n; i++)
    {
        if (books[i].id == id)
        {
            printf("Enter new book title: ");
            scanf(" %[^\n]", books[i].title);
            printf("Enter new book author:");
            scanf(" %[^\n]", books[i].author);
            return BOOK_SUCCESS_EDIT;
        }
    }
    return BOOK_EDIT_FAILED_NOT_FOUND;
}

BookRetCode_t deleteBook(Book_t books[], int *n)
{
    int id;
    printf("Enter book ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *n; i++)
    {
        if (books[i].id == id)
        {
            if (books[i].isBorrowed)
            {
                return BOOK_DELETE_FAILED_BORROWED;
            }
            for (int j = i; j < *n - 1; j++)
            {
                books[j] = books[j + 1];
            }
            (*n)--;
            return BOOK_SUCCESS_DELETE;
        }
    }
    return BOOK_DELETE_FAILED_NOT_FOUND;
}

BookRetCode_t borrowOrReturnBook(Book_t books[], int countBook, User_t  users[], int countUser, int isBorrow)
{
    int bookID, userID;
    printf("Enter book ID: ");
    scanf("%d", &bookID);
    printf("Enter user ID: ");
    scanf("%d", &userID);
    int bookIndex = -1, userIndex = -1;
    for (int i = 0; i < countBook; i++)
    {
        if (books[i].id == bookID)
        {
            bookIndex = i;
            break;
        }
    }
    for (int i = 0; i < countUser; i++)
    {
        if (users[i].id == userID)
        {
            userIndex = i;
            break;
        }
    }
    if (bookIndex == -1)
    {
        return BOOK_BORROW_RETURN_FAILED_BOOK_NOT_FOUND;
    }
    if (userIndex == -1)
    {
        return BOOK_BORROW_RETURN_FAILED_USER_NOT_FOUND;
    }
    if (isBorrow)
    {
        if (books[bookIndex].isBorrowed)
        {
            return BOOK_BORROW_RETURN_FAILED_BOOK_HAS_BEEN_BORROWED;
        }
        if (users[userIndex].borrowedCount >= MAX_BORROW_BOOKS)
        {
            return BOOK_BORROW_RETURN_FAILED_USER_LIMITED;
        }
        books[bookIndex].isBorrowed = 1;
        users[userIndex].borrowedBooks[users[userIndex].borrowedCount++] = bookID;
        return BOOK_BORROW_OK;
    }
    else
    {
        if (!books[bookIndex].isBorrowed)
        {
            return BOOK_BORROW_RETURN_FAILED_BOOK_EXISTED;
        }
        books[bookIndex].isBorrowed = 0;
        for (int i = 0; i < users[userIndex].borrowedCount; i++)
        {
            if (users[userIndex].borrowedBooks[i] == bookID)
            {
                for (int j = i; j < users[userIndex].borrowedCount - 1; j++)
                {
                    users[userIndex].borrowedBooks[j] = users[userIndex].borrowedBooks[j + 1];
                }
                users[userIndex].borrowedCount--;
                break;
            }
        }
        return BOOK_RETURN_OK;
    }
}

const char* bookRetCodeToString(BookRetCode_t code)
{
    switch (code) 
    {
        #define X(code, msg) case code: return msg;
        BOOK_ERROR_LIST(X)
        #undef X
        default: return "Invalid error";
    }
}
