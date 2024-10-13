# CLTEplusplus
  Command Line Text Editor, written in C++

# Use
  In order, to quit the program type "|"


# About
  In a world of button and mouse controlled applications.
  I decided out of all applications to make, with the C++ powerhouse,
  a command line text editor. Why I did this? I wished to pratice
  with C++, so what better way to pratice low level, then to make a
  Command Line Text Editor.

  Feel free to fork the code, leave a star if you wish.

# Code Breakdown
This C++ code is a simple text editor built for the command line using the ncurses library for managing text-based UI. Here's a brief breakdown of how it works:

1. Compiling the Code
You can compile the code in two ways, depending on your platform:

For a native build (Linux/Unix):
bash
Copy code
g++ -lncurses -o cltepp cltepp.cpp
For Windows (using Mingw32):
bash
Copy code
x86_64-w64-mingw32-g++ -o cltepp.exe cltepp.cpp
2. Main Features
File input and output: The editor loads a file provided as an argument and displays its contents. Changes made are saved to the file after each modification.
Text navigation: You can navigate up and down the text with the arrow keys (KEY_UP, KEY_DOWN), and edit the text.
Real-time text display: The content is continuously refreshed and redrawn as you navigate or modify the file.
Cursor control: The editor moves the cursor up, down, left, and right with the arrow keys.
Save changes: As you make changes to the text, they are automatically saved to the file.
3. Functions Overview
save_changes(std::string current_text[], int size)
Purpose: Saves the current state of the text to a file called data.txt.
Operation: Loops through the array of strings (current_text[]) and writes each line to the file.
draw_text(int current_row, int total_lines, std::string current_text[])
Purpose: Draws the text onto the screen starting from the current row.
Operation: Clears the screen and prints lines of text within the terminal window's dimensions. It moves the cursor row-by-row while printing lines from current_text[].
4. Main Program Flow
Argument Parsing: The program expects a filename as the first argument. If none is provided, it throws an error and terminates.

File Processing: Opens the specified file, counts the total number of lines, and stores them in the current_text[] array.

Text Rendering: Calls the draw_text() function to display the text in the terminal. This function clears the screen and displays the text starting from the current_row.

User Interaction:

Arrow keys: Move the cursor up, down, left, or right within the text.
Text editing: Captures typed characters and updates the corresponding line of text in current_text[].
Auto-save: After each modification, the text is saved to the file using save_changes().
Loop: The program continuously listens for user input until the '|' character is pressed, which exits the program.

5. Error Handling
File not found: If the provided file can't be opened, the program displays an error message and exits.
Out-of-range exception: If the user attempts to modify text beyond the string's length, the program catches and reports the out-of-range error.
Example Usage:
Run the text editor with a file:

bash
Copy code
./cltepp yourfile.txt
Then, use the arrow keys to navigate, type to edit the file, and press | to exit.

This basic text editor allows you to explore, navigate, and modify text files directly from the command line!
