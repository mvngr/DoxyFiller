#ifndef TCLASSINFO_H
#define TCLASSINFO_H

#include <set>
#include <memory>

#include "tfunctioninfo.h"

class TClassInfo
{
public:
    TClassInfo(const std::wstring inClassName);
    TClassInfo(const std::wstring inClassName, std::set<std::shared_ptr<TFunctionInfo>> inFunctions);

    void insertFunction(TFunctionInfo inValue);

    const std::shared_ptr<TFunctionInfo> findFunction(const std::wstring inName) const;

private:
    std::wstring name_;
    std::set<std::shared_ptr<TFunctionInfo>> functions_;
};

#endif // TCLASSINFO_H
