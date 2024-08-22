// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Define a structure to represent a book record
// struct Book {
//     int book_id;
//     char title[100];
//     char author[100];
//     char publication_date[20];
//     char genre[50];
//     char ISBN[20];
//     int quantity_available;
// };

// // Function to print the table header
// void printTableHeader() {
//     printf("%-8s %-50s %-30s %-20s %-15s %-20s %-10s\n", 
//            "Book ID", "Title", "Author", "Publication Date", "Genre", "ISBN", "Quantity");
//     printf("--------------------------------------------------------------------------------\n");
// }

// // Function to print a single book record
// void printBook(struct Book book) {
//     printf("%-8d %-50s %-30s %-20s %-15s %-20s %-10d\n", 
//            book.book_id, book.title, book.author, book.publication_date, 
//            book.genre, book.ISBN, book.quantity_available);
// }

// // Function to simulate SELECT * from table_name
// void selectAll(struct Book *books, int num_books) {
//     printTableHeader();
//     for (int i = 0; i < num_books; ++i) {
//         printBook(books[i]);
//     }
// }

// // Function to simulate SELECT * from table_name where some_condition
// void selectWithCondition(struct Book *books, int num_books, char *condition) {
//     printTableHeader();
//     for (int i = 0; i < num_books; ++i) {
//         // Example: Implement filtering based on condition
//         // For simplicity, let's assume the condition is based on book genre
//         if (strcmp(books[i].genre, condition) == 0) {
//             printBook(books[i]);
//         }
//     }
// }

// // Function to simulate SELECT {some_subset_of _attributes} from table_name
// void selectSubset(struct Book *books, int num_books, char *attributes) {
//     printTableHeader();
//     // Parse the attributes string to determine which fields to display
//     // For simplicity, let's assume the attributes are separated by commas
//     char *token = strtok(attributes, ",");
//     while (token != NULL) {
//         // Implement logic to print only the specified attributes
//         // For simplicity, let's print all attributes
//         printf("%s\t", token);
//         token = strtok(NULL, ",");
//     }
//     printf("\n");
//     printf("--------------------------------------------------------------------------------\n");
//     for (int i = 0; i < num_books; ++i) {
//         // Implement logic to print only the specified attributes
//         // For simplicity, let's print all attributes
//         printBook(books[i]);
//     }
// }

// int main(int argc, char *argv[]) {
//     // Create an array of book records (assuming at least 10 records)
//     struct Book books[10] = {
//         {1, "Book1", "Author1", "01-01-2020", "Fiction", "1234567890", 5},
//         {2, "Book2", "Author2", "02-02-2020", "Non-Fiction", "0987654321", 3},
//         {3, "Book3", "Author3", "03-03-2020", "Fantasy", "1112223334", 7},
//         {4, "Book4", "Author4", "04-04-2020", "Science Fiction", "4445556667", 2},
//         {5, "Book5", "Author5", "05-05-2020", "Mystery", "7778889990", 0},
//         {6, "Book6", "Author6", "06-06-2020", "Thriller", "1110002223", 8},
//         {7, "Book7", "Author7", "07-07-2020", "Romance", "6665554443", 4},
//         {8, "Book8", "Author8", "08-08-2020", "Biography", "3332221110", 6},
//         {9, "Book9", "Author9", "09-09-2020", "Historical Fiction", "0009998887", 1},
//         {10, "Book10", "Author10", "10-10-2020", "Self-Help", "8887776665", 10}
//     };

//     int num_books = 10;

//     // Check for the number of arguments provided
//     if (argc < 3) {
//         printf("Usage: %s <select_command> <condition/attributes>\n", argv[0]);
//         return 1;
//     }

//     // Parse the select command and execute the corresponding function
//     if (strcmp(argv[1], "SELECT * from table_name") == 0) {
//         selectAll(books, num_books);
//     } else if (strstr(argv[1], "SELECT * from table_name where") != NULL) {
//         selectWithCondition(books, num_books, argv[2]);
//     } else if (strstr(argv[1], "SELECT") != NULL) {
//         selectSubset(books, num_books, argv[2]);
//     } else {
//         printf("Invalid SELECT command\n");
//         return 1;
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Define a structure to represent a book record
// struct Book {
//     int book_id;
//     char title[100];
//     char author[100];
//     char publication_date[20];
//     char genre[50];
//     char ISBN[20];
//     int quantity_available;
// };

