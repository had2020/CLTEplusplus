#include <ncurses.h>

int main() {
    initscr(); // Initialize ncurses
    noecho(); // Disable echoing of input characters
    keypad(stdscr, TRUE); // Enable extended keyboard input

    while (true) {
        int ch = getch(); // Get a character from the keyboard

        if (ch == KEY_UP) { // Check if the up arrow key was pressed
            // Your code to execute when the up arrow key is pressed
            mvprintw(LINES - 1, 0, "Up arrow key pressed!");
            refresh(); // Update the screen
        } else {
            // Handle other keys or exit the loop if needed
            break;
        }
    }

    endwin(); // Terminate ncurses
    return 0;
}
