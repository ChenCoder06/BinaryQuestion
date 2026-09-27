#include <iostream>
#include <random>

int randomInt(int min,int max)
{
    static std::mt19937 engine(std::random_device{}());

    std::uniform_int_distribution<int> distribution(min,max);
    return distribution(engine);
}

int main()
{
    int min,max;
    std::cout << "输入最大值和最小值" << std::endl;
    std::cin >> min >> max;
    
    


    for(int i = 0;i < 100;i++)
    {
        std::cout << randomInt(min,max) << ' ';
    }

    return 0;
}