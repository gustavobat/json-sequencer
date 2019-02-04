//
// Created by Gustavo Batistela on 04/02/19.
//

#ifndef TJSONFUNCTIONCALLER_H
#define TJSONFUNCTIONCALLER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>

#include "json.hpp"
using json = nlohmann::json;

#include "StubFunctions.h"

class TJSONFunctionCaller {

public:
    TJSONFunctionCaller(std::string jsonPath);

    ~TJSONFunctionCaller();

    void PrintJSON(std::ostream& output);

private:
    json commandFile;
};

#endif