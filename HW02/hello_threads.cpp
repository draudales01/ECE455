#include <iostream>
#include <thread>
#include <vector>

void hello(int id, int total){
std::cout << "Hello from thread " << id << " of " << total << "\n";
}
int main()
{
    const int N = 10;
    std::vector<std::thread> threads;
    threads.reserve(N);
    for(int i = 0; i < N; ++i)
    {
        threads.emplace_back(hello,i,N);
    }

    for(auto& thread : threads)
    {
        thread.join();
    }
    return 0;
}
