#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "data_structure.hpp"

// файл с определениями

namespace itis {

  // здесь должны быть определения методов вашей структуры

    BinomialHeap::BinomialHeap(int capacity) {
        throw std::runtime_error("unsupported operation");
    }

    BinomialHeap::~BinomialHeap() = default;

    bool BinomialHeap::Insert(int key, int value) {
        return false;
    }

    int BinomialHeap::Minimum() const{
        int minKey = root->key;
        Node* node{root->sibling};
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

    bool BinomialHeap::merge(BinomialHeap heap1, BinomialHeap heap2) {
        return false;
    }

    void BinomialHeap::Decrease() {

    }

    void BinomialHeap::Delete() {

    }

    int BinomialHeap::capacity() const {
        return capacity_;
    }

    int BinomialHeap::size() const {
        return size_;
    }


}  // namespace itis
