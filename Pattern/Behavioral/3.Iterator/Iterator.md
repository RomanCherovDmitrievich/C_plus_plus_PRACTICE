# 3. Iterator (Итератор)
__Суть:__
Предоставляет способ последовательного доступа к элементам коллекции без раскрытия её внутреннего устройства.

## Задача
>_Шаблон проектирования итератор решает несколько задач, основные из которых:_
>_1. Предоставление пользователю возможности работать с элементами какого-либо контейнера;_
>_2. Избавление пользователя от необходимости работать с небезопасными указателями;_
>_3. Сокрытие от пользователя деталей реализации структуры узла множества._

## Диаграмма паттерна Итератор
<figure>
    <img src ="/assets/images/Diagram_Iterator.png" alt = "Iterator">
</figure>

## Пример
```c++
#include <iostream>
#include <vector>

template <typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual T next() = 0;
    virtual bool hasNext() = 0;
};

template <typename T>
class VectorIterator : public Iterator<T> {
    std::vector<T> data;
    size_t index = 0;
public:
    VectorIterator(const std::vector<T>& vec) : data(vec) {}
    T next() override { return data[index++]; }
    bool hasNext() override { return index < data.size(); }
};

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    VectorIterator<int> it(numbers);

    while (it.hasNext()) {
        std::cout << it.next() << " ";
    }
    return 0;
}
```

## Плюсы:
✅ Единый интерфейс для обхода разных коллекций.
✅ Скрывает детали реализации коллекции.

## Минусы:
❌ Избыточен для простых структур данных.

## Где применяется?
1. STL (std::vector::iterator).
2. Обход деревьев, графов.
3. Пользовательские коллекции.