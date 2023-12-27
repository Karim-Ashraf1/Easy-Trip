#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void readAndSplitFile(const std::string& filename, std::vector<std::vector<std::string>>& InputList) {
    // Open the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Read lines from the file
    std::string line;
    while (std::getline(file, line)) {
        // Split the line into words
        std::istringstream iss(line);
        std::vector<std::string> words;
        std::string word;
        while (iss >> word) {
            words.push_back(word);
        }

        // Add the vector of words to InputList
        InputList.push_back(words);
    }

    // Close the file
    file.close();
}

int main() {
    // Example usage
    std::string filename = "file.txt";
    std::vector<std::vector<std::string>> InputList;

    // Call the function to read and split the file
    readAndSplitFile(filename, InputList);

    // Display the result
    for (const auto& line : InputList) {
        for (const auto& word : line) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}