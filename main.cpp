#include <iostream>
#include "csv.hpp"

int main(void) {
    Csv* csv = new Csv("mega-sena.csv", "\t");

    for(auto & row : csv->get_interval_of_columns(0, 9)) {
        for(auto & column : row) {
            std::cout << column << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}

