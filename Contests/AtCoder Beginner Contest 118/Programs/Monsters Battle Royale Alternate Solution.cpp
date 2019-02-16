#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    multiset <int> H;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int health;
        cin >> health;
        H.insert(health);
    }

    while(H.size() > 1)
    {
        multiset <int> :: iterator it1 = H.begin();

        int smallest = (*it1);

        multiset <int> :: iterator it2 = (--H.end());

        int largest = (*it2);

        H.erase(it2);

        largest %= smallest;

        if(largest > 0)
            H.insert(largest);
    }

    multiset <int> :: iterator it = H.begin();
    int survivor = (*it);

    cout << survivor;
    return 0;
}
