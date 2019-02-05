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

#include "StubFunctions.h"

#include "json.hpp"
using json = nlohmann::json;

class TJSONFunctionCaller {

public:
    TJSONFunctionCaller(std::string jsonPath);

    ~TJSONFunctionCaller();

    void CallAllFunctions();

    void CallFunction(json J) const;

    void PrintJSON(std::ostream& output);

    const json &getJSON() const;

private:
    json commandFile;
};

#endif