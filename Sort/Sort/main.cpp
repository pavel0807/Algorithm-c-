//
//  main.cpp
//
//  Created by Pavel on 100.02.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "profile.h"
#include "flag.h"
size_t size=1000000;
int main(int argc, const char * argv[]) {
    std::vector<int> a ;
    for(size_t i=0;i<size;++i)
    {
        a.push_back(rand()%10);
    }
    Flagsort(a.begin(), a.end());
    return 0;
}

//
//Сортировка Шелла
//#include "SortingShell.h"
//#include "DifferentSequences.h"
//int main(int argc, const char * argv[]) {
//    std::vector<int> a = {12,3232,323232,132131,3212312,12312312,1,232322222};
//    std::vector<int> b = createSequenceWithOne(a.size());
//    Sort(a,b,[](int a,int b){return a<b;});
//    PrintResult(a);
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << std::endl;
////
////    std::vector<int> a1 = {12,3232,323232,132131,3212312,12312312,1,232322222};
////    std::vector<int> c = createSequenceWithOne(a.size());
////    Sort(a1,c,[](int a,int b){return a<b;});
////    PrintResult(a);
////    std::cout << std::endl;
////    std::cout << std::endl;
////    std::cout << std::endl;
////
////    std::vector<int> a2 = {12,3232,323232,132131,3212312,12312312,1,232322222};
////    std::vector<int> d = createSequenceWithTwo(a.size());
////    Sort(a2,d,[](int a,int b){return a<b;});
////
////    std::cout << "Hello, World!\n";
//    return 0;
///Сортировка быстрая
//std::vector<int> a = {1,2,3,4,5,6,7,8,9,100};
//qSort(a.begin(), a.end(), [](int a,int b){return a>b;});
//for(size_t i =0;i<a.size();++i)
//{
//    std::cout <<a[i] <<std::endl;
//}
//}




/*
 
 std::vector<int> a = {1,2,0,1,1,1,0,0,0,1,2,2,2,1,0,1,0,2,0,1,1};
 
 netherlandsFlag(a.begin(), a.end());
 
 for(size_t i =0;i<a.size();++i)
 {
     std::cout <<a[i] <<std::endl;
 }
 return 0;
 */


/*
 Heap sort
 
 std::vector<int> arr = {12, 11, 13, 5, 6,1,2,3,123312,1223,2323232,3231312,0,4,7,8,9,14};

 heapSort(arr.begin(),arr.end());

 cout << "Sorted array is \n";
 printArray(arr.begin(),arr.end());

 */




/*
 int* a = new int[size];
 for(int i=0;i<size;++i)
 {
     a[i]= rand()%256;
 }
 Flagsort(a, 0, size-1);
 for(size_t i=0;i<size;++i)
 {
     std::cout << a[i];
 }
 delete[] a;
 */
