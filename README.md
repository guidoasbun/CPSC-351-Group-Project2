# Programming Assignment 2: Threads

### Contributors

| Name            | GitHub                                      |
| --------------- | ------------------------------------------- |
| Guido Asbun     | [GitHub](https://github.com/guidoasbun)     |
| Alex Le         | [GitHub](https://github.com/dappurs)        |
| Conner Robbins  | [GitHub](https://github.com/elconnero)      |
| Harry Derderian | [GitHub](https://github.com/HarryDerderian) |

### Description

- This is a POSIX multithread sorting program written in C++
- This program takes an array of hard coded integers and divides them into 2
- Then, this program sorts the 2 separate arrays at the same time in parallel using 2 threads
- Then this program combines the two threads into one array and outputs it
- This makes for a more efficient and faster programming as we can accomplish multiple tasks at the same time

### Instructions

- This is a one file C++ program
- Make sure you have the latest g++ or gcc compiler installed in your computer
- Clone or copy the repository to your computer
  - [Link to GitHub Repository](https://github.com/guidoasbun/CPSC-351-Group-Project2)
- Using a Mac or a Linux terminal, go to the directory the project is in
- Type the following command to compile the program using threads
- `$ g++ -std=c++17 -pthread sorting.cpp -o sorting`
- Type the following command to run the program and print the results to a file named sorting_output.txt
- `$ ./sorting | tee sorting_output.txt`
