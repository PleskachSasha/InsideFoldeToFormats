#pragma once
#include "IPrinter.h"
#include "TXTPrinter.h"
#include "ICreator.h"
class TXTCreator : public ICreator {
public:
    std::unique_ptr<IPrinter> CreatePrinter() const override {
        return std::make_unique<TXTPrinter>(TXTPrinter());
    }
};