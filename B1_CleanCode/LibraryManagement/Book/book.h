#include "../User/user.h"
#ifndef BOOK_H
#define BOOK_H

#define MAX_BOOKS 100
#define MAX_LEN_TITLE MAX_BOOKS
#define MAX_LEN_NAME_AUTHOR MAX_BOOKS
#define BORROW_BOOK 1
#define RETURN_BOOK 2
#define BOOK_ERROR_LIST(X)  \
    X(BOOK_SUCCESS_ADD, "Book added successfully.") \
    X(BOOK_ADD_FAILED_FULL, "ERROR: Cannot add new book - library storage is full.") \
    X(BOOK_EDIT_FAILED_NOT_FOUND, "ERROR: Cannot edit book - book not found in library.") \
    X(BOOK_SUCCESS_EDIT, "Book information updated successfully.") \
    X(BOOK_DELETE_FAILED_NOT_FOUND, "ERROR: Cannot delete book - book not found in library.") \
    X(BOOK_DELETE_FAILED_BORROWED, "ERROR: Cannot delete book - the book is currently borrowed.") \
    X(BOOK_SUCCESS_DELETE, "Book deleted successfully.") \
    X(BOOK_BORROW_RETURN_FAILED_USER_NOT_FOUND, "ERROR: Cannot borrow or return book - user not found.") \
    X(BOOK_BORROW_RETURN_FAILED_BOOK_NOT_FOUND, "ERROR: Cannot borrow or return book - book not found.") \
    X(BOOK_BORROW_RETURN_FAILED_BOOK_HAS_BEEN_BORROWED, "ERROR: Cannot borrow or return book - book has been borrowed.") \
    X(BOOK_BORROW_RETURN_FAILED_USER_LIMITED, "ERROR: Cannot borrow or return book - user has been limited borrow 10 book.") \
    X(BOOK_BORROW_OK, "Borrow book successfully.") \
    X(BOOK_BORROW_RETURN_FAILED_BOOK_EXISTED, "ERROR: Cannot borrow or return book - book has been returned.") \
    X(BOOK_BORROW_RETURN_FAILED_USER_NOT_BORROW, "ERROR: Cannot borrow or return book - user dont borrow this book.") \
    X(BOOK_BORROW_RETURN_FAILED_UNKNOWN_MODE, "Error: Unknown the error when borrowing or return book.") \
    X(BOOK_RETURN_OK, "Return book successfully.") \
    X(BOOK_SERCH_NOT_FOUND, "Error: Serach book not found.") \
    X(BOOK_SERCH_OK, "") \
    X(BOOK_BORROWED_SHOW_NOT_FOUND, "ERROR: There is no book borrowed.") \
    X(BOOK_BORROWED_SHOW_OK, "")

typedef enum {
#define X(code, msg) code,
    BOOK_ERROR_LIST(X)
#undef X
    BOOK_ERROR_COUNT
} BookRetCode_t;

typedef struct {
    int id;
    char title[MAX_LEN_TITLE];
    char author[MAX_LEN_NAME_AUTHOR];
    int isBorrowed;     /* 0: available, 1: borrowed */
} Book_t;

/**
 * @brief   Adds a new book to the library.
 * @param   books The array of books in the library.
 * @param   n Pointer to the current number of books in the library. This will be updated if the book is added successfully.
 * @return  BookRetCode_t indicating the result of the operation.
 *
 * @details  This function inserts a new book entry into the library system.
 *           Return BOOK_SUCCESS_ADD if the book is added successfully,
 *           or BOOK_ADD_FAILED_FULL if the library storage is full.
 */
BookRetCode_t addBook(Book_t books[], int *n);

/**
 * @brief   Updates information of an existing book in the library.
 * @param   books The array of books in the library.
 * @param   n The current number of books in the library.
 * @return  BookRetCode_t indicating the result of the operation.
 *
 * @details  This function allows updating the title and author of a book identified by its ID. It checks if the book exists before attempting to edit it.
 *           Return BOOK_SUCCESS_EDIT if the book information is updated successfully,
 *           or BOOK_EDIT_FAILED_NOT_FOUND if the book is not found in the library.
 */
BookRetCode_t editBook(Book_t books[], int n);

/**
 * @brief   Removes a book record from the library.
 * @param   books The array of books in the library.
 * @param   n Pointer to the current number of books in the library. This will be updated if the book is deleted successfully.
 * @return  BookRetCode_t indicating the result of the operation.
 *
 * @details  This function removes a book entry from the library system based on its ID. It checks if the book exists and is not currently borrowed before deletion.
 *           Return BOOK_SUCCESS_DELETE if the book is deleted successfully,
 *           BOOK_DELETE_FAILED_NOT_FOUND if the book is not found,
 *           or BOOK_DELETE_FAILED_BORROWED if the book is currently borrowed.
 */
BookRetCode_t deleteBook(Book_t books[], int *n);

/**
 * @brief   Borrows or returns a book from/to the library.
 * @param   books The array of books in the library.
 * @param   countBook The current number of books in the library.
 * @param   countUser The current number of users in the system.
 * @param   userId The ID of the user borrowing or returning the book.
 * @param   isBorrow The operation mode (BORROW_BOOK or RETURN_BOOK).
 * @return  BookRetCode_t indicating the result of the operation.
 *
 * @details  This function handles both borrowing and returning of books. It checks if the user and book exist, and whether the book is currently borrowed or not based on the mode of operation.
 *           Return appropriate error codes for various failure scenarios, such as user not found, book not found, book already borrowed, user borrow limit exceeded, etc. Return BOOK_BORROW_OK or BOOK_RETURN_OK for successful operations.
 */
BookRetCode_t borrowOrReturnBook(Book_t books[], int countBook, User_t  users[], int countUser, int isBorrow);

/**
 * @brief   Show a message for a given book return code.
 * @param   code Code defined in BookRetCode_t.
 * @return  void.
 */
const char* bookRetCodeToString(BookRetCode_t code);

#endif /* BOOK_H */