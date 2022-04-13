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
        int minKey = root_list.front()->key;
        Node* node{root_list.front()->sibling};
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

    BinomialHeap* BinomialHeap::Merge(BinomialHeap heap1, BinomialHeap heap2) {
        std::list<Node*> h;
        Node* h1 = heap1.root_list.front();
        Node* h2 = heap2.root_list.front();
        while (h1 != nullptr && h2 != nullptr) {
            if (h1->degree <= h2->degree) {
                h.back()->sibling = h1;
                h.push_back(h1);
                h1 = h1->sibling;
            } else {
                h.back()->sibling = h2;
                h.push_back(h2);
                h2 = h2->sibling;
            }
        }
        while (h1 != nullptr) {
            h.back()->sibling = h1;
            h.push_back(h1);
            h1 = h1->sibling;
        }
        while (h2 != nullptr) {
            h.back()->sibling = h2;
            h.push_back(h2);
            h2 = h2->sibling;
        }
        BinomialHeap* binomialHeap = new BinomialHeap();
        binomialHeap->root_list = h;
        // тут пока что чисто первое условие биномиальной кучи выполняется
        return binomialHeap;
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
