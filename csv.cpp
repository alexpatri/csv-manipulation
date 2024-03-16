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
        if(row != "") {
            rows.push_back(row);
        }
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

std::vector<std::vector<std::string>> Csv::get_interval_of_rows(int initial_index, int end_index) {
    std::vector<std::vector<std::string>> rows;

    for(int i = initial_index; i < end_index; i++) {
        rows.push_back(this->matrix[i]);
    }
    return rows;
}

std::vector<std::vector<std::string>> Csv::get_interval_of_columns(int initial_index, int end_index) {
    std::vector<std::vector<std::string>> columns;

    for(auto row : this->matrix) {
        std::vector<std::string> individual_row;
        for(int i = initial_index; i < end_index; i++) {
            individual_row.push_back(row[i]);
        }
        columns.push_back(individual_row);
    }
    return columns;
}

