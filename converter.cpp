#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("information.csv");
    ofstream outputFile("information.json");
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    string line;
    while (getline(inputFile, line)) {
        // Process the CSV line and convert it to JSON format
        // For simplicity, let's just wrap the line in curly braces
        outputFile << "{" << line << "}" << endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}