#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int no_of_numbers;
    scanf("%d", &no_of_numbers);

    set <int> number;
    for(int i = 1; i <= no_of_numbers; i++)
    {
        int number_i;
        scanf("%d", &number_i);

        if(number.count(number_i) == 1)
            number.erase(number_i);
        else
            number.insert(number_i);
    }

    printf("%u\n", number.size());
    return 0;
}
