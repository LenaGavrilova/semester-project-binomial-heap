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

  struct BinomialHeap {
  protected:
      int size_{0};
      int capacity_{0};
      std::list<Node*> root_list;

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
      BinomialHeap* Merge(BinomialHeap heap1, BinomialHeap heap2);

      /**
       * пока не понял че за метод такой интересный
       */
      void Decrease();

      void Delete();

      // геттеры

      int capacity() const;

      int size() const;
  };

}  // namespace itis
