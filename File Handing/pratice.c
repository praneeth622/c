#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct transaction {
    int transaction_ID;
    char transaction_date[20];
    int book_ID;
    bool is_return;
};
struct book{
    int book_ID;
    char date[6];
    char title[20];
    char author[20];
    char publication_date[20];
    char gener[20];
    int ISBN;
    int quntity;
};

void create_book(){
    struct book newbook;

    printf("Enter the book name :");
    scanf("%s",newbook.title);
    
    printf("Enter the book id :");
    scanf("%d",&newbook.book_ID);
    
    printf("Enter the book author name :");
    scanf("%s",newbook.author);
    
    printf("Enter the date :");
    scanf("%s",newbook.date);
    
    printf("Enter the publication date :");
    scanf("%s",newbook.publication_date);
    
    printf("Enter the gener:");
    scanf("%s",newbook.gener);
    
    printf("Enter the quntity :");
    scanf("%d",&newbook.quntity);

    printf("Enter the book ISBN :");
    scanf("%d",&newbook.ISBN);
    

    FILE* fptr;
    fptr = fopen("database.txt", "ab");

    if (fptr == NULL) {
		printf("The file is not opened. The program will "
			"exit now");
		exit(0);
	}
    else{
        fwrite(&newbook,sizeof(struct book),1,fptr);}
        fclose(fptr);
    printf("Book added Sucessfully");
    
}

void borrow_book(){
    struct book b;
    struct transaction t;
    FILE* fptr = fopen("database.txt", "rb");
    FILE* tfile = fopen("transactions.txt", "ab");
    
    if(fptr == NULL || tfile == NULL){
        printf("Unable to open file \n");
    }
    
    int find;
    printf("Enter the book ID to Borrow \n");
    scanf("%d",&find);
    
    while(fread(&b, sizeof(struct book), 1, fptr)==1){
        if(b.book_ID == find || b.quntity > 0){
            printf("Book Found and copies are avalibale for borrow");
            b.quntity--;
            
            t.transaction_ID = rand();
            t.book_ID = b.book_ID;
            printf("Enter the transation date : ");
            scanf("%s",t.transaction_date);
            t.is_return = false;
            
            fseek(fptr, -sizeof(struct book), SEEK_CUR);
            fwrite(&b,sizeof(struct book) , 1, fptr);
            fwrite(&t, sizeof(struct transaction),1, tfile);
            
            fclose(tfile);
            fclose(fptr);
            return;
        }
        else if(b.book_ID == find || b.quntity == 0) {
            printf("Book is found but stock not avalible ");
            return;
        }
        else{
            printf("Book not found");
        }
    }
    fclose(fptr);
    fclose(tfile);
}

int update_book(){
    struct book b;
    int find1;
    FILE *fptr = fopen("database.txt", "rb+");

    if (fptr == NULL) {
		printf("The file is not opened. The program will "
			"exit now");
		exit(0);
	}
    printf("Enter the Book ID : \n");
    scanf("%d",&find1);

    while (fread(&b, sizeof(struct book), 1, fptr) == 1) {
        if (b.book_ID == find1) {
            printf("Enter the new book name: ");
            scanf("%s", b.title);

            printf("Enter the new book author name: ");
            scanf("%s", b.author);

            printf("Enter the date :");
            scanf("%s",b.date);
            
            printf("Enter the publication date :");
            scanf("%s",b.publication_date);
            
            printf("Enter the gener:");
            scanf("%s",b.gener);
            
            printf("Enter the quntity :");
            scanf("%d",&b.quntity);
        
            printf("Enter the book ISBN :");
            scanf("%d",&b.ISBN);
    

            // Move the file pointer back to the beginning of the record
            fseek(fptr, -sizeof(struct book), SEEK_CUR);

            // Write the updated record back to the file
            fwrite(&b, sizeof(struct book), 1, fptr);

            fclose(fptr);  // Close the file after updating
            return 1;      // Return 1 to indicate success
        }
    }
    return 0;
}

int delete_book(){
    struct book b;
    int find;
    FILE *fptr = fopen("database.txt", "rb+");
    FILE *tempfile = fopen("temp.txt", "wb");
    
    if(fptr == NULL || tempfile == NULL){
        printf("File cant open");
    }
    printf("Enter the Book ID you want to delete \n");
    scanf ("%d",&find);
    
    while(fread(&b,sizeof(struct book),1,fptr) == 1){
        if(b.book_ID == find){
            printf("The is deleted Successfully \n");
        }
        else{
            fwrite(&b, sizeof(struct book),1,tempfile);
        }
        
    }
    
    fclose(tempfile);
    fclose(fptr);
    
    remove("database.txt");
    rename("temp.txt", "database.txt");
    
    return 0;
}

int display() {
    struct book b;
    FILE *fptr = fopen("database.txt", "rb");

    if (fptr == NULL) {
        printf("Unable to open file");
        exit(0);
    }
    
    fseek(fptr, 0, SEEK_END);
    if (ftell(fptr) == 0) {
        printf("No books in the database.\n");
        fclose(fptr);
        return 0;
    }
     rewind(fptr);

    printf("Fetching Details... \n");
    while (fread(&b, sizeof(struct book), 1, fptr) == 1) {
        printf("Book Id : %-20d", b.book_ID);
        printf("Book Title : %-8s", b.title);
        printf("Book Author : %-10s", b.author);
        printf("Book Quantity : %-20d", b.quntity);
        printf("Book ISBN Number : %-20d", b.ISBN);
        printf("Book Published date : %-20s", b.publication_date);
        printf("\n");
    }
    fclose(fptr);
    return 0;
}

int find_book(){
    struct book b;
    int find,found=0;
    FILE *fptr = fopen("database.txt", "rb+");

    if (fptr == NULL) {
		printf("The file is not opened. The program will "
			"exit now \n");
		exit(0);
	}
	
	printf("Enter the book ID : \n");
	scanf("%d",&find);
	
	
	
	while(fread(&b, sizeof(struct book), 1, fptr) == 1){
	    if(b.book_ID == find){
            found =1;
	        printf("Book Found");
	        printf("Book Id : %-20d", b.book_ID);
            printf("Book Title : %-20s", b.title);
            printf("Book Author : %-20s", b.author);
            printf("Book Quantity : %-20d", b.quntity);  
            printf("Book ISBN Number : %-20d", b.ISBN);   
            printf("Book Published date : %-20s", b.publication_date);
            printf("\n"); 
	        
	        fclose(fptr); 
            return 0;
	    }
	    else{
	        printf("Book Not found in record, Try to create new book record \n");
	    }
	    fclose(fptr); 
	}

    if (!found) {
        printf("No books found with the given ID\n");
    }
    return 0;
}

int main()
{
    FILE* fptr;
    // char bname[20];

	// printf("Enter the book name: ");
    // scanf("%s", bname);
	fptr = fopen("database.txt", "wb");
    
    while(1){
    int choice;

    printf("\nEnter the option \n");
    printf("1. Create a book \n");
    printf("2. Update Record \n");
    printf("3. Find Book \n");
    printf("4. Display database \n");
    printf("5. Remove book \n");
    printf("6. Show Transtions \n");
    scanf("%d",&choice);
    switch(choice){
        case 1:{
            create_book();
            break;
        }
        case 2 :{
            update_book();
            break;
        }
        case 3:{
            find_book();
            break;
        }
        case 4:{
            display();
            break;
        }
        case 5:{
            delete_book();
            break;
        }
        case 6:{
            borrow_book();
            break;
        }
        default: {
        printf("Invalid option\n");
        break;
        }
    }
    }
	
    return 0;
}