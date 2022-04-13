#pragma once

// Заголовочный файл с объявлением структуры данных

#include <optional>
#include <list>

namespace itis {

  // Пример: объявление константы времени компиляции в заголовочном файле
  inline constexpr auto kStringConstant = "Hello, stranger!";

    struct Node final {
        int key{0};
        int value{0};
        int degree{0};
        Node* parent{nullptr};
        Node* child{nullptr};
        Node* sibling{nullptr};

        Node() = default;
        Node(int key, int value) : key{key}, value{value} {}
  };

    void binomialTreeLink(Node *node1, Node *node2) {
        // node1 - child, node2 - parent
        node1->parent = node2;
        node1->sibling = node2->child;
        node2->child = node1;
        node2->degree++;
    }

  struct BinomialHeap {
  public:
      int size_{0};
      Node* root_{nullptr};

  public:

      /**
       * Создание новой пустой кучи
       */
      explicit BinomialHeap() = default;

      ~BinomialHeap();

      bool Insert(int key, int value);

      /**
      * поиск минимального ключа кучи
      * @return минимальный ключ
      */
      int Minimum() const;

      std::optional<int> ExtractMin();

      /**
       * Слияние двух куч (пока хз как работает просто объявляю)
       * @param heap1 - куча 1))))
       * @param heap2 - куча 2
       * @return true если слились и false если разлились
       */
      BinomialHeap* Root_List_Merge(BinomialHeap heap1, BinomialHeap heap2);

      /**
       * пока не понял че за метод такой интересный
       */
      void Decrease();

      void Delete();

      // геттеры

      int size() const;
  };

    BinomialHeap* Root_List_Merge(BinomialHeap heap1, BinomialHeap heap2) {
        Node *h;
        Node *h1 = heap1.root_;
        Node *h2 = heap2.root_;
        while (h1 != nullptr && h2 != nullptr) {
            if (h1->degree <= h2->degree) {
                h->sibling = h1;;
                h1 = h1->sibling;
            } else {
                h->sibling = h2;
                h2 = h2->sibling;
            }
        }
        while (h1 != nullptr) {
            h->sibling = h1;
            h1 = h1->sibling;
        }
        while (h2 != nullptr) {
            h->sibling = h2;
            h2 = h2->sibling;
        }
        BinomialHeap* binomialHeap = new BinomialHeap();
        binomialHeap->root_ = h;
        binomialHeap->size_ = heap1.size_ + heap2.size_;
        return binomialHeap;
    }

    BinomialHeap* BinomialHeapUnion(BinomialHeap heap1, BinomialHeap heap2) {
        Node* h = Root_List_Merge(heap1, heap2)->root_;
        Node* prev_x = nullptr;
        Node* x = h;
        Node* next_x = x->sibling;
        while (next_x != nullptr) {
            if (x->degree != next_x->degree ||
                (next_x->sibling != nullptr and next_x->sibling->degree == x->degree)) {
                prev_x = x;
                x = next_x;
            } else if (x->key <= next_x->key) {
                x->sibling = next_x->sibling;
                binomialTreeLink(next_x, x);
            } else {
                if (prev_x == nullptr) {
                    h = next_x;
                } else {
                    prev_x->sibling = next_x;
                }
                binomialTreeLink(x, next_x);
                x = next_x;
            }
            next_x = x->sibling;
        }
        BinomialHeap* binomialHeap = new BinomialHeap();
        binomialHeap->root_ = h;
        binomialHeap->size_ = heap1.size_ + heap2.size_;
        return binomialHeap;
    }

}  // namespace itis
