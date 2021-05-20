#ifndef SortShell_h
#define SortShell_h

#include <cmath>

//Алгоритм Шелла
template<typename RandomIterator,typename Compare,typename offsetIterator>
void ShellSorting(RandomIterator first,RandomIterator last,Compare comp,offsetIterator beginOffset,offsetIterator endOffset )
{
    for(auto offset = endOffset; offset >= beginOffset;offset--)
            for (auto i = first + *offset; i != last; ++i)
                for (auto j = i; j - first >= *offset && comp(*j, *(j - *offset)); j -= *offset)
                    std::swap(*j, *(j - *offset));
}



//Вычисление номера элемента массива отклонения
template<typename T>
size_t CurrentElement(const T& array,long size)
{
    size_t currentNumber = 0;
    while(3*array[currentNumber] < size)
    {
        currentNumber++;
    }

    return currentNumber;
}

//Главная функция сортировки
template<typename T,typename K,typename Compare>
void SortShell(T& array,K& arrayOffset,Compare comp)
{
    const size_t size =array.size();
    ShellSorting(array.begin(),array.end(),comp,arrayOffset.begin(),arrayOffset.begin()+CurrentElement<T>(arrayOffset,size));
}

//Вывод на экран
template<typename T>
void PrintResult(const T& array)
{
    for(size_t i =0 ;i<array.size();++i)
    {
        std::cout << array[i] << std::endl;
    }
}
//Вывод на экран
//
////template<typename RandomIterator>
//void PrintResult(std::__wrap_iter<int*> first,std::__wrap_iter<int*> last)
//{
//    for(auto i = first ;i!= last;i++)
//    {
//        std::cout << *i << std::endl;
//    }
//}



#endif /* SortShell_h */
