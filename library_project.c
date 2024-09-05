#include <stdio.h>
void addBook(){
printf("you are adding a new book");
}

void showBooks(){
printf("you are showing the books a new book");
}

void searchingBook(){
printf("you are searching a new book");
}

void updateBook(){
printf("you are updating a new book");
}

void removebook(){
printf("you are removing book");

}

void quantityupdate(){
printf("you are updating quantity book");

}


int main (){

int choice ;

printf("The Menu\n");
printf("please choose a number in the list bellow");
printf("1- add new book to the library.\n");
printf("2- show all books from the library.\n");
printf("3- search for a book from the library.\n");
printf("4- update existed book in the library.\n");
printf("5- remove a book to the library.\n");
printf("6- quantity check of a book in the library.\.");

scanf("%d",&choice);

switch(choice){
case 1 :
    addBook();
break;

case 2 :
    showBooks();
break;

case 3 :
    searchingBook();
break;

case 4 :
    updateBook();
break;

case 5 :
    removebook();
break;

case 6 :
    quantityupdate();
break;

}









return 0;
}
