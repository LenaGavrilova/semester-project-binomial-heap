# Binomial Heap
В данном проекте реализутся структура данных под названием "Binomial heap".

Биномиальная куча представляет собой множество биномиальных деревьев, которые удовлетворяют следующим свойствам:
 * каждое биномиальное дерево в куче подчиняется свойству неубывающей кучи: ключ узла не меньше ключа его родительского узла (упорядоченное в соответствии со свойством неубывающей кучи дерево),
 * для любого неотрицательного целого k найдется не более одного биномиального дерева, чей корень имеет степень k, то есть все биномиальные деревья имеют разный размер.

Данная структура данных используется для реализации [priority queue.](https://en.wikipedia.org/wiki/Priority_queue#:~:text=In%20computer%20science%2C%20a%20priority,an%20element%20with%20low%20priority.)
Также биномиальная куча используется в [дискретно-событийном моделировании.](https://ru.wikipedia.org/wiki/%D0%94%D0%B8%D1%81%D0%BA%D1%80%D0%B5%D1%82%D0%BD%D0%BE-%D1%81%D0%BE%D0%B1%D1%8B%D1%82%D0%B8%D0%B9%D0%BD%D0%BE%D0%B5_%D0%BC%D0%BE%D0%B4%D0%B5%D0%BB%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5#:~:text=discrete%2Devent%20simulation%2C%20DES)

Все данные о проекте: [туть](https://drive.google.com/drive/folders/1XcATtVu8xDHlHDdta9sT6h_-edvn4emC?usp=sharing)

Для этой структуры должны быть возможны операции:
 * Make – создание новой пустой кучи,
 * Insert – вставка нового элемента в кучу,
 * Minimum – минимальный ключ,
 * ExtractMin – извлечение минимума,
 * Merge – слияние 2-х куч,
 * Decrease – уменьшение ключа,
 * Delete – удаление объекта.

Асимптотика перечисленных выше операций такова:
 * Make – O(1)
 * Merge – O(log N)
 * Insert – O(log N) – где N – количество элементов в куче.
 * Minimum – O(log N)
 * ExtractMin – O(log N)
 * Decrease – O(log N)
 * Delete – O(log N)


# Команда "Stopapupa"
Группа: 11-101
| Фамилия Имя | Вклад (%) | Прозвище |
|----------------|:---------:|----------------:|
| Пудова Анжела | 25 | вумен1 |
| Гаврилова Елена | 25 | вумен2 |
| Катаргина Ксения | 25 | вумен3 |
| Вергасов Шамиль | 25 | мен |

#### Девиз команды:
-Скажи: "стоп Аня"
-Но я вижу здесь по-другому: "стопапупа"


# Структура проекта
Проект состоит из следующих частей:

 * [src](https://github.com/LenaGavrilova/semester-project-binomial-heap/tree/main/src) / [include](https://github.com/LenaGavrilova/semester-project-binomial-heap/tree/main/include) - реализация структуры данных (исходный код и заголовочные файлы);
 * [benchmark](https://github.com/LenaGavrilova/semester-project-binomial-heap/tree/main/benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления, поиска и пр.);
 * [examples](https://github.com/LenaGavrilova/semester-project-binomial-heap/tree/main/examples) - примеры работы со структурой данных;
 * [dataset](https://github.com/LenaGavrilova/semester-project-binomial-heap/tree/main/dataset) - наборы данных для запуска контрольных тестов и их генерация;


# Требования
Рекомендуемые требования:

1. С++ компилятор c поддержкой стандарта C++17 (например, GNU GCC 8.1.x и выше).
2. Система автоматизации сборки CMake (версия 3.12.x и выше).
3. Интерпретатор Python (версия 3.7.x и выше).
4. Рекомендуемый объем оперативной памяти - не менее 8 ГБ.
5. Свободное дисковое пространство объемом ~ 3 ГБ (набор данных для контрольных тестов).

# Сборка и запуск
*Инструкция по сборке проекта, генерации тестовых данных, запуска контрольных тестов и примеров работы. (italic)*
#### Для Windows

##### Сборка проекта
Склонируйте проект к себе на устройство через [Git for Windows](https://git-scm.com/download/win) (либо используйте возможности среды разработки):
        
``` git clone https://github.com/LenaGavrilova/semester-project-binomial-heap.git ```

Для ручной сборки проекта в терминале введите:

 ``` # переход в папку с проектом
cd C:\Users\username\asd-projects\semester-project-binomial-heap

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```

##### Генерация готовых тестов 

Генерация тестового набора данных в формате [comma-seperated values (CSV)](https://ru.wikipedia.org/wiki/CSV) :
1. Откройте вашу среду разработки.
2. В директории dataset найдите файл generate.py и запустите его, например, с помощью правой кнопки мыши (проверьте, чтобы у вас был настроен интерпетатор python). После этого в директории `dataset` начнётся генерация тестовых данных. (или вы можете скачать их с гугл диска)
Данные будут организованы следующим образом:

``` 
dataset/
  insert/
    01/
      100.csv
      ...
      5000000.csv
    02/ ...
    03/ ...
    ...
    10/ ...
  extractMin/
    01/
      100.csv
      ...
      5000000.csv
    ...
    10/ ...
  ... 
  ```
  По названию директории /dataset/data/add можно понять, что здесь хранятся наборы данных для контрольных тестов по добавлению элементов в структуру данных. Названия файлов 100.csv. 5000000.csv и т.д. хранят информацию о размере набора данных (т.е. количество элементов).
  
  ##### Контрольные тесты
  
Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных.

| Название | Описание| Метрика |
|----------------|:---------:|----------------:|
| insert | добавление элемента| время |
| extractMin| нахождение минимума | время |
| merge | слияние двух куч | время |

##### Пример запуска
просто запускаете benchmark/benchmark.cpp, все описание и результаты тестов будут выведены в консоль

# Источники


1. https://habr.com/ru/post/135232/
2. https://neerc.ifmo.ru/wiki/index.php?title=Биномиальная_куча
3. https://itnan.ru/post.php?c=1&p=578252
4. https://vporoshok.me/post/2018/11/meldable-heaps/
5. https://www.youtube.com/watch?v=PzytwZRjjS8
