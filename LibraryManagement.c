#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void removeBookAtBeginning();
void removeBookAtEnd();
void removeBookAtPosition();
void countBooks();
struct Book{
	int id;
	char title[20];
	char author[20];
	int isBorrowed; // 0 for Other(not borrowed) and 1 for borrowed
	struct Book *next;
};
struct Book *head=NULL;
int count=0;

// Create Book Function
struct Book * createBook(){
	struct Book * newBook=(struct Book *)malloc(sizeof(struct Book));
	if (newBook==NULL){
		printf("\nHeap Memory is Full\n");
		return;
	}
	int bookId;
	char bookTitle[20];
	char bookAuthor[20];
	printf("Enter the id of the Book: ");
	scanf("%d",&bookId);
	printf("Enter the Title of the Book: ");
	scanf(" %[^\n]",bookTitle);
	strcpy(newBook->title,bookTitle);
	printf("Enter the Author of the Book: ");
	scanf(" %[^\n]",bookAuthor);
	strcpy(newBook->author,bookAuthor);
	newBook->id=bookId;
	newBook->isBorrowed=0;
	newBook->next=NULL;
	return newBook;
}

// Create Book List Function
void createBookList(){
	int n,i;
	printf("Enter the number of books: ");
	scanf("%d",&n);
	struct Book *temp,*newBook;
	for(i=1;i<=n;i++){
		newBook=createBook();
		if (head==NULL){
			head=newBook;
			temp=head;
		}
		else{
			temp->next=newBook;
			temp=newBook;
		}
	}
	printf("\nBooks List is Successfully Created!!!\n");
}

// Add Book Function
void addBook(){
	struct Book *newBook=createBook();
	newBook->next=NULL;
	head=newBook;
	printf("\nBook is added Successfully into the Library!!!\n");
}

// Remove Book Function
void removeBook(){
	struct Book *temp=head;
	int id;
	printf("Enter the id of the Book you want to remove: ");
	scanf("%d",&id);
	int position=1;
	while(temp!=NULL){
		if (temp->id==id){
			break;
		}
		position=position+1;
		temp=temp->next;
	}
	countBooks();
	if (position==1){
		removeBookAtBeginning();
	}
	else if (position==count){
		removeBookAtEnd();
	}
	else{
		removeBookAtPosition(position);
	}	
}

// Remove Book At Beginning Function
void removeBookAtBeginning(){
	struct Book *temp=head;
	head=head->next;
	free(temp);
	
}

// Remove Book At End Function
void removeBookAtEnd(){
	struct Book *temp=head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	free(temp->next);
}

// Remove Book At Specific Position
void removeBookAtPosition(int position){
	struct Book *temp=head;
	int i;
	for(i=1;i<position-1&&temp!=NULL;i++){
		temp=temp->next;
	}
	temp->next=temp->next->next;
	free(temp->next);
}

// Display all the Available Books in the Library
void displayBooks(){
	int books=1;
	if (head==NULL){
		printf("\nLibrary is Empty!!!\n");
		return;
	}
	struct Book *temp=head;
	printf("\nLibrary Books: \n");
	while(temp!=NULL){
		printf("\nBook %d :",books);
		printf("\nID     : %d",temp->id);
		printf("\nTitle  : %s",temp->title);
		printf("\nAuthor : %s",temp->author);
		if (temp->isBorrowed==1)
		printf("\nStatus : Borrowed");
		else if (temp->isBorrowed==-1)
		printf("\nStatus : Returned");
		else
		printf("\nStatus : None");
		books=books+1;
		temp=temp->next;
	}
}

// Return the Book Function
void returnBook(){
	int id;
	printf("Enter the id of the Book you want to Return: ");
	scanf("%d",&id);
	struct Book *temp=head;
	while(temp!=NULL){
		if (temp->id==id){
			if (temp->isBorrowed==1){
			    temp->isBorrowed=-1;
			    printf("\nBook with id %d is Successfully Returned!!! \n",id);
				break;
			}
			else{
				printf("\nBook with id %d is already Available in the Library!!!\n");
				break;
			}
		}
	}
}

// Borrow the Book Function
void borrowBook(){
	int id;
	printf("Enter the id of the Book you want to Borrow: ");
	scanf("%d",&id);
	struct Book *temp=head;
	while(temp!=NULL){
		if (temp->id==id){
			if (temp->isBorrowed==0){
			    temp->isBorrowed=1;
			    printf("\nBook with id %d is Successfully Borrowed!!!\n",id);
			    break;
			}
			else{
				printf("\n Sorry , Book with id %d is already Borrowed!!!",id);
				break;
			}
		}
	}
}

// Number of Books in the Linked List
void countBooks(){
	struct Book *temp=head;
	while(temp!=NULL){
		count=count+1;
		temp=temp->next;
	}
}

int main(){
	int choice;
	while(1){
		printf("\n=====================Library Management System======================\n");
		printf("1.Create Books List Operation\n");
		printf("2.Add Book into Library\n");
		printf("3.Remove Book from the Library\n");
		printf("4.Return Book to the Library\n");
		printf("5.Borrow Book from the Library\n");
		printf("6.Display all the Books Available in the Library\n");
		printf("7.Exit\n");
		printf("=======================================================================\n");
		printf("Enter your choice from the above menu Options: ");
		scanf("%d",&choice);
		if (choice==1)
		createBookList();
		else if (choice==2)
		addBook();
		else if (choice==3)
		removeBook();
		else if (choice==4)
		returnBook();
		else if (choice==5)
		borrowBook();
		else if (choice==6)
		displayBooks();
		else
		return 0;	
	}
}


