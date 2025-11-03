#include "runner.hpp"

int main() {
    Converter converter;
    converter.convert();
    system("npx @11ty/eleventy --serve");
    return 0;
}