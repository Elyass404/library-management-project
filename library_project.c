#include <stdio.h>
#include <string.h>


#define books_max 100


typedef struct {

char title[50];
char author[50];
float price;
int quantity;

} Book;


Book books_list[books_max];
int counter = 0;

void addBook(){

if (counter < books_max){
    printf("Please enter the title of the book: ");
    scanf(" %[^\n]%*c",&books_list[counter].title);
    printf("Please enter the name of the author: ");
    scanf(" %[^\n]%*c",&books_list[counter].author);
    printf("Please enter the price of the book: ");
    scanf("%f", &books_list[counter].price);
    printf("Please enter the quantity available of this book: ");
    scanf("%d", &books_list[counter].quantity);
    printf("Operation completed! you have registered \"%s\"",books_list[counter].title);
    counter ++;
}else{
    printf("the library is full of book, BAAAAARAKA!");
}
}

void showBooks(){
for(int i = 0; i < counter; i++){
    printf("the book N°%d:\n    Title: %s\n    Author: %s\n    Price: %.2f\n    Quantity: %d\n",i+1,books_list[i].title,books_list[i].author,books_list[i].price,books_list[i].quantity);
}
}

void searchingBook(){
char search_title[20];
int found =0;

printf("Please enter the title of the book you want: ");
scanf(" %[^\n]%*c",search_title);

for(int i = 0 ; i < counter; i++){
    if (strcmp(books_list[i].title,search_title) == 0){
        found = i+1 ;
    }
}
if(found != 0){
    printf("here is the book you are looking for:\n    Title: %s\n    Author: %s\n    Price: %.2f\n    Quantity: %d\n",books_list[found-1].title,books_list[found-1].author,books_list[found-1].price,books_list[found-1].quantity);
}else{
    printf("Sorry, the book you are looking for is unavailable!");
}
}

void updateBook(){
    char title_search[20];
    int  new_quantity;
    int found = 0 ;
    printf("Please enter the title of the book you want to update: ");
    scanf(" %[^\n]%*c",title_search);

    for (int i = 0 ; i < counter ; i++){
        if(strcmp(books_list[i].title, title_search)==0){
            found = i+1;
        }
    }
    if(found != 0){
        printf("Book found! Its current quantity is: %\n",books_list[found-1].quantity);
        printf("enter the new quantity value: ");
        scanf("%d",&new_quantity);
            books_list[found-1].quantity= new_quantity;
        printf("Operation completed! the book with title %s has the quantity of %d books",books_list[found-1].title, books_list[found-1].quantity);
    }else{
        printf("Sorry! The book your are looking for is unavailable.");
    }
}

void removebook(){
    char title_search[50];
    int found = 0;
    printf("Please enter the title of the book you want to remove: ");
    scanf(" %[^\n]",title_search);

   for(int i=0 ; i<counter ; i++){
        if(strcmp(books_list[i].title,title_search)==0){
            found =i+1;
            break;
        }
   }

   if(found!=0){
        for ( int j = found-1 ; j< counter; j++){
               strcpy(books_list[j].title,books_list[j+1].title) ;
               strcpy(books_list[j].author,books_list[j+1].author) ;
               books_list[j].price = books_list[j+1].price;
               books_list[j].quantity = books_list[j+1].quantity;
               counter--;
               printf("Operation completed! you have successfully removed the book named \"%s\"",title_search);
               break;
         }

    }else{
            printf("Sorry! the book you are looking for is unavailable.");
        }
}

void booksQuantity(){
    int quantity=0;
    for(int i = 0 ; i < counter; i++){
        quantity += books_list[i].quantity;
    }

printf("The quantity of books in the library is: %d",quantity);

}


int main (){


int choice ;
Welcome_Menu:
printf("-------------------------------------\n");
printf("The Menu\n");
printf("please choose a number in the list bellow:\n");
printf("1- Add new book to the library.\n");
printf("2- Show all books from the library.\n");
printf("3- Search for a book from the library.\n");
printf("4- Update existed book in the library.\n");
printf("5- Remove a book from the library.\n");
printf("6- Check the quantity of all books in the library.\n");
printf("Enter the number here: ");

scanf("%d",&choice);

switch(choice){
case 1 :
    addBook();
    goto Welcome_Menu;
break;

case 2 :
    showBooks();
    goto Welcome_Menu;
break;

case 3 :
    searchingBook();
    goto Welcome_Menu;
break;

case 4 :
    updateBook();
    goto Welcome_Menu;
break;

case 5 :
    removebook();
    goto Welcome_Menu;
break;

case 6 :
    booksQuantity();
    goto Welcome_Menu;
break;

}









return 0;
}
