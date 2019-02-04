//
// Created by gus on 04/02/19.
//

#include "StubFunctions.h"

void openFile(std::string filePath, std::string nickname) {
    std::cout << "open(" << filePath << ", " << nickname << ");" << std::endl;
}

void select(std::string parameter, int initial, int final) {
    std::cout << "select(" << parameter << ", " << initial << ", " << final << ");" << std::endl;
}