// // Function to print the table header
// void printTableHeader() {
//     printf("%-50s %-30s %-15s\n", "Title", "Author", "Genre");
//     printf("--------------------------------------------------------------------------------\n");
// }

// // Function to print a single book record with selected attributes
// void printSelectedAttributes(struct Book book) {
//     printf("%-50s %-30s %-15s\n", book.title, book.author, book.genre);
// }

// // Function to simulate SELECT * from table_name
// void selectAll(struct Book *books, int num_books) {
//     printTableHeader();
//     for (int i = 0; i < num_books; ++i) {
//         printSelectedAttributes(books[i]);
//     }
// }

// // Function to simulate SELECT * from table_name where some_condition
// void selectWithCondition(struct Book *books, int num_books, char *condition) {
//     printTableHeader();
//     // For simplicity, let's assume the condition is based on book genre
//     for (int i = 0; i < num_books; ++i) {
//         if (strcmp(books[i].genre, condition) == 0) {
//             printSelectedAttributes(books[i]);
//         }
//     }
// }

// int main(int argc, char *argv[]) {
//     // Create an array of book records (assuming at least 10 records)
//     struct Book books[10] = {
//         {1, "Book1", "Author1", "01-01-2020", "Fiction", "1234567890", 5},
//         {2, "Book2", "Author2", "02-02-2020", "Non-Fiction", "0987654321", 3},
//         {3, "Book3", "Author3", "03-03-2020", "Fantasy", "1112223334", 7},
//         {4, "Book4", "Author4", "04-04-2020", "Science Fiction", "4445556667", 2},
//         {5, "Book5", "Author5", "05-05-2020", "Mystery", "7778889990", 0},
//         {6, "Book6", "Author6", "06-06-2020", "Thriller", "1110002223", 8},
//         {7, "Book7", "Author7", "07-07-2020", "Romance", "6665554443", 4},
//         {8, "Book8", "Author8", "08-08-2020", "Biography", "3332221110", 6},
//         {9, "Book9", "Author9", "09-09-2020", "Historical Fiction", "0009998887", 1},
//         {10, "Book10", "Author10", "10-10-2020", "Self-Help", "8887776665", 10}
//     };

//     int num_books = 10;

//     // Check for the number of arguments provided
//     if (argc < 3) {
//         printf("Usage: %s <select_command> <condition/attributes>\n", argv[0]);
//         return 1;
//     }

//     // Parse the select command and execute the corresponding function
//     if (strcmp(argv[1], "SELECT * from table_name") == 0) {
//         selectAll(books, num_books);
//     } else if (strstr(argv[1], "SELECT * from table_name where") != NULL) {
//         selectWithCondition(books, num_books, argv[2]);
//     } else if (strstr(argv[1], "SELECT") != NULL) {
//         // Split the attributes to get the subset of attributes
//         char *token = strtok(argv[1], " ");
//         while (token != NULL) {
//             if (strcmp(token, "SELECT") != 0 && strcmp(token, "from") != 0) {
//                 printf("%s\t", token);
//             }
//             token = strtok(NULL, " ");
//         }
//         printf("\n");
//         printf("--------------------------------------------------------------------------------\n");
//         for (int i = 0; i < num_books; ++i) {
//             printSelectedAttributes(books[i]);
//         }
//     } else {
//         printf("Invalid SELECT command\n");
//         return 1;
//     }

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Define a structure to represent a book record
// struct Book {
//     int book_id;
//     char title[100];
//     char author[100];
//     char publication_date[20];
//     char genre[50];
//     char ISBN[20];
//     int quantity_available;
// };

// // Function to print the table header
// void printTableHeader() {
//     printf("%-50s %-30s %-15s\n", "Title", "Author", "Genre");
//     printf("--------------------------------------------------------------------------------\n");
// }

// // Function to print a single book record with selected attributes
// void printSelectedAttributes(struct Book book) {
//     printf("%-50s %-30s %-15s\n", book.title, book.author, book.genre);
// }

// // Function to simulate SELECT * from table_name where some_condition
// void selectWithCondition(struct Book *books, int num_books, char *condition) {
//     printTableHeader();
//     // Extract the genre condition from the SELECT command
//     char genre_condition[50];
//     sscanf(condition, "genre=%s", genre_condition);
//     // For simplicity, let's assume the condition is based on book genre
//     for (int i = 0; i < num_books; ++i) {
//         if (strcmp(books[i].genre, genre_condition) == 0) {
//             printSelectedAttributes(books[i]);
//         }
//     }
// }

