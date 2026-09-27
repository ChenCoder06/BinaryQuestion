#include <iostream>
#include <algorithm>

bool binaryquestion(long long value,long long *arr,long long N,long long M);

int main()
{
    int N,M;
    std::cin >> N >> M;
    long long *arr = new long long[N];
    long long sum = 0;
    long long maxx = 0;
    for(int i = 0;i < N;i++)
    {
        std::cin >> arr[i];
        sum += arr[i];
        maxx = std::max(maxx,arr[i]);
    }
    long long left = maxx,right = sum;
    while(left < right)
    {
        long long mid = left + (right - left) / 2;
        if(binaryquestion(mid,arr,N,M))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    std::cout << left << std::endl;
    delete[] arr;
    return 0;
}

bool binaryquestion(long long value,long long *arr,long long N,long long M)
{
    long long sum = 0;
    int count =1;
    for(int i = 0;i<N;i++)
    {
        if(arr[i]>value)
            return false;
        if(sum + arr[i] <= value)
        {
            sum += arr[i];
        }
        else
        {
            count++;
            if(count > M)
                return false;
            sum = arr[i];
        }
    }
    return count <= M;
}