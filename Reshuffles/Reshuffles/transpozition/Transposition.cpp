#include "Transposition.hpp"
#include "lexicographic.h"

std::vector<std::vector<int>> PermTr(int n)
{
    std::vector<std::vector<int>> result;
    // Массив для текущей перестановки
    std::vector<int> shuffle;
    shuffle.resize(n+2);
    

    std::vector<int> shuffleReverse;
    shuffleReverse.resize(n+2);
    

    int *d = new int[n + 2];
    int m;

    // Инициализация векторов shuffle
    shuffle[0] = n + 1;
    shuffle[n + 1] = n + 1;

    m = n + 1;
    for (size_t i = 1; i <= n ; ++i) {
        shuffle[i] = shuffleReverse[i] = i;
        d[i] = -1;
    }
    
    d[1] = 0;
    
    while(m!=1)
    {
        result.push_back(std::vector<int>(shuffle.begin()+1,shuffle.end()-1));
        m = n;
        
        while(shuffle[shuffleReverse[m]+d[m]] > m)
        {
            d[m] = -d[m];
            m--;
        }
        swap(shuffle,shuffleReverse[m],shuffleReverse[m] + d[m]);
        swap(shuffleReverse,shuffle[shuffleReverse[m]],m);
    }
    return result;
}
