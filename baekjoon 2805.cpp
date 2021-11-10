#include <iostream>
#include <algorithm>

using namespace std;

int main(void) 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long N; 
    long long M; 
    long long arr[1000001] = { 0, };
    long long max = -1;

    cin >> N >> M;

    for (int i = 0; i < N; i++) 
	{
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int start = 0; 
    int end = arr[N - 1];
    int mid = 0; 

    while (start <= end) 
	{ 
        long long sum = 0;
        mid = (start + end) / 2;

        for (int i = 0; i < N; i++) 
		{
            if (arr[i] - mid > 0) 
                sum += (arr[i] - mid); 
        }

        if (sum >= M) 
		{
            start = mid + 1; 
            if (mid > max) 
			{ 
                max = mid;
            }
        }

        else 
		{
            end = mid - 1; 
        }
    }
    cout << max << '\n';

    return 0;
}


