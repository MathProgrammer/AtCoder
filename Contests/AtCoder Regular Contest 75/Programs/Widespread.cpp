#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
typedef long long LL;
using namespace std;

int ceil(LL numerator, LL denominator)
{
	return (numerator/denominator + (numerator%denominator != 0));
}

int possible(vector <LL> H, LL A, LL B, LL explosions)
{
	for(int i = 1; i < H.size(); i++)
	{
		H[i] -= (explosions*B);
	}

	LL explosions_used = 0;
	for(int i = H.size() - 1; i > 0 && H[i] > 0; i--)
	{
		explosions_used += ceil(H[i], A - B);
	}

	return (explosions_used <= explosions);
}

int main()
{
    int no_of_monsters, A, B;
    cin >> no_of_monsters >> A >> B;

    vector <LL> health(no_of_monsters + 1);
    for(int i = 1; i <= no_of_monsters; i++)
    	cin >> health[i];

    sort(all(health));

    int left = 1, right = 1e9;
    while(left <= right)
    {
    	int mid = (left + right) >> 1;

    	if(possible(health, A, B, mid))
    	{
    		if(mid == left || !possible(health, A, B, mid - 1))
    		{
    			cout << mid;
    			break;
    		}
    		else
    		{
    			right = mid - 1;
    		}
    	}
    	else
    	{
    		left = mid + 1;
    	}
    }
	return 0;
}

