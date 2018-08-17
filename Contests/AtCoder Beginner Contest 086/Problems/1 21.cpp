#include <iostream>
using namespace std;

int get_value(string S)
{
	int value = 0;
	
	for(int i = 0; i < S.size(); i++)
	{
		value = value*10 + (S[i] - '0');
	}
	
	return value;
}

int main() 
{
	string A, B;
	cin >> A >> B;
	string N = A + B;
	
	int n = get_value(N);
	int is_square = false;
	
	for(int i = 1; i*i <= n; i++)
	{
		if(i*i == n)
			is_square = true;
	}
	
	cout << (is_square ? "Yes" : "No");
	return 0;
}
