#include <vector>
#include <fstream>

/**
 * @param: a string of the filename that contains the numbers to be sorted. Each number is separated by a space.
 * @post: reads the file, creates a vector that is filled with numbers where each entry is separated by a space in the input file.
 * @return: a vector containing the numbers from the input file
 **/
std::vector<int> readDataFromFile(std::string filename){
    std::vector<int> data;
    std::ifstream file(filename);
    int number;
    while (file >> number){
        data.push_back(number);
        file.ignore(1, ' ');
    }
    
    return data;
}