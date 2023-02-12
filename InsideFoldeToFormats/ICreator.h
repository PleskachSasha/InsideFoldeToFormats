#pragma once
#include "IPrinter.h"
#include <string>
#include <memory>
#include "ICreator.h"
class ICreator {
public:
    virtual ~ICreator() {};
    virtual std::unique_ptr<IPrinter> CreatePrinter() const = 0;
    void CreateAndMakeReport( std::vector<DirectoryObjects> directoryObjects) const {
        auto product = this->CreatePrinter();
        product->MakeReport(directoryObjects);
    }
};