#include <iostream>
#include "data_structure.hpp"

int main(int argc, char *argv[]) {
    itis::BinomialHeap* binomialHeap = new itis::BinomialHeap();
    binomialHeap->Insert(10, 20);
    binomialHeap->Insert(12, 200);
    binomialHeap->Insert(13, 200);
    binomialHeap->Insert(14, 200);
    std::cout << binomialHeap->root_->child->child->key;
    return 0;
}
