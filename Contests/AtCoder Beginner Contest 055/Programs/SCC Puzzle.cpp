#include <iostream>
using namespace std;

int main() 
{
	long long S, C;
	cin >> S >> C;
	
	long long no_of_pieces = min(S, C/2);
	
	S -= no_of_pieces;
	C -= 2*no_of_pieces;
	
	no_of_pieces += C/4;
	
	cout << no_of_pieces;
	return 0;
}
