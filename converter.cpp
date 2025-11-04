#include "runner.hpp"
using namespace std;


std::vector<std::string> split(const std::string &s, char delimiter);
std::string output (const std::vector<std::vector<std::string>> _pages);
class Converter {
public:
    int convert(){
        ifstream inputFile("information.txt");
    ofstream outputFile("information.json");
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    string line;
    std::vector<std::vector<std::string>> pages;
    if (getline(inputFile, line)) {
        // Skip header line
    }
    while (getline(inputFile, line)) {
        std::vector<std::string> tokens = split(line, '-');
        if (tokens.size() == 5) {
            pages.push_back(tokens);
        }
        else {
            cerr << "Malformed line: " << line << endl;
        }
    }
    outputFile << output(pages);
    inputFile.close();
    outputFile.close();
    return 0;
    }
};



std::string output (const std::vector<std::vector<std::string>> _pages) {
    std::vector<std::string> titles;
    std::vector<std::string> images;
    std::vector<std::string> alts;
    std::vector<std::string> headings;
    std::vector<std::string> texts;
    Pager pager;
    NavMaker navmaker;
    for (const auto& page : _pages) {
        titles.push_back(page[0]);
        images.push_back(page[1]);
        alts.push_back(page[2]);
        headings.push_back(page[3]);
        texts.push_back(page[4]);
    }
    navmaker.make_Nav(titles, "_includes/template-layout.liquid", "_includes/my-layout.liquid");
    for (const auto& title : titles) {
        pager.make_page(title);
    }
    std::ostringstream oss;
    oss << "{\n";
    oss << "\"titles\": [";
    for (size_t i = 0; i < titles.size(); ++i) {
        oss << "\"" << titles[i] << "\"";
        if (i != titles.size() - 1) oss << ", ";
    } 
    oss << "],\n";
    oss << "\"images\": [";
    for (size_t i = 0; i < images.size(); ++i) {
        oss << "\"" << images[i] << "\"";
        if (i != images.size() - 1) oss << ", ";
    }
    oss << "],\n";
    oss << "\"alts\": [";
    for (size_t i = 0; i < alts.size(); ++i)
    {
        oss << "\"" << alts[i] << "\"";
        if (i != alts.size() - 1) oss << ", ";
    }
    oss << "],\n";
    oss << "\"headings\": [";
    for (size_t i = 0; i < headings.size(); ++i)
    {
        oss << "\"" << headings[i] << "\"";
        if (i != headings.size() - 1) oss << ", ";
    }
    oss << "],\n";
    oss << "\"texts\": [";
    for (size_t i = 0; i < texts.size(); ++i)
    {
        oss << "\"" << texts[i] << "\"";
        if (i != texts.size() - 1) oss << ", ";
    }
    oss << "]\n";
    oss << "}\n";
    return oss.str();
}


std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}