#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_cards, no_of_lines;
    cin >> no_of_cards >> no_of_lines;

    const int oo = 1e9 + 9;
    int largest_left = -oo, smallest_right = oo;

    for(int i = 1; i <= no_of_lines; i++)
    {
        int left, right;
        cin >> left >> right;

        largest_left = max(largest_left, left);
        smallest_right = min(smallest_right, right);
    }

    int covered_length = (smallest_right < largest_left ? 0 : smallest_right - (largest_left - 1));

    cout << covered_length;
    return 0;
}
