#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    // Отваряне на входния CSV файл и изходния текстов файл
    std::ifstream input_file("input.csv");
    std::ofstream output_file("output.txt");

    // Създаване на вектор за съхранение на първата колона от CSV файла
    std::vector<std::string> data;

    // Четене на CSV файла и добавяне на първата колона във вектора
    std::string line;
    while (std::getline(input_file, line)) {
        std::string value = line.substr(0, line.find(','));
        data.push_back(value);
    }

    // Премахване на повтарящите се елементи
    std::set<std::string> unique_data(data.begin(), data.end());
    data.assign(unique_data.begin(), unique_data.end());

    // Сортиране на елементите в азбучен ред
    std::sort(data.begin(), data.end());

    // Записване на елементите в изходния текстов файл
    for (const auto& value : data) {
        output_file << value << std::endl;
    }

    // Затваряне на файловете
    input_file.close();
    output_file.close();

    return 0;
}
