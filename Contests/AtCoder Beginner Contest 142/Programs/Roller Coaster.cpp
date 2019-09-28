#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_students, height;
    cin >> no_of_students >> height;

    int tall_students = 0;
    while(no_of_students--)
    {
        int height_here;
        cin >> height_here;

        tall_students += (height_here >= height);
    }

    cout << tall_students;
    return 0;
}
