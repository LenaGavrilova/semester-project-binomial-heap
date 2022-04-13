#include <stdexcept>
#include "data_structure.hpp"

// файл с определениями

namespace itis {

  // здесь должны быть определения методов вашей структуры

    BinomialHeap::BinomialHeap(int capacity) {
        if (capacity <= 0) {
            throw std::invalid_argument("capacity must be positive");
        }
        size_ = 0;
        capacity_ = capacity;

        data_ = new Node[capacity_];

        std::fill(data_, data_ + capacity_, Node{});
    }

    BinomialHeap::~BinomialHeap() {
        size_ = 0;
        capacity_ = 0;

        delete[] data_;
        data_ = nullptr;
    }

    bool BinomialHeap::Insert(int key, int value) {
        throw std::runtime_error("unsupported operation");
    }

    std::optional<int> BinomialHeap::Extract() {
        throw std::runtime_error("unsupported operation");
    }

    bool BinomialHeap::Remove(int key) {
        throw std::runtime_error("unsupported operation");
    }

    void BinomialHeap::Clear() {
        throw std::runtime_error("unsupported operation");
    }

    std::optional<int> BinomialHeap::Search(int key) const {
        throw std::runtime_error("unsupported operation");
    }

    bool BinomialHeap::Contains(int key) const {
        throw std::runtime_error("unsupported operation");
    }

    bool BinomialHeap::IsEmpty() const {
        throw std::runtime_error("unsupported operation");
    }

    int BinomialHeap::capacity() const {
        throw std::runtime_error("unsupported operation");
    }

    int BinomialHeap::size() const {
        throw std::runtime_error("unsupported operation");
    }

    bool BinomialHeap::merge(BinomialHeap heap1, BinomialHeap heap2) {
        throw std::runtime_error("unsupported operation");
    }

    void BinomialHeap::sift_up(int index) {
        throw std::runtime_error("unsupported operation");
    }

    void BinomialHeap::heapify(int index) {
        throw std::runtime_error("unsupported operation");
    }

    std::optional<int> BinomialHeap::search_index(int key) const {
        throw std::runtime_error("unsupported operation");
    }


}  // namespace itis