// int main(int argc, char *argv[]) {
//     // Create an array of book records (assuming at least 10 records)
//     struct Book books[10] = {
//         {1, "Book1", "Author1", "01-01-2020", "Fiction", "1234567890", 5},
//         {2, "Book2", "Author2", "02-02-2020", "Non-Fiction", "0987654321", 3},
//         {3, "Book3", "Author3", "03-03-2020", "Fantasy", "1112223334", 7},
//         {4, "Book4", "Author4", "04-04-2020", "Science Fiction", "4445556667", 2},
//         {5, "Book5", "Author5", "05-05-2020", "Mystery", "7778889990", 0},
//         {6, "Book6", "Author6", "06-06-2020", "Thriller", "1110002223", 8},
//         {7, "Book7", "Author7", "07-07-2020", "Romance", "6665554443", 4},
//         {8, "Book8", "Author8", "08-08-2020", "Biography", "3332221110", 6},
//         {9, "Book9", "Author9", "09-09-2020", "Historical Fiction", "0009998887", 1},
//         {10, "Book10", "Author10", "10-10-2020", "Self-Help", "8887776665", 10}
//     };

//     int num_books = 10;

//     // Check for the number of arguments provided
//     if (argc != 2 || strstr(argv[1], "SELECT * from table_name where genre=") == NULL) {
//         printf("Usage: %s \"SELECT * from table_name where genre=<genre>\"\n", argv[0]);
//         return 1;
//     }

//     // Parse the select command and execute the corresponding function
//     selectWithCondition(books, num_books, argv[1]);

//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a book record
struct Book {
    int book_id;
    char title[100];
    char author[100];
    char publication_date[20];
    char genre[50];
    char ISBN[20];
    int quantity_available;
};

// Function to print the table header
void printTableHeader() {
    printf("%-50s %-30s %-15s\n", "Title", "Author", "Genre");
    printf("--------------------------------------------------------------------------------\n");
}

// Function to print a single book record with selected attributes
void printSelectedAttributes(struct Book book) {
    printf("%-50s %-30s %-15s\n", book.title, book.author, book.genre);
}

// Function to simulate SELECT * from table_name where some_condition
void selectWithCondition(struct Book *books, int num_books, char *condition) {
    printTableHeader();
    // Extract the genre condition from the SELECT command
    char *genre_condition = strstr(condition, "genre=");
    if (genre_condition == NULL) {
        printf("Invalid SELECT command.\n");
        return;
    }
    genre_condition += strlen("genre=");

    // Remove surrounding quotes if present
    if (genre_condition[0] == '"') {
        genre_condition++;
        genre_condition[strlen(genre_condition) - 1] = '\0';
    }

    // For simplicity, let's assume the condition is based on book genre
    for (int i = 0; i < num_books; ++i) {
        if (strcmp(books[i].genre, genre_condition) == 0) {
            printSelectedAttributes(books[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    // Create an array of book records (assuming at least 10 records)
    struct Book books[10] = {
        {1, "Book1", "Author1", "01-01-2020", "Fiction", "1234567890", 5},
        {2, "Book2", "Author2", "02-02-2020", "Non-Fiction", "0987654321", 3},
        {3, "Book3", "Author3", "03-03-2020", "Fantasy", "1112223334", 7},
        {4, "Book4", "Author4", "04-04-2020", "Science Fiction", "4445556667", 2},
        {5, "Book5", "Author5", "05-05-2020", "Mystery", "7778889990", 0},
        {6, "Book6", "Author6", "06-06-2020", "Thriller", "1110002223", 8},
        {7, "Book7", "Author7", "07-07-2020", "Romance", "6665554443", 4},
        {8, "Book8", "Author8", "08-08-2020", "Biography", "3332221110", 6},
        {9, "Book9", "Author9", "09-09-2020", "Historical Fiction", "0009998887", 1},
        {10, "Book10", "Author10", "10-10-2020", "Self-Help", "8887776665", 10}
    };

    int num_books = 10;

    // Check for the number of arguments provided
    if (argc != 2 || strstr(argv[1], "SELECT * from table_name where genre=") == NULL) {
        printf("Usage: %s \"SELECT * from table_name where genre=<genre>\"\n", argv[0]);
        return 1;
    }

    // Parse the select command and execute the corresponding function
    selectWithCondition(books, num_books, argv[1]);

    return 0;
}
