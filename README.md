**Task Scheduler System**

**OVERVIEW OF THE PROJECT AND ITS PURPOSE**

The Task Scheduler System is a C-based console application designed to help users efficiently manage their daily tasks. Its main purpose is to organize tasks based on priority, allow easy tracking of completion status, and provide scheduling support. The system enables users to add, delete, search, sort, and update tasks, helping reduce manual tracking and improving productivity and organization.


**THE DATA STRUCTURES AND ALGORITHMS USED, AND WHICH FEATURES THEY SUPPORT**

The system utilizes several fundamental data structures to support its functionality. A linked list is used to store all tasks, allowing efficient insertion, deletion, and traversal of task records. A stack is implemented to support the undo feature, enabling users to restore recently deleted tasks using a Last-In, First-Out (LIFO) approach. Additionally, a queue is used to manage scheduled tasks, ensuring they are processed in a First-In, First-Out (FIFO) order.

For algorithms, the system uses a sorting algorithm (bubble sort) to arrange tasks according to priority levels, ensuring that high-priority tasks are handled first. A linear search algorithm is used to locate tasks by name, providing a simple and effective way to retrieve task information. These data structures and algorithms make the system organized, functional, and suitable for task management applications.


**INSTRUCTIONS ON HOW TO COMPILE AND RUN THE APPLICATION**

How to Compile and Run Using Dev-C++

1. Open Dev-C++.
2. Click File → New → Source File.
3. Copy and paste the Task Scheduler System code into the editor.
4. Click File → Save As and save it as `task_scheduler.c`.
5. To compile the program, click Execute → Compile or press F9.
6. To compile and run the program, click Execute → Compile & Run or press F11.
7. After running, the console window will appear showing the Task Scheduler menu, and you can start using the system by entering your desired option.

Important:  Ensure that the file is saved with a `.c` extension so that Dev-C++ recognizes it as a C program.


**SAMPLE MENU**

===== TASK MANAGER =====

1. Add Task
2. View Tasks
3. Delete Task
4. Mark Complete
5. Sort Tasks
6. Search Task
7. Undo Delete
8. View Queue
9. Exit

**PURPOSE OF THE PROJECT**

This project is intended to demonstrate the practical application of core data structures such as linked lists, stacks, and queues in a real-world scenario. It also highlights the use of basic algorithms like sorting and searching within a functional system.


