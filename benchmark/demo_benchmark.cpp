#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>

// подключаем вашу структуру данных
#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};
static constexpr auto kMethodsNamesList = {"Insert", "ExtractMin", "Merge"};
static constexpr auto kDatasetNamesList = {"01", "02", "03", "04", "05"};
static constexpr auto kDatasetCountsList = {"100", "1000", "10000", "100000", "1000000"};

vector<int> createVectorFromCSV(string &path) {
  fstream fin;
  fin.open(path, ios::in);

  string temp;
  fin >> temp;
  istringstream ss(temp);

  string token;
  vector<int> numbers;

  while (getline(ss, token, ',')) {
    numbers.push_back(stoi(token));
  }
  return numbers;
}

int main(int argc, char **argv) {

  // Tip 1: входные аргументы позволяют более гибко контролировать работу вашей программы.
  // Можете передать путь до входного/выходного тестового файла в качестве аргумента программы.
  // Tip 2: для перевода строки в число можете использовать функцию stoi (string to integer)

  // можете использовать функционал класса stringstream для обработки строки

  for (int index = 0; index < argc; index++) {
    cout << "Arg: " << argv[index] << '\n';
  }
  // работа с набором данных
  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  for (string dataset_name : kDatasetNamesList) {
    for (string count : kDatasetCountsList) {
      for (int trial = 1; trial < 11; trial++) {
        string path_to_csv = path + "/" + "Insert" + "/" + dataset_name + "/" + count + ".csv";
        auto vect = createVectorFromCSV(path_to_csv);
        cout << "Method-" << "Insert" << " dataset-" << dataset_name << " datacount-" << count << " trial-";
        cout << trial << "\t";

        auto *binomialHeap = new BinomialHeap();
        const auto time_point_before = chrono::steady_clock::now();

        for (int key : vect) {
          binomialHeap->Insert(key, 228);
        }

        const auto time_point_after = chrono::steady_clock::now();
        // переводим время в наносекунды
        const auto time_diff = time_point_after - time_point_before;
        const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
        cout << "Time elapsed (ns): " << time_elapsed_ns << '\n';
      }
      cout << endl;
    }
  }
  // Контрольный тест: операции добавления, удаления, поиска и пр. над структурой данных

  // Tip 3: время работы программы (или участка кода) можно осуществить
  // как изнутри программы (std::chrono), так и сторонними утилитами

  return 0;
}

