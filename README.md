# CLTEplusplus

**Command Line Text Editor, written in C++**

---

## Overview

In a world full of button and mouse-controlled applications, I decided to create a command-line text editor using the C++ powerhouse. Why did I choose this project? I wanted to practice C++ and delve into low-level programming. A command-line text editor seemed like a perfect way to do that.

Feel free to fork the code and leave a star if you wish!

---

## Usage

To quit the program, type `|`.

---

## Code Breakdown

This C++ code is a simple text editor built for the command line using the `ncurses` library for managing the text-based UI. Below is a brief breakdown of how it works:

### Compiling the Code

You can compile the code in two ways, depending on your platform:

#### For Linux/Unix:
```bash
g++ -lncurses -o cltepp cltepp.cpp
```

#### For Windows (using MinGW32):
```bash
x86_64-w64-mingw32-g++ -o cltepp.exe cltepp.cpp
```

---

## Main Features

- **File Input and Output:** The editor loads a file provided as an argument and displays its contents. Changes are automatically saved to the file after each modification.
- **Text Navigation:** Use the arrow keys (`KEY_UP`, `KEY_DOWN`) to navigate through the text and edit it.
- **Real-Time Text Display:** The content is continuously refreshed and redrawn as you navigate or modify the file.
- **Cursor Control:** Move the cursor up, down, left, and right using the arrow keys.
- **Auto-Save:** Changes are saved automatically to the file after editing.

---

## Functions Overview

### `save_changes(std::string current_text[], int size)`
**Purpose:** Saves the current state of the text to a file called `data.txt`.

**Operation:** Loops through the array of strings (`current_text[]`) and writes each line to the file.

### `draw_text(int current_row, int total_lines, std::string current_text[])`
**Purpose:** Draws the text onto the screen starting from the current row.

**Operation:** Clears the screen and prints lines of text within the terminal window's dimensions. Moves the cursor row-by-row while printing lines from `current_text[]`.

---

## Main Program Flow

1. **Argument Parsing:**
   - The program expects a filename as the first argument.
   - If none is provided, it throws an error and terminates.

2. **File Processing:**
   - Opens the specified file, counts the total number of lines, and stores them in the `current_text[]` array.

3. **Text Rendering:**
   - Calls the `draw_text()` function to display the text in the terminal.
   - Clears the screen and displays the text starting from the current row.

4. **User Interaction:**
   - **Arrow keys:** Move the cursor up, down, left, or right within the text.
   - **Text editing:** Captures typed characters and updates the corresponding line of text in `current_text[]`.
   - **Auto-save:** After each modification, the text is saved to the file using `save_changes()`.
   - **Exit:** Press `|` to exit the program.

---

## Error Handling

- **File not found:** If the provided file can't be opened, the program displays an error message and exits.
- **Out-of-range exception:** If the user attempts to modify text beyond the string's length, the program catches and reports the out-of-range error.

---

## Example Usage

Run the text editor with a file:

```bash
./cltepp yourfile.txt
```

Then, use the arrow keys to navigate, type to edit the file, and press `|` to exit.

---

## Conclusion

This basic text editor allows you to explore, navigate, and modify text files directly from the command line!

---

### Changes Made:
- Structured the document with headers to improve readability.
- Added syntax highlighting for code blocks.
- Used clear and concise descriptions for features and functions.
- Improved formatting of commands and file paths.
