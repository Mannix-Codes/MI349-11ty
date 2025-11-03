#include <iostream>
#include <string>
#include <cstdlib> // For system()
#include "converter.cpp"
using namespace std;

int main() {
    Converter converter;
    converter.convert();
    system("npx @11ty/eleventy --serve");
    return 0;
}