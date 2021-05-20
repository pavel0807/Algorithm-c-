// Реализация пирамидальной сортировки на C++
#include <iostream>

using namespace std;

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

template<typename RandomIterator>
void heapify(RandomIterator begin,RandomIterator end, long i)
{
    //размер массива
    long int size = std::distance(begin, end);
    
    //инициализируем переменные для построения дереваr
    long largest = i;
    long l = 2*i + 1; // левый = 2*i + 1
    long r = 2*i + 2; // правый = 2*i + 2
    
    // Если левый дочерний элемент больше корня
    if (l < size && *(begin+l) > *(begin+largest))
        largest = l;

   // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < size &&*(begin+r) > *(begin+largest))
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        //меняем местами текущий и наибольший
        swap(*(begin+i), *(begin+largest));

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(begin,end, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
template<typename RandomIterator>
void heapSort(RandomIterator begin,RandomIterator end)
{
    long int size = std::distance(begin, end);
    
    // Построение кучи (перегруппируем массив)
    for (long int i = size / 2 - 1; i >= 0; i--)
        heapify(begin,end, i);

    
   // Один за другим извлекаем элементы из кучи
   for (long int i=size-1; i>=0; i--)
   {
       // Перемещаем текущий корень в конец
       swap(*begin, *(begin+i));

       // вызываем процедуру heapify на уменьшенной куче
       heapify(begin, begin+i, 0);
   }
}


//Вспомогательная функция для вывода на экран массива размера n
template<typename RandomIterator>
void printArray(RandomIterator begin,RandomIterator end)
{
    for (auto it = begin;it!=end;++it)
        cout << *it << " ";
    cout << "\n";
}
