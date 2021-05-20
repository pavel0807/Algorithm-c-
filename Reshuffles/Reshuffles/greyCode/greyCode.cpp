#include "greyCode.hpp"
#include <iostream>
std::vector<std::vector<int>> generateGreyCode(size_t size)
{
    std::vector<std::vector<int>> result;
    int * shuffle = new int[size+1];
    int * buffer = new int[size+1];
    
    for(int i=0;i<size+1;++i)
    {
        shuffle[i]=0;
        buffer[i] = i+1;
    }
    
    int i=0;
    
    while(i < size+1)
    {
        result.push_back(std::vector<int>(shuffle.begin()+1,shuffle.end()));
        
        i = buffer[0];
        
        shuffle[i] == 1 ? shuffle[i] = 0 : shuffle[i] = 1;
        
        buffer[0]=1;
        buffer[i-1] = buffer[i];
        buffer[i] = i+1;
    }
    
    return result;
}
std::vector<std::vector<int>> Comb(int n, int k)
{
    std::vector<std::vector<int>> result;
    std::vector<int> shuffle;
    shuffle.resize(k+1);

    int i, j;
    shuffle[0] = -1;
    for (i = 1; i < k + 1; ++i)
        shuffle[i] = i;
    j = 1;
    while (j > 0) {
        // Вывод полученного сочетания
        result.push_back(std::vector<int>(shuffle.begin()+1,shuffle.end()));
        j = k;
        while (shuffle[j] == n + j -k)
            --j;
        ++shuffle[j];
        for (i = j + 1; i < k + 1; ++i)
            shuffle[i] = shuffle[i-1] + 1;
    }
    return result;
}

void CodеGrey(int n) {
    int * Stack = new int [n];    // Стек
    int top = -1;    // Вершина стека

    // Массив для текущего вектора кода Грея
    int * G = new int[n];
    int i, j, k, m;

    // Инициализация кода Грея и заполнение
    // рабочего стека
    for (i = n ; i > 0; --i) {
        G[i] = 0;
        Stack[++top] = i;
    }

    // Формирование кода Грея
    while (top >= 0) {
        // Готовый вектор выводим на экран
//        for (i = 0; i < n; ++i)
//            std::cout << G[i] << " ";
//        std::cout << std::endl;

        // Определяем позицию, в которой
        // следующий вектор отличается
        // от текущего
        i = Stack[top--];

        // Инвертируем значение булевой
        // переменной
        G[n - i] = (G[n - i] + 1) % 2;

        // Заносим в стек индексы позиций для
        // дальнейших преобразований
        for (j = i - 1; j > 0; --j)
            Stack[++top] = j;
    }

}
