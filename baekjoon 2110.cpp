#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, C;         
	cin >> N >> C;

	int* home = new int[N + 1];

	for (int i = 1; i <= N; i++)
		cin >> home[i];             
	
	sort(home + 1, home + N + 1);   

	int s = 1, l = home[N] - home[1], res;  
                                            
	while (s <= l) 
	{
		int answer = (s + l) / 2, count = 1, pre_value = home[1];  
                                                                  
		for (int i = 2; i <= N; i++) 
		{
			if (home[i] - pre_value >= answer) 
			{
				count++;
				pre_value = home[i];
			}
			if (count == C)
				break;
		}

		if (count < C)
			l = answer - 1;
		else 
		{
			res = answer;        
			s = answer + 1;       
		}
	}

	cout << res;
	delete[] home;
}

