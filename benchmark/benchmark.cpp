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

// константы всякие
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};
static constexpr auto kTrialsCount = 10;
static constexpr auto kRandomInsertKey = 1000000;
static constexpr auto kMethodsNamesList = {"Insert", "Minimum", "ExtractMin"};
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

void ExtractMin_benchmark(BinomialHeap* binomialHeap) {
    const auto time_point_before = chrono::steady_clock::now();

    binomialHeap->ExtractMin();

    const auto time_point_after = chrono::steady_clock::now();

    const auto time_diff = time_point_after - time_point_before;
    const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
    cout << "Time elapsed (ns): " << time_elapsed_ns << '\n';
}

void Insert_Benchmark(BinomialHeap* binomialHeap) {
    const auto time_point_before = chrono::steady_clock::now();

    binomialHeap->Insert(kRandomInsertKey, kRandomInsertKey);

    const auto time_point_after = chrono::steady_clock::now();

    const auto time_diff = time_point_after - time_point_before;
    const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
    cout << "Time elapsed (ns): " << time_elapsed_ns << '\n';
}

void Minimum_Benchmark(BinomialHeap* binomialHeap) {
    const auto time_point_before = chrono::steady_clock::now();

    binomialHeap->Minimum();

    const auto time_point_after = chrono::steady_clock::now();

    const auto time_diff = time_point_after - time_point_before;
    const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
    cout << "Time elapsed (ns): " << time_elapsed_ns << '\n';
}

// fill BinomialHeap
BinomialHeap* fill(std::vector<int> vect) {
    auto *binomialHeap = new BinomialHeap();
    for (int key: vect) {
        binomialHeap->Insert(key, key);
    }
    return binomialHeap;
}

int main() {
    const auto path = string(kDatasetPath);
    cout << "Path to the 'dataset/' folder: " << path << endl;

    for (string method : kMethodsNamesList) {
        for (string dataset_name: kDatasetNamesList) {
            for (string count: kDatasetCountsList) {
                for (int trial = 1; trial < kTrialsCount + 1; trial++) {
                    string path_to_csv = path + "/" + method + "/" + dataset_name + "/" + count + ".csv";
                    auto vect = createVectorFromCSV(path_to_csv);
                    cout << "Method-" << method << " dataset-" << dataset_name << " datacount-" << count << " trial-";
                    cout << trial << "\t";

                    BinomialHeap* binomialHeap = fill(vect);

                    if (std::equal(method.begin(), method.end(), "ExtractMin")) {
                        ExtractMin_benchmark(binomialHeap);
                    } else if (std::equal(method.begin(), method.end(), "Insert")) {
                        Insert_Benchmark(binomialHeap);
                    } else if (std::equal(method.begin(), method.end(), "Minimum")) {
                        Minimum_Benchmark(binomialHeap);
                    }
                }
                cout << endl;
            }
        }
    }

    return 0;
}
