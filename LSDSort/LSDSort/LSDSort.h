#ifndef LSDSort_h
#define LSDSort_h
#include <map>
#include <deque>

template<typename iterType>
void makeSortM(std::map<char, std::deque<iterType>>& sortM, std::deque<iterType>& work, int strLen)
{
    while (!work.empty())
    {
        auto itStr = work.front();
        sortM[(*itStr)[strLen]].push_back(itStr);
        work.pop_front();
    }
}

template<typename iterType>
void makeSortedWork(std::map<char, std::deque<iterType>>& sortM, std::deque<iterType>& work)
{
    auto itMap = sortM.begin();
    while (itMap != sortM.end())
    {
        auto itDeq = itMap->second;
        while (!itDeq.empty())
        {
            work.push_back(itDeq.front());
            itDeq.pop_front();
        }
        ++itMap;
    }
}

template<typename iterType>
void copySortedWorkToResult(iterType begin, iterType end, std::deque<iterType>& work)
{
    std::deque<std::iterator_traits<iterType>::value_type> valueDeq;
    auto it = work.begin();
    while (it != work.end())
        valueDeq.push_back(*(*it++));

    auto valIt = valueDeq.begin();
    while (valIt != valueDeq.end())
        *begin++ = *valIt++;
}

template<typename iterType>
int strLength(iterType strIt)
{
    std::string str(*strIt);
    return str.length();
}

template<typename iterType>
void addStrToWorkDeque(std::deque<iterType>& work, std::deque<iterType>& eqLenStr)
{
    auto deqIt = eqLenStr.begin();
    while (deqIt != eqLenStr.end())
        work.push_back(*deqIt++);
}

template<typename iterType>
void RadixLSD(iterType begin, iterType end)
{
    std::map<int, std::deque<iterType>> diffLenStr;
    iterType strIt = begin;
    while (strIt != end)
        diffLenStr[strLength(strIt)].push_back(strIt++);

    int currentStrLength = diffLenStr.rbegin()->first;
    std::deque<iterType> work;
    addStrToWorkDeque(work, diffLenStr[currentStrLength]);
    std::map<char, std::deque<iterType>>sortM;

    while (--currentStrLength >= 0)
    {
        auto it = diffLenStr.find(currentStrLength);
        if (it != diffLenStr.end())
            addStrToWorkDeque(work, diffLenStr[currentStrLength]);

        makeSortM(sortM, work, currentStrLength);
        makeSortedWork(sortM, work);
        sortM.clear();
    }

    copySortedWorkToResult(begin, end, work);
}

#endif
