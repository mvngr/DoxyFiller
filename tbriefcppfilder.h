#ifndef TBRIEFCPPFILDER_H
#define TBRIEFCPPFILDER_H

#include <string>
#include <fstream>
#include <map>
#include <memory>
#include <algorithm>
#include <iostream>

#include "FileStructure/tclassinfo.h"

typedef std::map<std::wstring, TClassInfo> CppData;

class TBriefCppFilder
{
public:
    TBriefCppFilder(const std::wstring inPathToFile);

    std::shared_ptr<CppData> calculate();

private:
    std::shared_ptr<CppData> data_;
    std::wstring path_;

    void readFile();

    void parseLine(const std::wstring inLine);

};

#endif // TBRIEFCPPFILDER_H
