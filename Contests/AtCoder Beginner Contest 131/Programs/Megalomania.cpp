#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct event
{
    int time, deadline;

    event(){}

    event(int t, int d)
    {
        time = t, deadline = d;
    }

    const int operator <(const event &E)
    {
        return (deadline < E.deadline);
    }
};

int main()
{
    int no_of_events;
    cin >> no_of_events;

    vector <event> E(no_of_events);
    for(int i = 0; i < no_of_events; i++)
    {
        cin >> E[i].time >> E[i].deadline;
    }

    sort(all(E));

    int time_now = 0, possible = true;
    for(int i = 0; i < no_of_events; i++)
    {
        time_now += E[i].time;

        if(time_now > E[i].deadline)
            possible = false;
    }

    cout << (possible ? "Yes" : "No");
    return 0;
}
