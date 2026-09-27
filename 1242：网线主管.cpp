#include <iostream>
#include <algorithm>
#include <iomanip>

bool BinaryQuestion(int *arr,int N,int K,int value);


int main()
{
    int N,K;
    std::cin >> N >> K;
    int *arr = new int[N];
    int maxx = 0;
    for(int i=0;i<N;i++)
    {
        double x;
        std::cin >> x;
        arr[i] = (int)(x*100 + 0.5) ;
        maxx = std::max(maxx,arr[i]);
    }
    int left = 0,right = maxx;
    while(left < right)
    {
        int mid = left + (right - left+1) /2;
        if(BinaryQuestion(arr,N,K,mid))
        {
            left = mid; 
        }
        else
        {
            right = mid-1;
        }
    }
    if(left < 1)
        std::cout << "0.00" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(2) << left / 100.0<< std::endl;
    delete[] arr;
    return 0;
}

bool BinaryQuestion(int *arr,int N,int K,int value)
{
    long long count = 0;
    if(value <= 0)
    {
        return false;
    }
    for(int i =0;i<N;i++)
    {
        count += (int)(arr[i]/value);
        if(count >= K)
            return true;
    }
    return count >= K;
}