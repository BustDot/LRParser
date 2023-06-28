#include <iostream>
#include "src/include/SLRParser.h"
#include "src/include/LR1Parser.h"

bool chooseParingMethod() {
    auto parser = SLR::SLRParser();
    if (parser.process())
        return true;

    auto lr1_parser = LR1::LR1Parser();
    lr1_parser.process();
}


int main() {
    chooseParingMethod();
    return 0;
}
