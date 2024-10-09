/*
Creative Commons, CLTEplusplus, By Hadrian Lazic, 10/9/24
*/

// TIP ./ to run apps on macos

#include <iostream>
#include <fstream>

int create_file(std::string filesname) {
}

int read_data(std::string filesname) {
    std::ifstream infile(filesname);
    if (infile.is_open()) {
        std::string line;
        while (std::getline(infile, line)) {
            std::cout << line << std::endl;
        }
        //infile.close();
    } else {
        //std::cerr << "Unable to open file for reading" << std::endl; Error if non-file
        std::fstream file;
        file.open("test.txt", std::ios::out);
        file << "test data";
        file.close();
    }

    return 0;
}

int write_data(std::string filesname) {
    std::ofstream outfile("data.txt");
    if (outfile.is_open()) {
        outfile << "Hello, world!" << std::endl;
        outfile << 42 << std::endl;
        outfile.close();
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
    } 

    return 0;
}

int main() {
    std::string name; 

    std::cout << "CLTEplusplus, By Hadrian Lazic" << std::endl;
    std::cout << "File to open/create" << std::endl;
    std::cin >> name;
    read_data(name);

    return 0;
}