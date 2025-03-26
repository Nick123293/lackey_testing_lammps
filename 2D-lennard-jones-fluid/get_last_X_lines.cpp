#include<iostream>
#include<fstream>
#include<string>
#include<deque>
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
    std::deque<std::string> lastLines;
    int i = 0;

    while (std::getline(file, line)) 
    {
        lastLines.push_back(line);
        if (lastLines.size() > value) {
            lastLines.pop_front();
        }
    }
    file.close();
    std::cout << "File read..." << std::endl;
    std::string output_fileName = "Last_" + std::to_string(value) + "_Lines";
    std::ofstream outFile(output_fileName);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file " << output_fileName << std::endl;
        return 1;
    }
    // Write the contents of the deque to the output file
    for (const auto &l : lastLines) {
        outFile << l << std::endl;
    }
    outFile.close();
    return 0;
}
