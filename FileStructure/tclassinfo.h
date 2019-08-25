#ifndef TCLASSINFO_H
#define TCLASSINFO_H

#include <set>
#include <memory>

#include "tfunctioninfo.h"

class TClassInfo
{
public:
    TClassInfo();

private:
    std::set<TFunctionInfo> functions_;
};

#endif // TCLASSINFO_H
