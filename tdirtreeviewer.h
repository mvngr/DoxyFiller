#ifndef TDIRTREEVIEWER_H
#define TDIRTREEVIEWER_H

#include <string>
#include <fstream>

class TDirTreeViewer
{
public:
    TDirTreeViewer();

    bool setPath(std::wstring inPathToDir);

    bool isValid();

private:
    std::wstring root_;
};

#endif // TDIRTREEVIEWER_H
