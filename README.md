# get_next_line
<img width="1925" alt="get_next_line" src="https://user-images.githubusercontent.com/74931024/117971689-7f429380-b32a-11eb-90c8-2b05dc9ce923.png">

**If you want to learn more about IT topics, visit my website:** [**IA Notes**](https://ia-notes.com/)

Thanks to **get_next_line** we will be able to read an open file line by line whose file descriptor is supplied as an argument. The main objective of the project is being able to work with static variables, as well as knowing how to manage dynamic memory so as not to obtain any memory leaks (leaks).

### RETURN VALUES
Since is a function of type int, our **get_next_line** returns a value of type int. This value can be:
<ul>
 <li>-1: if an error has occurred within our function, either because the entered arguments don't have the correct values or because an error occurred while reading the file.</li>
 <li> 0: if it has reached EOF, that is, if the file has been read completely, returning the content read up to that moment.</li>
 <li> 1: if it has found a line break, returning the content read up to that moment since the function was called.</li>
</ul>

### HOW TO USE GET_NEXT_LINE?
1. Clone get_next_line repository:

       git clone https://github.com/pgomez-a/get_next_line.git && cd get_next_line

2. Move the two main functions to your main function (usually main.c):

       mv get_next_line.c get_next_line_utils.c get_next_line.h ~/project_path/

3. In you main function, include the header "get_next_line.h"

       #include <stdio.h>
       #include "get_next_line.h"
       
       int main(void)
       {

4. Compile your program with the three moved functions:

       gcc get_next_line.c get_next_line_utils.c main.c

### ALLOWED FUNCTIONS
When it comes to reading a file, the use of lseek function can be helpful. This function allows us to read the file forward and backward. However, in this project we can't use it. Instead of this, we can only use the external functions: **read, malloc and free.** If we want to use another function, we have to program it ourselves. This is the reason why I have used some of the functions of my **libft.**
Since we are not allowed to use lseek, we can only read the file once, so we have to use a static variable to store the characters that we have read but that are after the line break, so they won't be in the current output but in the next. In this way, we are practicing with the use of static variables at the same time that we have to deal with dynamic memory.

### EXAMPLES OF USE
<img width="350" align="right" alt="main_gnl" src="https://user-images.githubusercontent.com/74931024/109808430-65e4e300-7c27-11eb-9434-b3f64699795e.png">
<img width="350" alt="text_gnl" src="https://user-images.githubusercontent.com/74931024/109808435-68473d00-7c27-11eb-8abc-401f970b5f60.png">
<img width="350" align="right" alt="leaks_gnl" src="https://user-images.githubusercontent.com/74931024/109808444-69786a00-7c27-11eb-8496-d2b5135dbb5a.png">
<img width="350" alt="output_gnl" src="https://user-images.githubusercontent.com/74931024/109808440-68dfd380-7c27-11eb-9bf5-d0d180288a77.png">
