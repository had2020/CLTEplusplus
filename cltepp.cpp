#include <iostream>
#include <fstream>
#include <string>
//#include <vector>

// export g++ -o cltepp cltepp.cpp

// argc is number of arguments 
// argc is number of args, argv is array of args
int main(int argc, char** argv) {

    std::cout << "Cltepp, By Hadrian Lazic" << std::endl;

    if (argc < 2) {
        std::cerr << "Error, Missing argv" << std::endl;
        std::cerr << "Usage: ./Cltepp <filename>" << std::endl;
        exit(1);
    }

    std::string filename = argv[1]; // filename is first argument

    std::fstream file; // fstream file object
    file.open(filename, std::ios::in | std::ios::out); // fstream open file object

    // Read from the file:
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        // Process the line
    }

    if (!file.is_open()) {
    std::cerr << "Error opening file." << std::endl;
    exit(1);
    }

    // Write to the file:
    std::ofstream outputFile(filename); // ofstream output file object

    //file << "Hello, world!" << std::endl; fails ?

    std::string text; // declartion 
    std::cin >> text; // input
    outputFile << text + line << std::endl; // output to file // TODO keep old data

    file.close();
}