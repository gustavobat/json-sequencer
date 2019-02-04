// main.cpp : Defines the entry point for the console application.

#include <iostream>
#include <fstream>
#include "TJSONFunctionCaller.h"

int main() {
    std::string path;
    std::ifstream input;

    //std::cout << ":: Please type the path of the JSON input file:" << std::endl;

    path = "input.json";
    input.open(path.c_str());

    while (!input.is_open()) {
        std::cout << ":: Oops! Let's try again with an actual file. Please write down its path:" << std::endl;
        std::cin >> path;
        input.open(path.c_str());
    }

    std::cout << ":: The file was successfully read! Check it below: " << std::endl;

    TJSONFunctionCaller blob(path);
    blob.PrintJSON(std::cout);

    return 0;
}
