#include "iostream"

#include "TApplication.h"

int main(int argc, char** argv) {

    TApplication app("light_yield", &argc, argv);
    std::cout << "We ran!\n";
    return 0;
}