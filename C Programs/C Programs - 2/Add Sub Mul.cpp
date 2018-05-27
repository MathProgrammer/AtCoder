#include <iostream>
using namespace std;

#define max(a, b) (a > b ? a : b)
#define max_3(a, b, c) max(a, max(b, c))

int main()
{
	int A, B;
	cin >> A >> B;
	cout << max_3(A + B, A - B, A*B);
	return 0;
}
