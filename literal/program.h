#ifndef LO21_LITERAL_PROGRAM_H
#define LO21_LITERAL_PROGRAM_H


#include "interface.h"

struct ProgramLiteral : public NumericLiteralInterface {
private:
    std::string value;

public:
    ProgramLiteral(std::string value): value(value) {}

    const std::string &getValue() const {
        return value;
    }
};


#endif // LO21_LITERAL_PROGRAM_H
