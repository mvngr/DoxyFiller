#ifndef TCLASSINFO_H
#define TCLASSINFO_H

#include <set>

#include "tfunctioninfo.h"

class TClassInfo
{
public:
    TClassInfo(const std::wstring inClassName);
    TClassInfo(const std::wstring inClassName, std::set<TFunctionInfo> inFunctions);

    void insertFunction(TFunctionInfo inValue);

    const TFunctionInfo & findFunction(const std::wstring inName) const;

private:
    std::wstring name_;
    std::set<TFunctionInfo> functions_;
};

#endif // TCLASSINFO_H
