#include<iostream>
#include<fstream>
#include<string>
#include<unordered_set>
int main(int argc, char* argv[])
{
    // Check if the filename is provided
    if (argc < 2) {
        std::cerr << "Usage: ./extract_values <file>" << std::endl;
        return 1;
    }
    // Get the filename from the command-line arguments
    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error opening file"<< std::endl;
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
    long int numLines = 0;
    file.seekg(temp); //Reload last line
    while(std::getline(file, line)) //Seek through the beef of the lackey output
    //There is also lackey output that we need to parse out at the end, how do we do this?
    {
        ++numLines;
    }  
    std::cout <<"Num lines: " << numLines << std::endl;
    return 0;
}
