#pragma once
#include <vector>
#include "DirectoryObject.h"

class IPrinter {
public:
    virtual ~IPrinter() {}
    virtual void MakeReport(std::vector<DirectoryObjects> directoryObjects) = 0;
};
