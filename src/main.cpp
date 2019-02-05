// main.cpp : Defines the entry point for the console application.

#include <iostream>
#include <fstream>
#include "TJSONFunctionCaller.h"

int main() {
    std::string path;
    std::ifstream input;

    path = "input.json";
    input.open(path.c_str());

    while (!input.is_open()) {
        std::cout << ":: Oops! Let's try again with an actual file. Please write down its path:" << std::endl;
        std::cin >> path;
        input.open(path.c_str());
    }

    std::cout << ":: The JSON file was successfully read! Check it below: " << std::endl << std::endl;

    TJSONFunctionCaller caller(path);
    caller.PrintJSON(std::cout);

    std::cout << std::endl << ":: The following functions would be called: " << std::endl << std::endl;
    caller.CallAllFunctions();

    return 0;
}
