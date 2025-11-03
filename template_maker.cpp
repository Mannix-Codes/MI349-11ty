#include "runner.hpp"

bool makenav = false;
class NavMaker {
public:
    int make_Nav(const std::vector<std::string>& titles, std::string in_template_name, std::string out_template_name) {
        std::ifstream inFile(in_template_name);
        std::ofstream outFile;
        outFile.open(out_template_name);
        if (!inFile.is_open() || !outFile.is_open()) {
            std::cerr << "Error opening template file!" << std::endl;
            return 1;
        }
        std::string line;
        while (std::getline(inFile, line)) {
            if (line.find("<nav>") != std::string::npos && !makenav) {
                makenav = true;
                outFile << "<nav>\n<ul>\n";
                for (const auto& title : titles) {
                    outFile << "<li><a href=\"/" << title << "\">" << title << "</a></li>\n";
                }
                outFile << "</ul>\n</nav>\n";
            }
            else if (makenav && line.find("</nav>") != std::string::npos) {
                makenav = false;
            }
            else {
                outFile << line << "\n";
            }

        }
        inFile.close();
        outFile.close();
        return 0;


    }};