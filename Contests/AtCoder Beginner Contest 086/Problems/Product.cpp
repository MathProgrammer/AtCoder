#include <iostream>
using namespace std;

int main() 
{
	int A, B;
	cin >> A >> B;
	cout << ((A*B)%2 == 0 ? "Even" : "Odd");
	return 0;
}
