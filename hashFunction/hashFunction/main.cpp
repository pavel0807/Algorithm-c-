#include <iostream>
#include "Hash.h"
#include "UnivHash.h"

size_t Fun(size_t k, size_t m, size_t a, size_t b, size_t p)
{
    return k % 11;
}


int main(int argc, const char * argv[]) {
    size_t m = 11;
//
//    Hash<size_t, size_t(size_t, size_t, size_t, size_t, size_t)> hash(m, Fun);
//
//    hash.add(18);
//    hash.add(14);
//    hash.add(9);
//    hash.add(20);
//    hash.add(19);
//    hash.add(12);
//    hash.add(5);
//    hash.add(27);
//    hash.add(16);
//    hash.add(34);
//    hash.remove(9);
//
    HashNode<size_t>* findNode ;

    std::vector<size_t> num{18, 14, 9, 20, 19, 12, 5, 27, 16, 34};
    
    UnivHash<size_t, size_t(size_t, size_t, size_t, size_t, size_t)> hashUni(m, Fun, num);
    hashUni.add(192);

    HashNode<size_t>* findNodeUni = hashUni.search(27);

    findNode = hashUni.search(111);

    hashUni.remove(27);
    findNode = hashUni.search(27);
}
