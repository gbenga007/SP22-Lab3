# Lab 3: Constructing Singly Linked Lists using C++ Classes
For your lab this week, you will be constructing a singly linked list using a C++ class. This lab will serve as a soft introduction to programming in C++. Your task is to implement something similar to what you did for Lab2 (perhaps even simpler, since it'll be a singly linked list instead of a doubly linked list) however, you will be using a C++ class object for your linked list nodes.


# Preliminaries 
## A short primer on Singly Linked Lists
```c++
class Node{
  public : 
        std::string  Name;
		    float         GPA;
		    int Total credits;
        Node* next;
        Node()
        {}
        Node(std::string fileName) 
        {}

};

```



## File I/O in C++
Consult the ifstream and ofstream classes for C++ File I/O 
A doubly linked list is a linked list that contains a previous and a next pointer. In this assignment, the head is a dummy node and its previous pointer should be null. The tail is not a dummy node, but its next pointer is null.
<br>
<br>
<img src="doublylinked.svg">
<br>
We will work through insertion during the lab.


# Instructions
- You are given an empty repository with this readme. 
- Make commits as often as necessary, with self-contained bits of code rather than large blobs. ***You do not need to push after each commit.***
- **Read and internalize the warnings.**
- Itemized directions are below. You may not have to do them in order.

1. Read and internalize the warnings.
2. Create a `main.cpp` OR `main.cc` file. The C++ compiler recognizes either extension for Cplusplus source code files.
	- Include the `argc` and `argv` arguments. For this assignment, you will be reading the node data from a text file. Use the command line args to pass in the file.  
	- Hard code 10 students to use in your doubly linked list.
3. Create a header and implementation file for a studentList. 
	- Implement doubly linked list methods for students.
	- Create the actual doubly linked list in `main`.
	- Use a struct to contain the data necessary for a student.
		- Name
		- GPA
		- Total credits
	- Use a struct to contain the data necessary for a student node in a doubly linked list.
		- Student
		- next
		- prev
	- Use a dummy `head` node. For index operations, treat the dummy head node as 0.
	- Your `tail` pointer should not be a dummy.
	- Implement the following operations. You will need to pass the head to these methods.
		1. Index at.
			- Specify an integer.
			- Return the student node at the given integer.
		2. Deletion by specifying the index, and handling the head, tail, or anything in between.
			- Specify an integer.
			- Delete the student node at the given integer.
			- Prove the student was deleted inside the method. You may achieve this with a `printf` statement.
		3. Deletion of all items in the list.
		4. Add at end by specifying a student struct.
		5. Insertion by specifying the index and student struct. This will not insert at the end.
			- Let head be the 0 index.
			- The given integer is where the new node will be.
			- Specify an integer and student struct.
			- Add the student at the given integer.
		6. Print student.
			- Specify an integer.
			- Use `printf` to print the student at the given index. 
			- Print in this format: 
			- ```Student Name: #####\nGPA: #####\nTotal credits: ####```
				- Replace the hashes with the actual data. *Please do not take this too literally.*
		7. Print all students.
4. Dynamically allocate students and nodes with `calloc`.
5. Read and internalize the warnings.
6. Test all of your functions in `main`.
7. Verify that you may give your program an integer argument to delete students from the doubly linked list. prove that it works.
8. Add error handling, such as if-else statements that use `printf` to write warnings to the console.
9. Don't use `malloc` for this assignment, since it may lead to memory issues that will reduce your grade.
10. Paste your terminal output from the assignment onto the end of this document.
		
		
# 🌟Bonus Points🌟
- **Read and internalize the warnings.** They apply to the bonus as well.
- Prove your functions work in main.
- Add error handling.

1. **10 points:** Add a function to reverse the linked list, do this by swapping the pointers **NOT** the data members of the node!
2. **10 points:** For this problem, consider a linked list as containing a non-negative integer. That is, each node in the list contains a single digit of the integer. For example, the number 9,326 can be stored in a linked list as l1 where l1: { 9->3->2->6 }. Your task is to perform an addition of two such non-negative integers and return the result as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself. Please ask question if this problem is unclear.


# Getting Started
Get your personal link and invoke `git clone {linkhere}`, which should be a combination of your username and the name of the lab.

# Compiling
The repository does not include a makefile, so you'll need to create your own. The instructors should be able to compile the code by invoking `make`. Additionally, `make clean` should remove all files that are not source code.


# Running
The instructors should be able to run the code by invoking the executable, `./linkedList`, or by running `make run`.

# <span style="color:red">Warning</span>
<span style="color:red">Failure to heed the following statements may result in lost points.</span>
- Valgrind will be used on your assignments and be a critera for grading.
- Do not push unneeded files, such as those created during compilation.
- It is advised to do the lab assignment first, and then any extra credit you want to attempt. Your submission's grade is much more dependent on the core instructions. 
- Do not use `malloc` in this assignment. Use C++'s `new` and `delete` keyword for heap memory management instead.
- Test all of your functions in `main`.
- Use some sort of error handling, such as if-else statements that use `std::cout` to write warnings to the console.
- Do not assume the number of items in your singly linked list.

Example valgrind output that would not result in a loss of points:
```
==18852== 
==18852== HEAP SUMMARY:
==18852==     in use at exit: 0 bytes in 0 blocks
==18852==   total heap usage: 24 allocs, 24 frees, 3,952 bytes allocated
==18852== 
==18852== All heap blocks were freed -- no leaks are possible
==18852== 
==18852== For counts of detected and suppressed errors, rerun with: -v
==18852== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Gitignore
All submissions must not include any extraneous files, which includes intermediate files used in compilation. One simple but tedious way to achieve this is to not stage and commit unnwanted files. However, a more efficient way exists that won't take up space in a `git status` command.

You may use a `.gitignore` file, which supports the wildcard `*`. A good reference is provided here: https://linuxize.com/post/gitignore-ignoring-files-in-git/ 
First, you need to create the file with `touch .gitignore` or `vim .gitignore`. Nano can probably be used as well, but it is not explicitly mentioned here because it is inferior to vim. Make sure to include the `.` character.

The `.gitignore` file should contain one pattern per line. Directories may be included as well. A small example is below and will need to be augmented to ignore all of the unwanted files.
```
*.o
build/
```
