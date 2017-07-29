#include <cstdio>
using namespace std;

int main()
{
	int number;
	scanf("%d", &number);

	int power = 0;
	while( (1 << power) <= number)
		power++;

	power--;
	printf("%d\n", (1 << power));
	return 0;
}
