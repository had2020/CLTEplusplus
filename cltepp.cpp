#include <iostream>
#include <fstream>
#include <string>
//#include <vector>

// export native: g++ -o cltepp cltepp.cpp
// export for exe: x86_64-w64-mingw32-g++ -o cltepp.exe cltepp.cpp

// argc is number of arguments
// argc is number of args, argv is array of args
int main(int argc, char** argv) {

    std::cout << "#### Cltepp, By Hadrian Lazic ####" << std::endl;

    if (argc < 2) {
        std::cerr << "Error, Missing argv" << std::endl;
        std::cerr << "Usage: ./Cltepp <filename>" << std::endl;
        exit(1);
    }

    std::string filename = argv[1]; // filename is first argument

    std::fstream file; // fstream file object
    file.open(filename, std::ios::in | std::ios::out); // fstream open file object

    std::string current_data;

    // Read from the file:
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl; // displays line for i
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
