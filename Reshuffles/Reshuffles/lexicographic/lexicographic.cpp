#include <stdio.h>
#include "lexicographic.h"

std::vector<std::vector<int>*> LexPermut(int n) {
    int i, j, leftPoint, rightPoint;
    
    std::vector<std::vector<int>*> result;
    
    // Массив для текущей перестановки
    std::vector<int> permut;
    permut.resize(n);
    
    // Формирование тождественной перестановки
    for (j = 0; j < n; ++j)
        permut[j] = j+1;
    
    
    for ( ; ; )
    {
        result.push_back(&permut);

        // Найти максимальное i, такое что
        for (i = n - 2; i > -1 && permut[i] > permut[i+1]; --i);
        
        if (i == -1)
            break;

        j = n - 1;
        
        while (permut[i] > permut[j])
            --j;

        // перевернуть
        swap(permut,i,j);
        
        leftPoint = i + 1;
        rightPoint = n - 1;
        
        while (rightPoint > leftPoint) {
            swap(permut, leftPoint++, rightPoint--);
        }
    }
    return result;
}

void swap(std::vector<int>& per,int indexFirst,int indexSecond)
{
    int  temp = per[indexSecond];
    per[indexSecond] = per[indexFirst];
    per[indexFirst] = temp;
}
