#include <iostream>
#include <string>
#include <fstream>

class Pager {
    public: 
        void make_page(std::string title) {
            std::ofstream page_file;
            std::string filename = title + ".md";
            page_file.open(filename);
            if (!page_file.is_open()) {
                std::cerr << "Error creating page file!" << std::endl;
                return;
            }
            page_file << "---\n";
            page_file << "layout: my-layout.liquid\n";
            page_file << "title: " << title << "\n";
            page_file << "---\n";
            page_file << "{% index_page " << title << " %}\n";
            page_file.close();
        }
    };