#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>

// export native: g++ -o cltepp cltepp.cpp
// export for exe: x86_64-w64-mingw32-g++ -o cltepp.exe cltepp.cpp

// argc is number of arguments
// argc is number of args, argv is array of args
void inputs() {
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

}

int main(int argc, char** argv) {

    if (argc < 2) {
        std::cerr << "Error, Missing argv" << std::endl;
        std::cerr << "Usage: ./Cltepp <filename>" << std::endl;
        exit(1);
    }

    initscr();
    //mvprintw(LINES - 5, 5, "### Cltepp, by Hadrian Lazic ###");
    refresh();

    char mesg[] = "Enter: ";
    char str[80];
    int row, col;

    getmaxyx(stdscr, row, col);

    std::string filename = argv[1]; // filename is first argument

    std::fstream file; // fstream file object
    file.open(filename, std::ios::in | std::ios::out); // fstream open file object

    std::string current_data;

    // Read from the file:
    std::string line;
    while (std::getline(file, line)) {
        //std::cout << line << std::endl; // displays line for i
        printw("%s\n", line.c_str());
        refresh();
        current_data = current_data + "\n" + line;
        // Process lines
    }

    if (!file.is_open()) {
    std::cerr << "Error opening file." << std::endl;
    exit(1);
    }

    // Write to the file:
    std::ofstream outputFile(filename); // ofstream output file object

    //file << "Hello, world!" << std::endl; fails ?

    //std::string line_int = "\n"; // predeclared with \n, for next line
    std::string changed_text;
    std::getline(std::cin, changed_text); // input, allows for space in input
    outputFile << current_data + "\n" + changed_text;// output to file TODO add quit function

    file.close(); // TODO close after reading so that work is not removeed if writing and then quit
}
