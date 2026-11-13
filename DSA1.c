#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    int Book_ID;
    char Title[100];
    char Author[100];
    float Price;
    char Status[10];
};

struct Book *books = NULL;
int N = 0;

void create()
{
    int i;

    printf("Enter number of books: ");
    scanf("%d", &N);

    books = (struct Book *)malloc(N * sizeof(struct Book));

    if (books == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    for (i = 0; i < N; i++)
    {
        printf("\nEnter details of Book %d\n", i + 1);

        printf("Book ID: ");
        scanf("%d", &books[i].Book_ID);

        printf("Title: ");
        scanf(" %s", books[i].Title);

        printf("Author: ");
        scanf(" %s", books[i].Author);

        printf("Price: ");
        scanf("%f", &books[i].Price);

        strcpy(books[i].Status, "Available");
    }

    printf("\nBook records created successfully!\n");
}

void display()
{
    int i;

    if (books == NULL)
    {
        printf("No book records available.\n");
        return;
    }

    printf("\n========== AVAILABLE BOOKS ==========\n");

    for (i = 0; i < N; i++)
    {
        if (strcmp(books[i].Status, "Available") == 0)
        {
            printf("\nBook ID   : %d", books[i].Book_ID);
            printf("\nTitle     : %s", books[i].Title);
            printf("\nAuthor    : %s", books[i].Author);
            printf("\nPrice     : %.2f", books[i].Price);
            printf("\nStatus    : %s\n", books[i].Status);
        }
    }
}

void search()
{
    int id, i, found = 0;

    if (books == NULL)
    {
        printf("No book records available.\n");
        return;
    }

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < N; i++)
    {
        if (books[i].Book_ID == id)
        {
            printf("\nBook Found!\n");
            printf("Book ID   : %d\n", books[i].Book_ID);
            printf("Title     : %s\n", books[i].Title);
            printf("Author    : %s\n", books[i].Author);
            printf("Price     : %.2f\n", books[i].Price);
            printf("Status    : %s\n", books[i].Status);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Book not found.\n");
    }
}

void issueBook()
{
    int id, i;

    if (books == NULL)
    {
        printf("No book records available.\n");
        return;
    }

    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < N; i++)
    {
        if (books[i].Book_ID == id)
        {
            if (strcmp(books[i].Status, "Available") == 0)
            {
                strcpy(books[i].Status, "Issued");
                printf("Book issued successfully.\n");
            }
            else
            {
                printf("Book is already issued.\n");
            }

            return;
        }
    }

    printf("Book not found.\n");
}

void returnBook()
{
    int id, i;

    if (books == NULL)
    {
        printf("No book records available.\n");
        return;
    }

    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < N; i++)
    {
        if (books[i].Book_ID == id)
        {
            if (strcmp(books[i].Status, "Issued") == 0)
            {
                strcpy(books[i].Status, "Available");
                printf("Book returned successfully.\n");
            }
            else
            {
                printf("Book is already available.\n");
            }

            return;
        }
    }

    printf("Book not found.\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n\n========== LIBRARY MENU ==========\n");
        printf("1. Add Book Records\n");
        printf("2. Display All Book Records\n");
        printf("3. Search Book by Book ID\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                free(books);
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
