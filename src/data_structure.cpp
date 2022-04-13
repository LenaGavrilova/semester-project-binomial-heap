#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "data_structure.hpp"

// файл с определениями

namespace itis {

  // здесь должны быть определения методов вашей структуры

    BinomialHeap::~BinomialHeap() = default;

    bool BinomialHeap::Insert(int key, int value) {
        return false;
    }

    int BinomialHeap::Minimum() const {
        int minKey = root_->key;
        Node* node{root_->sibling};
        while (node != nullptr) {
            if (node->key < minKey) {
                minKey = node->key;
            }
            node = node->sibling;
        }
        return minKey;
    }

    std::optional<int> BinomialHeap::ExtractMin() {
        return std::nullopt;
    }



    void BinomialHeap::Decrease() {

    }

    void BinomialHeap::Delete() {

    }

    int BinomialHeap::size() const {
        return size_;
    }

}  // namespace itis
