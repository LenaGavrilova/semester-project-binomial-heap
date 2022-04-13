#pragma once

// Заголовочный файл с объявлением структуры данных

#include <optional>
#include <list>

namespace itis {

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

  struct BinomialHeap {
  public:
      int size_{0};
      Node* root_{nullptr};

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
      bool Insert(int key, int value);

      /**
      * поиск минимального ключа кучи
      * @return минимальный ключ кучи (удивительно)
      */
      int Minimum() const;

      std::optional<int> ExtractMin();

      /**
       * пока не понял че за метод такой интересный
       */
      void Decrease();

      void Delete();

      // геттеры

      int size() const;
  };

}  // namespace itis
