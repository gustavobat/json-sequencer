//
// Created by Gustavo Batistela on 04/02/19.
//

#ifndef TJSONFUNCTIONCALLER_H
#define TJSONFUNCTIONCALLER_H

#include <string>
#include <map>

#include "json.hpp"

class TJSONFunctionCaller {

public:
    TJSONFunctionCaller();

    ~TJSONFunctionCaller();

private:
    nlohmann::json commandFile;
    std::map<std::string, std::string> fNicknameToPath;

};

#endif