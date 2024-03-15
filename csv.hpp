#ifndef CSV_HPP
#define CSV_HPP

#include <string>
#include <vector>

class Csv {
    private:
        std::string file_name;
        std::vector<std::vector<std::string>> matrix;

        std::vector<std::string> get_all_rows();
        std::vector<std::string> split_row(std::string row, std::string delimiter);
        std::vector<std::vector<std::string>> to_matrix();

    public:
        Csv(std::string file_name);

        std::vector<std::string> get_row(int row_index);
        std::vector<std::string> get_column(int column_index);
        std::vector<std::vector<std::string>> get_matrix();
        std::vector<std::vector<std::string>> get_interval_of_rows(int initial_index, int end_index);
        std::vector<std::vector<std::string>> get_interval_of_columns(int initial_index, int end_index);
}

#endif
