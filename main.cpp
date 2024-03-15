#include <iostream>
#include "csv.hpp"

int main(void) {
    Csv* csv = new Csv("mega-sena.csv", "\t");

    for(auto & row : csv->get_matrix()) {
        for(auto & column : row) {
            std::cout << column << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}

