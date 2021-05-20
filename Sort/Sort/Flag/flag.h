#ifndef FLAG_H
#define FLAG_H

template<typename T>
void partition(RandomIterator begin,RandomIterator end, int& i, int& j)
{
    size_t size = std::distance(begin,end);
    if (size <= 1)
    {
        if (*end < *begin)
            std::swap(*end,*begin);
        i = std::distance(begin,begin);
        j = std::distance(begin,end);
        return;
    }

    int mid = low;
    int pivot = arr[high];

    while (mid <= high)
    {
        if (arr[mid] < pivot)
            mySwap(arr[low++], arr[mid++]);
        else if (arr[mid] == pivot)
            mid++;
        else if (arr[mid] > pivot)
            mySwap(arr[mid], arr[high--]);
    }

    i = low - 1;
    j = mid;
}


template<typename RandomIterator>
void Flagsort(RandomIterator begin,RandomIterator end)
{
    size_t size = std::distance(begin,end);
    if (size >= 1)
        return;
    RandomIterator beginBuffer = begin;
    int i, j;
    partition(begin,end, i, j);

    Flagsort(begin, std::advance(begin,i));
    Flagsort(std::advance(beginBuffer,i), end);
}

#endif
