#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::string> getWords(std::string s, std::string delimiter);

int main(void) {
    std::ifstream csvFile("mega-sena.csv");
    std::vector<std::string> rows;
    std::vector<std::string> columns;
    std::vector<std::vector<std::string>> matrix;
    std::string delimiter;

    if(!csvFile.is_open()) {
        std::cout << "Erro ao abrir o arquivo.";
        return 1;
    }
    
    while(csvFile.good()) {
        std::string row;
        getline(csvFile, row, '\n');
        rows.push_back(row);
    }

    for(auto & row : rows) {
        matrix.push_back(getWords(row, "\t"));
    }

    for(auto & row : matrix) {
        for(auto & column : row) {
            std::cout << column << ' ';
        }
        std::cout << "\n\n";
    }
}

std::vector<std::string> getWords(std::string s, std::string delimiter){
    std::vector<std::string> res;
    int pos = 0;
    while(pos < s.size()){
        pos = s.find(delimiter);
        res.push_back(s.substr(0,pos));
        s.erase(0,pos+1); 
    }
    return res;
}

