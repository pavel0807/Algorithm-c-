//
//  Sequences.h
//  Sort
//
//  Created by Pavel on 13.02.2021.
//

#ifndef Sequences_h
#define Sequences_h


#include <vector>
#include <cmath>

//h(j) = 3*h(j-1)+1
std::vector<int> createSequenceWithOne(const size_t& size)
{
    std::vector<int> result;
    result.push_back(1);
    for(size_t i = 1;i<size;++i)
    {
        result.push_back(3*result[i-1] + 1);
    }
    return result;
}


//h(j) = 3*h(j-1)+2
std::vector<int> createSequenceWithTwo(const size_t& size)
{
    std::vector<int> result;
    result.push_back(1);
    for(size_t i = 1;i<size;++i)
    {
        result.push_back(3*result[i-1] + 2);
    }
    return result;
}

//Exponent
std::vector<int> createDifferentSequence(const size_t& size)
{
    std::vector<int> result;
    result.push_back(1);
    for(size_t i = 1;i<size;++i)
    {
        if(i%2 ==0)
            result.push_back(9*std::pow(2,i)-9*std::pow(2,i/2)+1);
        else
            result.push_back(8*std::pow(2,i)-6*std::pow(2,(i+1)/2)+1);
    }
    return result;
}

#endif /* Sequences_h */
