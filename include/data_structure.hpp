#pragma once

#include <list>

namespace itis {

    /**
     * Узел биномиального дерева (а потом и кучи)
     */
    struct Node final {
        int key{0};
        int value{0};
        int degree{0};
        Node *parent{nullptr};
        Node *child{nullptr};
        Node *sibling{nullptr};

        Node() = default;

        Node(int key, int value) : key{key}, value{value} {}

        ~Node() {
            value = 0;
            degree = 0;
            parent = nullptr;
            child = nullptr;
            sibling = nullptr;
        }
    };

    struct BinomialHeap {
    private:
        int size_{0};
        Node *root_{nullptr};

    public:

        /**
         * Создание новой пустой кучи
         */
        explicit BinomialHeap() = default;

        /**
         * удаление и высвобождение памяти
         */
        ~BinomialHeap();

        /**
         * вставка нового узла в биномиальную кучу
         * работает по типу создается новый узел с данными ключами и значениями
         * и объединяется с уже существующей кучей
         * @param key
         * @param value
         * @return
         */
        Node *Insert(int key, int value);

        /**
        * поиск минимального элемента кучи по ключу
        * @return минимальный элемент кучи по ключу (удивительно)
        */
        Node *Minimum() const;

        /**
         * Извлечение минимума
         *
         * 1. из всех корней отыскиваем корень с минимальным ключом и разрываем с ним связь
         * 2. создаем пустую кучу
         * 3. меняем порядок следования дочерних узлов удаленного корня на обратный, у каждого
         * дочернего узла обращаем parent в null
         * 4. устанавливаем заголовок созданной пустой кучи на первый элемент нового списка корней
         * 5. Сливаем кучи
         * @return минимальный по ключу узел
         */
        Node *ExtractMin();

        /**
         * Понижение приоритета узла
         *
         * уменьшаем значения ключа у узла
         * и если ключ становится меньше чем родительский, меняем их местами
         * и делаем так, пока возможно и пока не добрались до корня
         */
        void Decrease(Node *node, int key);

        /**
         * Удаление узла
         *
         * ты просто берешь
         * и удаляешь
         * узел
         *
         * комбинирует 2 метода сначала понижается степень ключа узла до минимального какое только может быть
         * затем производится ExtractMin соответсвенно этого узла
         * (((хитро? да, хитро)))
         */
        void Delete(Node *node);

        int size() const;

        Node *root();
    };

}  // namespace itis
