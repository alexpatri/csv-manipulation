#include "csv.hpp"

Csv::Csv(std::string file_name, std::string delimiter) {
    this->file_name = file_name;
    this->delimiter = delimiter;
    this->to_matrix();
}

void Csv::to_matrix() {
    std::vector<std::string> rows = this->get_all_rows();

    for(auto & row : rows) {
        this->matrix.push_back(split_row(row));
    }
}

std::vector<std::string> Csv::get_all_rows() {
    std::vector<std::string> rows;
    std::string row;
    std::ifstream csv_file(this->file_name);

    if(!csv_file.is_open()) {
        std::cout << "Erro ao abrir o arquivo.";
        exit(1);
    }

    while(csv_file.good()) {
        getline(csv_file, row, '\n');
        if(row != "")
            rows.push_back(row);
    }
    return rows;
}

std::vector<std::string> Csv::split_row(std::string row) {
    std::vector<std::string> row_splited;

    int pos = 0;
    while(pos < row.size()) {
        pos = row.find(this->delimiter);
        row_splited.push_back(row.substr(0, pos));
        row.erase(0, pos + this->delimiter.size());
    }
    return row_splited;
}

std::vector<std::string> Csv::get_row(int row_index) {
    return this->matrix[row_index];
}

std::vector<std::string> Csv::get_column(int column_index) {
    std::vector<std::string> column;
    for(auto & row : this->matrix) {
            column.push_back(row[column_index]);
    }
    return column;
}

std::vector<std::vector<std::string>> Csv::get_matrix() {
    return this->matrix;
}

