#include <iostream>

bool check(int * arr,int N,int M,int L,int value);


int main()
{
    int L,N,M;
    std::cin >> L >> N >> M;
    int *arr = new int[N];
    for(int i=0;i<N;i++)
    {
        std::cin >> arr[i];
    }
    int left = 1 ,right = L,ans = 0;
    while(left <= right)
    {
        int mid = left + (right - left ) / 2;
        if(check(arr,N,M,L,mid))
        {
            ans = mid;
            left = mid +1;
        }
        else
        {
            right = mid - 1;
        }
    }
    std::cout << ans << std::endl;
    delete[] arr;
    return 0;
}

bool check(int * arr,int N,int M,int L,int value)
{
    int count = 0,last = 0;
    for(int i = 0;i<N;i++)
    {
        if(arr[i] - last < value)
        {
            count ++;
            if(count > M)
            {
                return false;
            }
        }
        else
        {
            last = arr[i];
        }
        
    }
    if(L - last < value)
    {
        count ++;
    }
    return count <= M;
}