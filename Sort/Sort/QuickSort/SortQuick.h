//
//  quickSort.h
//  Sort
//
//  Created by Pavel on 13.02.2021.
//
#ifndef SortQuick_h
#define SortQuick_h
#include <stack>
//Функция вычисляюща номер жлемента,являющаяся медиану первого последнего и среднего элемента
template<typename RandomIterator, typename Compare>
void Partition(RandomIterator first,RandomIterator last,Compare comp)
{
    auto pivot = std::prev(last, 1);
    std::swap(*first, *pivot);
} 



//Осносвная функция сортивки

template<typename RandomIterator, typename Compare>
void qSort(RandomIterator first,RandomIterator last,Compare comp)
{
//    if (std::distance(first, last)>1){
//        RandomIterator bound = Partition(first, last,comp);
//        qSort(first, bound, comp);
//        qSort(bound+1, last, comp);
//    }
    
    RandomIterator itL = first;
    RandomIterator itR = last;
    std::stack<RandomIterator> stack;
    stack.push(last);
    stack.push(first);
    auto pivot = *itL, temp = *itL;
    while(!stack.empty())
    {
        
        first = stack.top();
        stack.pop();
        last = stack.top();
        stack.pop();
        
        //Partition(first, last,comp);
        //std::swap(*first,*(last));
        if (last <= first)
            continue;
        itL = first + 1;
        itR = last;
        pivot = *first;
        while (true)
        {
            while(itL < itR && *itL <= pivot)
                ++itL;
            while(itR >= itL && *itR > pivot)
                --itR;
            if(itL < itR)
                std::swap(*itL++, *itR--);
            else
                break;
        }
        *first = *itR;
        *itR = pivot;
        
        stack.push(itR - 1);
        stack.push(first);
        stack.push(last);
        stack.push(itR + 1);
    }
    
}

template<typename RandomIterator>
void netherlandsFlag(RandomIterator first,RandomIterator last)
{
    auto itLeft  = first;
    auto itMid   = first;
    auto itRight = --last;
    while(itMid <= itRight)
    {
        if(*itMid == 0 )
        {
            std::swap(*itMid,*itLeft);
            itMid++,itLeft++;
            continue;
        }
        if(*itMid == 1 )
        {
            ++itMid;
            continue;
        }
        if(*itMid == 2)
        {
            std::swap(*itMid,*itRight);
            --itRight;
            continue;
        }
    }
}

#endif /* SortQuick_h */
