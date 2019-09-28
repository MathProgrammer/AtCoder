#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_students;
    cin >> no_of_students;

    vector <int> position(no_of_students + 1, 0);
    for(int i = 1; i <= no_of_students; i++)
        cin >> position[i];

    vector <int> correct_order(no_of_students + 1, 0);
    for(int i = 1; i <= no_of_students; i++)
        correct_order[position[i]] = i;

    for(int i = 1; i <= no_of_students; i++)
        cout << correct_order[i] << " ";

    return 0;
}
