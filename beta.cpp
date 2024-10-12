#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>

// EXPORTING
// export native: g++ -o cltepp cltepp.cpp
// export for exe: x86_64-w64-mingw32-g++ -o cltepp.exe cltepp.cpp

// DRAWING text
void draw_text(int total_lines, std::string current_text[]) {

    // DISPLAY accounting
    int max_rows, max_cols;
    getmaxyx(stdscr, max_rows, max_cols); // Get the size of the window

    int counter = 0;

    while (counter < total_lines) {
        move(counter, 0);
        printw("%s", current_text[counter].c_str());
        refresh();
        counter++;
    }
}

// argc is number of arguments
// argc is number of args, argv is array of args
int main(int argc, char** argv) {

    // MISSING filepath
    if (argc < 2) {
        std::cerr << "Error, Missing argv" << std::endl;
        std::cerr << "Usage: ./Cltepp <filename>" << std::endl;
        exit(1);
    }

    initscr();
    noecho(); // disable echoing of input characters
    keypad(stdscr, TRUE); // enable extended keyboard input

    std::string filename = argv[1]; // filename is first argument

    std::fstream file; // fstream file object
    file.open(filename, std::ios::in | std::ios::out); // fstream open file object

    // PROCESS lins in file to var:
    int total_lines = 0;
    std::string line;

    // Checking total lines
    while (std::getline(file, line)) {
        //total_lines = total_lines + 1;
        total_lines++;
    }

    file.close();

    file.open(filename, std::ios::in | std::ios::out); // fstream open file object

    std::string current_text[total_lines]; // each index is a line
    int current_line = 0;

    while (std::getline(file, line)) {
        current_text[current_line] = line;
        current_line++;
    }

    // FAILED opening
    if (!file.is_open()) {
    std::cerr << "Error opening file." << std::endl;
    exit(1);
    }

    file.close(); // closes to prevent data loss.

    while (true) {
        int ch = getch();

        if (ch == KEY_UP) {
            draw_text(total_lines, current_text);
        } else {
            // handle other keys or exit the loop if needed
            break;
        }
    }

    //clear(); // clears screen
    endwin();
}
