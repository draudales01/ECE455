#include <iostream>
#include <vector>
#include <omp.h>

int main()
{
    const int N = 1024;

    std::vector<std::vector<int>> A(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> B(N, std::vector<int>(N, 2));
    std::vector<std::vector<int>> RESULT(N, std::vector<int>(N, 0));

    #pragma omp parallel for
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++)
       {
        int sum = 0;
        for(int k = 0; k < N; k++)
        {
            sum += A[row][k] * B[k][col];
        }
        RESULT[row][col] = sum;

       }
       
    }
    
    std::cout << "RESULT[0][0] = " << RESULT[0][0] << std::endl;


    return 0;
}
