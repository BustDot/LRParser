#include <iostream>
#include "src/include/SLRParser.h"

int main() {
    auto parser = SLR::SLRParser();
    parser.process();
    return 0;
}
