# Lab 3: Constructing Singly Linked Lists using C++ Classes
For your lab this week, you will be constructing a singly linked list using a C++ class. This lab will serve as a soft introduction to programming in C++. Your task is to implement something similar to what you did for Lab2 (perhaps even simpler, since it'll be a singly linked list instead of a doubly linked list) however, you will be using a C++ class object for your linked list nodes. You will also be performing File I/O for the reading in the data for your linked list nodes.


# Preliminaries 
Your linked list node should be constructed using the following class.
```c++
class StudentNode{
  public : 
        std::string  name_;
	float         gpa_;
	int totalCredits_;
        StudentNode* next_;
        StudentNode();
        StudentNode(std::string fileName);

};

```

## File I/O in C++
Consult the <a href="https://www.cplusplus.com/reference/fstream/ifstream/">ifstream</a> and  <a href="https://www.cplusplus.com/reference/fstream/ofstream/ofstream/">ofstream</a> reference page for C++ File I/O.
An example: 

```c++
#include <fstream>

int main(){
	
	std::ifstream ifs; //  std::ofstream ofs -- output file stream object
	ifs.open("myfile.bin", ios::in | ios::binary); 
	// This will open a file named `myfile.txt' 
	// `ios::in` -- this sets up the stream for input operations -- 
	// `ios::binary` -- this opens the file in binary mode.
	
	if( ifs.is_open() ){ // returns a bool value to validate whether or not the stream object is associated with an open file.
	 // Let's read in some data.
	 int num; // assuming we have some integer value to read in.
	 ifs >> num; // We use the stream extraction operator `>>` to extract data from the stream.
	 	     // You may use the stream insertion operator `<<` to insert data into an ofstream object.
	  // The fstream object has a set of flags we can query to check if read-write operations were succesful.
	 
	   /* 1.) badbit - checked with ifs.bad(). This returns true if reading or writing operations fail. The failure here is with regards to
	      		   The buffer associated with the stream. In other words, if we try to write to a file that is not open for writing or 
			   if we attemptwriting to a device that has no space left.
	       
	`.    2.) Failbit - checked with ifs.fail() - trigerred in the same cases as  ifs.bad(). However, it's also set to true when there is a
			    format error. For example, attempting to extract an integer from the stream into an alphabetical character.
			    
	      3.) eofbit     - end of file - checked with ifs.eof(). This returns true if a file open for reading has reached the end of the file.
	      
	      4.) goodbit     - checked with ifs.good(). Returns false in the same cases where all others return true. 
	      
	      You may also use the NOT (bang) operator `!` which returns true if either failbit or badbit is set to true.
	
	   */
	
	}
	ifs.close(); // close the file stream
	

	return 0;
}

```

# Instructions 
- Make commits as often as necessary, with self-contained bits of code rather than large blobs. ***You do not need to push after each commit.***
- **Read and internalize the warnings.**
- Itemized directions are below. You may not have to do them in order.

1. Read and internalize the warnings.
2. Create a `main.cpp` OR `main.cc` file. **N.B**: The C++ compiler recognizes either extension for Cplusplus source code files.
	- Include the `argc` and `argv` arguments for the main function. For this assignment, you will be reading the node data from a text file.
	- Use the command line arguments to pass in the file name **more on this later..**.  
3. Create a header and implementation file for a studentList. 
	- Define a C++ class for a student Node following the above example.
	- Your class should include a default constructor which just creates an instance of the class with all data members set to null.
	- Since the data for the Linked List will be read in from a file, you should also implement a constructor which takes in a file name as a parameter. 
		- This constructor should go through every student in the file and create and link a node for each respective student.
	- Each student file will follow this format:
		``` 
		Name
		GPA
		Total credits
		```
	- Implement a function to print list to standard out using the following format:
			- ```Student Name: #####\nGPA: #####\nTotal credits: ####```
				- Replace the hashes with the actual data. 
	- Implement a function to print the contents of the list to a file with the following format:
		``` 		
		Name
		GPA
		Total credits
		\n
		Name
		GPA
		Total credits
		...
		```	
		The default file name for the ouput file should be `composite_student_list.txt` unless otherwise specified by the user through the command line 		(more on this later). 
	- In this lab, you will be utilizing the command line to pass in flags (or options) to your program for performing a variety of tasks.
		1. Implement a `-f` flag to specify a single student file ID to be read into memory. 
			 - For example `./prog -f student_1.txt` this will load data from the file entitled `student_1.txt` into a node and write the list to a 			   file named `composite_student_list.txt`.
		2. Implement a `-r` flag to specify a range of student file IDs to be read into memory.
			 - For example `./prog -r 1-5` this will load data from the files entitled `student_1.txt` through `student_5.txt` into independent nodes 			     which will be linked together. The resulting linked list should be printed to a file named `composite_student_list.txt` unless otherwise 				 specified.
		3. Implement a `-o` flag to specify an output file name. By default, the output file should be called `composite_student_list.txt`.
		4. Implement a `-i` flag for Node insertion. This flag should support two(2) or one (1) argument(s). If only one argument is passed in, it should 		             first, check to see if a file named `composite_student_list.txt` exisits. If it does, it appends a node at the end of the list generated 				 from the file and it updates the file. Ensure that the student doesn't already exist in the list before appending. If two arguments 			           are passed, it should operate as `-i src_file insert_file`. Where the list is generated using `src_file` and the contents of 				  `insert_file` should be appended to the generated list. The modified lists' content should be written to `composite_student_list.txt` 		   	   unless otherwise specified by the `-o` option.
		5. Implement a `-d` flag. This command line option should delete a student node by name in the list generated from `composite_student_list.txt`. 		            The list is updated following student deletion.
		6. Implement a `-h` flag which prints the programs usage. That is, it prints how the program may be executed.
		7. In the event of an invalid or insufficient command line, print a meaningful error message such as:  `-q` flag is not supported **OR** `-f` flag 		   		expects an accompanying file name for read operation.  Following this, print the program's usage.
	
4. Dynamically allocate students and nodes with C++'s `new` keyword.
5. Read and internalize the warnings.
6. Test all of your functions in `main`.
7. Add **ROBUST** error handling to deal with the command line input!!
8. Paste your terminal output from the assignment onto the end of this document. Displaying test cases for each command line arguments.
9. Print meaningful error messages to standard out. Such as ```c++ std::cout << "Could not delete student `" << student << "` . The student does not exist!"<< std::endl; ```
		
		
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
- Be sure to perform substantial error checking on the command line options.

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
