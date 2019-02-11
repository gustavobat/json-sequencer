// main.cpp : Defines the entry point for the console application.

#include <iostream>
#include <fstream>
#include <iomanip>
#include "json.hpp"

#include "StubFunctions.h"

using json = nlohmann::json;
void printJSON(json commandFile, std::ostream& out);
void callMethods(json commandFile);
void translateToFunction(json singleCommand);


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

    json commands;
    input >> commands;
    printJSON(commands, std::cout);

    std::cout << std::endl << ":: The following methods would be called: " << std::endl << std::endl;
    callMethods(commands);

    return 0;
}

void printJSON(json commandFile, std::ostream& output) {
    output << std::setw(4) << commandFile << std::endl;
    output << std::flush;
}

void callMethods(json commandFile) {
    for (int i = 0; i < commandFile.size(); i++) {
        translateToFunction(commandFile[i]);
    }
}

void translateToFunction(json singleCommand) {
    std::string functionName = singleCommand[0].get<std::string>();

    if (functionName == "open") {
        std::string filePath = singleCommand[1].get<std::string>();
        std::string fileNickname = singleCommand[2].get<std::string>();

        openFile(filePath, fileNickname);
        return;
    }

    if (functionName == "select") {
        std::string fileNickname = singleCommand[1].get<std::string>();
        int initialTime = singleCommand[2].get<int>();
        int finalTime = singleCommand[3].get<int>();

        select(fileNickname, initialTime, finalTime);
        return;
    }

    std::cout << "Invalid function name, please check your JSON file." << std::endl;
    return;
}
