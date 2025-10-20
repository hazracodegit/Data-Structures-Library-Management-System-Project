# Data-Structures-Library-Management-System-Project
The Library Management System(LMS) is a simple data structures project implemented in the C programming Language using a Single Linked List (SLL).


📚 Library Management System (C Project using Singly Linked List)

🧩 Overview

The Library Management System is a Data Structures project implemented in C using a Singly Linked List (SLL).
It manages a collection of books, allowing users to add, delete, borrow, return, search, and display books dynamically.

This project provides a clear demonstration of how linked lists can be used for dynamic data handling without using databases or arrays.


---

🎯 Features

✅ Add Book – Add a new book record with ID, title, and author.
✅ Display Books – Show all books available in the library.
✅ Search Book – Search a book by its ID.
✅ Delete Book – Remove a book record permanently.
✅ Borrow Book – Mark a book as borrowed (not available for others).
✅ Return Book – Mark a borrowed book as returned.
✅ Exit – Close the program safely.




---

⚙ Data Structure Used

This project uses a Singly Linked List (SLL) to store book details dynamically.
Each node represents one book and contains:

struct Node {
    int id;
    char title[50];
    char author[50];
    int isBorrowed;  // 0 = available, 1 = borrowed
    struct Node* next;
};

id → Unique book ID

title → Title of the book

author → Author name

isBorrowed → Status of the book (available or borrowed)

next → Pointer to the next node (book)



---

🧠 Core Operations

1️⃣ Add Book

Prompts user to enter ID, title, and author.

Dynamically creates a new node and inserts it at the end of the list.


2️⃣ Display Books

Traverses the linked list and displays all book details.

Shows whether each book is Available or Borrowed.


3️⃣ Search Book

Searches a book by its unique ID.

Displays full book details if found.


4️⃣ Delete Book

Deletes a book record from the linked list by ID.

Frees the memory using free() to avoid memory leaks.


5️⃣ Borrow Book

Allows a user to borrow a book if it is available.

Changes the isBorrowed flag to 1 and marks it as “Borrowed”.


6️⃣ Return Book

Marks a borrowed book as returned.

Updates isBorrowed flag back to 0.


7️⃣ Exit

Terminates the program safely and frees all dynamically allocated memory.



---

🧮 Algorithms Used

Operation	Algorithm Summary

Insert	Traverse till last node → link new node at end
Search	Traverse and compare IDs until found
Delete	Locate node before target → adjust pointer links
Borrow/Return	Traverse → find by ID → change status flag
Display	Traverse → print all node data



---

🖥 Sample Menu

========= 📚 LIBRARY MANAGEMENT SYSTEM =========
1. Add Book
2. Display Books
3. Search Book
4. Borrow Book
5. Return Book
6. Delete Book
7. Exit
Enter your choice:


---

💾 Example Output

Enter your choice: 1
Enter Book ID: 101
Enter Title: Data Structures in C
Enter Author: Yashwanth Kanetkar
✅ Book added successfully!

Enter your choice: 4
Enter Book ID to borrow: 101
📖 Book borrowed successfully!

Enter your choice: 2
ID: 101
Title: Data Structures in C
Author: Yaswanth Kanetkar
Status: Borrowed


---

🧰 Tools Used

Language: C

Compiler: GCC

IDE : Dev C++

Concepts Used: Structures, Pointers, Dynamic Memory Allocation, Singly Linked List



---



🚀 Future Enhancements

Add File Handling to store records permanently.

Add Sorting (by title, author, or ID).

Add User Accounts and Fine Calculation for overdue returns.

Add Graphical Interface or building using Web Stack.



---

🧾 Conclusion

This Library Management System demonstrates how Singly Linked Lists can be used to manage real-life data dynamically.
It helps to understand:

Linked List traversal

Dynamic memory allocation

Node insertion, deletion, and modification

Real-world data handling using data structures


This project is ideal for beginners learning C programming and Data Structures.


