//
// Created by Gustavo Batistela on 04/02/19.
//

#include "TJSONFunctionCaller.h"

TJSONFunctionCaller::TJSONFunctionCaller(std::string jsonPath) {
    std::ifstream input(jsonPath.c_str());
    input >> commandFile;
}

TJSONFunctionCaller::~TJSONFunctionCaller() {}

void TJSONFunctionCaller::CallAllFunctions() {
    for (int i = 0; i < commandFile.size(); i++) {
        CallFunction(commandFile[i]);
    }
}

void TJSONFunctionCaller::CallFunction(json J) const {
    std::string functionName = J[0].get<std::string>();

    if (functionName == "open") {
        std::string filePath = J[1].get<std::string>();
        std::string fileNickname = J[2].get<std::string>();

        openFile(filePath, fileNickname);
        return;
    }

    if (functionName == "select") {
        std::string fileNickname = J[1].get<std::string>();
        int initialTime = J[2].get<int>();
        int finalTime = J[3].get<int>();

        select(fileNickname, initialTime, finalTime);
        return;
    }

    std::cout << "Invalid function name, please check your JSON file." << std::endl;
    return;
}

void TJSONFunctionCaller::PrintJSON(std::ostream& output) {
    output << std::setw(4) << commandFile << std::endl;
    output << std::flush;
}

const json &TJSONFunctionCaller::getJSON() const {
    return commandFile;
}
