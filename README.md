# get_next_line
Thanks to **get_next_line** we will be able to read an open file line by line whose file descriptor is supplied as an argument. The main objective of the project is being able to work with static variables, as well as knowing how to manage dynamic memory so as not to obtain any memory leaks (leaks).

### RETURN VALUES
Since is a function of type int, our **get_next_line** returns a value of type int. This value can be:
<ul>
 <li>-1: if an error has occurred within our function, either because the entered arguments don't have the correct values or because an error occurred while reading the file.</li>
 <li> 0: if it has reached EOF, that is, if the file has been read completely, returning the content read up to that moment.</li>
 <li> 1: if it has found a line break, returning the content read up to that moment since the function was called.</li>
</ul>

### ALLOWED FUNCTIONS
When it comes to reading a file, the use of lseek function can be helpful. This function allows us to read the file forward and backward. However, in this project we can't use it. Instead of this, we can only use the external functions: **read, malloc and free.** If we want to use another function, we have to program it ourselves. This is the reason why I have used some of the functions of my **libft.**
Since we are not allowed to use lseek, we can only read the file once, so we have to use a static variable to store the characters that we have read but that are after the line break, so they won't be in the current output but in the next. In this way, we are practicing with the use of static variables at the same time that we have to deal with dynamic memory.

### EXAMPLES OF USE
