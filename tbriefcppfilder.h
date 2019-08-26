#ifndef TBRIEFCPPFILDER_H
#define TBRIEFCPPFILDER_H

#include <string>
#include <fstream>
#include <map>
#include <memory>
#include <algorithm>
#include <iostream>

#include "FileStructure/tclassinfo.h"

typedef std::map<std::wstring, TClassInfo> Data;

class TBriefCppFilder
{
public:
    TBriefCppFilder(const std::wstring inPathToFile);

    std::shared_ptr<Data> calculate();

private:
    std::shared_ptr<Data> data_;
    std::wstring path_;

    void readFile();

    void parseLine(const std::wstring inLine);

};

#endif // TBRIEFCPPFILDER_H
