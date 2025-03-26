#include<iostream>
#include<fstream>
#include<string>
#include<unordered_set>
int main(int argc, char* argv[])
{
    // Check if the filename is provided
    if (argc < 3) {
        std::cerr << "Usage: ./extract_values <file> <number of lines you want to parse>" << std::endl;
        return 1;
    }
    // Get the filename from the command-line arguments
    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error opening file"<< std::endl;
        return 1;
    }
    uint64_t value;
    try {
        size_t pos;
        value = std::stoull(argv[2], &pos);
        // Check if the entire string was converted
        if (pos == std::string(argv[2]).length()) {
            std::cout << "Argument is a valid integer: " << value << std::endl;
        } else {
            std::cout << "Argument contains extra non-integer characters ... Usage: ./extract_values <file> <number of lines you want to parse>" << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Non-Integer value listed as argument 2 ... Usage: ./extract_values <file> <number of lines you want to parse>" << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
        std::cout << "Argument is not a valid 64-bit usigned integer (out of range) ... Usage: ./extract_values <file> <number of lines you want to parse>" << std::endl;
        return 1;
    }
    std::string line;
    char equal_test = '=';
    std::streampos temp;
    while (equal_test == '=') //Parse out the beginning lines of Lackey output
    {
        temp = file.tellg(); //Save file pointer of the last line with an equal
        std::getline(file, line);
        equal_test = line[0];
    }
    int numLines = 0;
    file.seekg(temp); //Reload last line
    while(numLines < value) //Seek through the beef of the lackey output
    //There is also lackey output that we need to parse out at the end, how do we do this?
    {
        std::getline(file, line);
        ++numLines;
    }  
    return 0;
}
