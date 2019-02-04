//
// Created by Gustavo Batistela on 04/02/19.
//

#include "TJSONFunctionCaller.h"

TJSONFunctionCaller::TJSONFunctionCaller(std::string jsonPath) {
    std::ifstream input(jsonPath.c_str());
    input >> commandFile;
}

TJSONFunctionCaller::~TJSONFunctionCaller() {}

void TJSONFunctionCaller::PrintJSON(std::ostream& output) {
    output << std::setw(4) << commandFile << std::endl;
    output << std::flush;
}

const json &TJSONFunctionCaller::getJSON() const {
    return commandFile;
}
