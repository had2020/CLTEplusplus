#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>

// EXPORTING
// export native: g++ -o cltepp cltepp.cpp
// export for exe: x86_64-w64-mingw32-g++ -o cltepp.exe cltepp.cpp

void save_changes(std::string current_text1[], int size) {
    std::ofstream file("data.txt");

    for (int i = 0; i < size; ++i) {
        file << current_text1[i] << "\n"; // Add a newline character after each string
    }

    file.close();
}

// DRAWING text
void draw_text(int current_row1 ,int total_lines, std::string current_text[]) {
    clear(); // clears screen

    // DISPLAY accounting
    int max_rows, max_cols;
    getmaxyx(stdscr, max_rows, max_cols); // Get the size of the window

    int counter = 0;
    int move_counter = 0;

    // USER cursor, up and down
    counter  = counter + current_row1;
    max_rows = max_rows + current_row1;

    while (counter < total_lines) {
        move(move_counter, 0);
        printw("%s", current_text[counter].c_str());
        refresh();
        counter++;
        move_counter++;
        if (counter == max_rows) {
            break;
        }
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
    curs_set(1); // cursor visible
    cbreak();   // disable line buffering input passed immediately

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

    // get current text
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

    int current_row = 0;

    int max_rows;
    int max_cols;
    getmaxyx(stdscr, max_rows, max_cols);

    draw_text(current_row, total_lines, current_text);

    mvaddstr(0, 0, ""); // sets cursor to start
    std::string changed_text;

    // USER curosr
    while (true) {
        int ch = getch();
        int x;
        int y;

        switch (ch) {
            case KEY_UP:
                if (current_row != 0) {
                    current_row--;
                }
                draw_text(current_row, total_lines, current_text);
                mvaddstr(y, x, "");
                break;
            case KEY_DOWN:
                current_row++;
                draw_text(current_row, total_lines, current_text);
                mvaddstr(y, x, "");
                break;
            case KEY_LEFT:
                mvaddstr(y, x - 1, ""); // clear
                x--;
                mvaddstr(y, x, ""); // new
                break;
            case KEY_RIGHT:
                mvaddstr(y, x + 1, "");
                x++;
                mvaddstr(y, x, "");
                break;
            default:
                if (ch != '|') {
                    std::string change;
                    change = ch;
                    changed_text = changed_text + change;
                    mvaddstr(y, x + 1, "");
                    x++;
                    //mvaddch(y, x, ch);
                    mvaddstr(y, x, ""); // slient move
                    //current_text[current_row][x] = ch; fails
                    //current_text[current_row].insert(x, 1, ch); inserts
                    //current_text[current_row].replace(x, 1, 1, ch);
                    try {
                        if (x < current_text[current_row].length()) {
                            // replace when within
                            current_text[current_row].replace(x, 1, 1, ch);
                        } else {
                            // insert when out
                            current_text[current_row].insert(current_text[current_row].length(), 1, ch);
                        }
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Out of range error: " << e.what() << '\n';
                        // exception here
                    }
                    save_changes(current_text, total_lines);
                    draw_text(current_row, total_lines, current_text);
                    mvaddstr(y, x, ""); // bc resets due draw_text method
                }
        }

        if (ch == '|') {
            break;
        }

        refresh();
    }

    endwin();
    return 0;
}
