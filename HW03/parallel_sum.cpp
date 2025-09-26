#include <iostream>
#include <vector>
#include <omp.h>

int main()
{
    const int ASIZE= 1000000;
    std::vector<int> data(ASIZE,1);
    long long sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for(int i=0; i<ASIZE; i++){
        sum += data[i];
    }

    std::cout << "Sum = " << sum << std::endl;

    return 0;
}
