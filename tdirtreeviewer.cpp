#include "tdirtreeviewer.h"

TDirTreeViewer::TDirTreeViewer() :
    root_(L"")
{

}

/*!
 * \brief TDirTreeViewer::setPath запоминает путь до корневой директории проекта
 * \param inPathToDir путь до директории
 * \return удачно ли воспринята директория
 */
bool TDirTreeViewer::setPath(std::wstring inPathToDir)
{
    return true; //TODO
}
