#ifndef TJSONSEQUENCER_H
#define TJSONSEQUENCER_H

#include <string>
#include <map>

class TJSONSequencer {

public:
    TJSONSequencer();

    ~TJSONSequencer();

private:
    std::map<std::string, std::string> fNicknameToPath;
};

#endif
