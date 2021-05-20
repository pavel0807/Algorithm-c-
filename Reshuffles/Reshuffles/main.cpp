#include <iostream>
#include "greyCode.hpp"
#include "lexicographic.h"
#include "transpozition/Transposition.hpp"
#include <ctime>
int main(int argc, const char * argv[]) {
    
    clock_t start =  clock(); // начальное время
        // здесь должен быть фрагмент кода, время выполнения которого нужно измерить

    CodеGrey(30);
    
    clock_t end = clock(); // конечное время
    //clock_t search_time = end_time - start_time; // искомое время
//
//        {
//            LogDuration("Second");
//            generateGreyCode(25);
//        }
    printf("The above code block was executed in %.4f second(s)\n", ((double) end - start) / ((double) CLOCKS_PER_SEC));
    
    start =  clock();
    generateGreyCode(30);
    end = clock();
    printf("The above code block was executed in %.4f second(s)\n", ((double) end - start) / ((double) CLOCKS_PER_SEC));
     return 0;
}
