#include <stdio.h>
#include "../Book/book.h"
#include "../User/user.h"
#include "../Ultils/ultils.h"


void manageLibrary()
{
    Book_t books[MAX_BOOKS];
    User_t users[MAX_USERS];

    int bookCount = 0;
    int userCount = 0;

    int mainChoice;

    while (1)
    {
        showMenu(MENU_MAIN);
        printf("Select an option: ");
        scanf("%d", &mainChoice);

        switch (mainChoice)
        {
        case 1:   // MANAGE BOOKS
        {
            int bookChoice;
            do
            {
                showMenu(MENU_BOOK);
                printf("Select an option: ");
                scanf("%d", &bookChoice);

                switch (bookChoice)
                {
                case 1:
                    addBook(books, &bookCount);
                    break;

                case 2:
                    editBook(books, bookCount);
                    break;

                case 3:
                    deleteBook(books, &bookCount);
                    break;

                case 4:
                    borrowOrReturnBook(books, bookCount, users, userCount, 1);
                    break;

                case 5:
                    showBooks(books, bookCount);
                    break;

                case 6:
                    searchBook(books, bookCount);
                    break;

                case 7:
                    printf("Returning to Main Menu...\n");
                    break;

                default:
                    printf("Invalid choice!\n");
                }

            } while (bookChoice != 7);
        }
        break;

        case 2:   // MANAGE USERS
        {
            int userChoice;
            do
            {
                showMenu(MENU_USER);
                printf("Select an option: ");
                scanf("%d", &userChoice);

                switch (userChoice)
                {
                case 1:
                    addUser(users, &userCount);
                    break;

                case 2:
                    editUser(users, userCount);
                    break;

                case 3:
                    deleteUser(users, &userCount);
                    break;

                case 4:
                    showUsers(users, userCount);
                    break;

                case 5:
                    searchUser(users, userCount);
                    break;

                case 6:
                    printf("Returning to Main Menu...\n");
                    break;

                default:
                    printf("Invalid choice!\n");
                }

            } while (userChoice != 6);
        }
        break;

        case 3:   // EXIT (đúng theo menu bạn in)
            printf("Exiting program...\n");
            return;

        default:
            printf("Invalid choice!\n");
        }
    }
}