#include <iostream>
#include <vector>
#include <queue>
#include "data_structure.hpp"

// файл с определениями

namespace itis {

  // здесь должны быть определения методов вашей структуры

    /**
     * Объединение узлов в сестренские отношения
     * с учетом 1го условия биномиальной кучи и всех сестренских отношений каждого из узлов
     *
     * возвращает указатель на самый мелкий по ключу узел
     * из всех объединенных
     * @param node1 - узел 1
     * @param node2 - узел 2
     * @return - указатель на новый узел
     */
    inline Node* Root_List_Merge(Node* node1, Node* node2) {
        Node *h{nullptr};
        Node *newRoot{nullptr};
        Node *h1 = node1;
        Node *h2 = node2;
        while (h1 != nullptr && h2 != nullptr) {
            if (h1->degree <= h2->degree) {
                if (h == nullptr) {
                    h = h1;
                    newRoot = h;
                } else {
                    h->sibling = h1;
                    h = h1;
                }
                h1 = h1->sibling;
            } else {
                if (h == nullptr) {
                    h = h2;
                    newRoot = h;
                } else {
                    h->sibling = h2;
                    h = h2;
                }
                h2 = h2->sibling;
            }
        }
        while (h1 != nullptr) {
            if (h == nullptr) {
                h = h1;
                newRoot = h;
            } else {
                h->sibling = h1;
                h = h1;
            }
            h1 = h1->sibling;
        }
        while (h2 != nullptr) {
            if (h == nullptr) {
                h = h2;
                newRoot = h;
            } else {
                h->sibling = h2;
                h = h2;
            }
            h2 = h2->sibling;
        }
        return newRoot;
    }

    /**
     * связывание двух узлов биномиального дерева
     * node1 становится потомком node2
     * @param node1 - узел 1
     * @param node2 - узел 2
     */
    inline void BinomialTreeLink(Node *node1, Node *node2) {
        // node1 - child, node2 - parent
        node1->parent = node2;
        node1->sibling = node2->child;
        node2->child = node1;
        node2->degree++;
    }

    /**
     * Объединение узлов в сестренские отношения (с учетом таковых у самих узлов)
     * с учетом 1го и 2го условия биномиальной кучи
     *
     * возвращает указатель на самый мелкий по ключу узел
     * из всех объединенных
     * @param node1 - узел 1
     * @param node2 - узел 2
     * @return - указатель на новый узел
     */
    inline Node* BinomialHeapUnion(Node* heap1, Node* heap2) {
        Node* h = Root_List_Merge(heap1, heap2);
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
                BinomialTreeLink(next_x, x);
            } else {
                if (prev_x == nullptr) {
                    h = next_x;
                } else {
                    prev_x->sibling = next_x;
                }
                BinomialTreeLink(x, next_x);
                x = next_x;
            }
            next_x = x->sibling;
        }
        return h;
    }

    BinomialHeap::~BinomialHeap() {
        Node* currPtr = root_;
        std::vector<Node*> nodes;
        while (currPtr != nullptr) {
            std::queue<Node*> queue;
            queue.push(currPtr);
            while (!queue.empty()) {
                Node* current = queue.front();
                nodes.push_back(queue.front());
                queue.pop();

                if (current->child != nullptr) {
                    Node* tempPtr = current->child;
                    while (tempPtr != nullptr) {
                        queue.push(tempPtr);
                        tempPtr = tempPtr->sibling;
                    }
                }
            }
            currPtr = currPtr->sibling;
        }
        for (auto & node : nodes) {
            delete node;
        }
    }

    Node* BinomialHeap::Insert(int key, int value) {
        Node* node = new Node();
        node->key = key;
        node->value = value;
        node->degree = 0;
        node->parent = nullptr;
        node->child = nullptr;
        node->sibling = nullptr;
        root_ = BinomialHeapUnion(root_, node);
        size_++;
        return node;
    }

    Node* BinomialHeap::Minimum() const {
        int minKey = ~0U >> 1;
        Node* node = root_;
        Node* min_node = nullptr;
        while (node != nullptr) {
            if (node->key < minKey) {
                minKey = node->key;
                min_node = node;
            }
            node = node->sibling;
        }
        return min_node;
    }

    int BinomialHeap::ExtractMin() {
        Node* x = root_;
        Node* x_min = nullptr;
        int x_min_key = ~0U >> 1;
        Node* previous = nullptr;
        Node* previous_min = nullptr;
        while (x != nullptr) {
            if (x->key < x_min_key) {
                x_min_key = x->key;
                x_min = x;
                previous_min = previous;
            }
            previous = x;
            x = x->sibling;
        }
        if (previous_min != nullptr) {
            previous_min->sibling = x_min->sibling;
        } else {
            root_ = x_min->sibling;
        }

        Node* child = x_min->child;
        previous = nullptr;
        while (child != nullptr) {
            Node* sibling = child->sibling;
            child->sibling = previous;
            previous = child;
            child = sibling;
        }

        root_ = BinomialHeapUnion(root_, previous);
        size_--;
        return x_min->value;
    }

    void BinomialHeap::Decrease(Node* node, int newKey) {
        node->key = newKey;
        Node* y = node;
        Node* z = y->parent;
        while (z != nullptr and y->key < z->key) {
            int temp = y->key;
            y->key = z->key;
            z->key = temp;
            y = z;
            z = y->parent;
        }
    }

    inline constexpr auto kIntConstant = INT32_MIN;

    void BinomialHeap::Delete(Node* node) {
        Decrease(node, kIntConstant);
        ExtractMin();
    }

    int BinomialHeap::size() const {
        return size_;
    }

}  // namespace itis
