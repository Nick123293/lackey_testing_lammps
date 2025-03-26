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
    int i = 0;
    std::string output_fileName = "First_" + std::to_string(value) + "_Lines";
    std::ofstream outFile(output_fileName);
    while(i < value && std::getline(file, line)) //Seek through the beef of the lackey output
    //There is also lackey output that we need to parse out at the end, how do we do this?
    {
        outFile << line << std::endl;        
        ++i;
    }  
    return 0;
}
