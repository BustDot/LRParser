#include <iostream>
#include "src/include/SLRParser.h"
#include "src/include/LR1Parser.h"

int main() {
//    auto parser = SLR::SLRParser();
    auto parser = LR1::LR1Parser();
    parser.process();
    return 0;
}
