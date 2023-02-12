#pragma once
#include "IPrinter.h"
#include "JSONPrinter.h"
#include "ICreator.h"
class JSONCreator : public ICreator {
public:
    std::unique_ptr<IPrinter> CreatePrinter() const override {
        return std::make_unique<JSONPrinter>(JSONPrinter());
    }
};