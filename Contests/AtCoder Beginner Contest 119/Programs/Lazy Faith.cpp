#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

typedef long long LL;
const LL oo = 1e18;

struct Query
{
    int index;
    LL position;
    LL left_most_shrine, left_most_temple;
    LL right_most_temple, right_most_shrine;

    Query(LL p, int i)
    {
        position = p, index = i;

        left_most_temple = -oo, left_most_shrine = -oo;
        right_most_temple = oo, right_most_shrine = oo;
    }

    int operator <(const Query &Q)
    {
        return (position < Q.position);
    }
};

int main()
{
    int no_of_temples, no_of_shrines, no_of_queries;
    cin >> no_of_temples >> no_of_shrines >> no_of_queries;

    vector <LL> temple(no_of_temples + 2, 0);
    for(int i = 1; i <= no_of_temples; i++)
        cin >> temple[i];

    temple[0] = -oo, temple[no_of_temples + 1] = oo;
    sort(all(temple));

    vector <LL> shrine(no_of_shrines + 2, 0);
    for(int i = 1; i <= no_of_shrines; i++)
        cin >> shrine[i];

    shrine[0] = -oo, shrine[no_of_shrines + 1] = oo;
    sort(all(shrine));

    vector <Query> query(no_of_queries + 1, Query(0, 0));
    for(int i = 1; i <= no_of_queries; i++)
    {
        LL position;
        cin >> position;

        query[i] = Query(position, i);
    }

    sort(all(query));

    int right_temple = no_of_temples + 1, right_shrine = no_of_shrines + 1;

    for(int current_query = no_of_queries; current_query >= 1 ;current_query--)
    {
        while(query[current_query].position <= temple[right_temple - 1])
            right_temple--;

        while(query[current_query].position <= shrine[right_shrine - 1])
            right_shrine--;

        query[current_query].right_most_temple = temple[right_temple];
        query[current_query].right_most_shrine = shrine[right_shrine];
    }

    int left_temple = 0, left_shrine = 0;

    for(int current_query = 1; current_query <= no_of_queries; current_query++)
    {
        while(temple[left_temple + 1] <= query[current_query].position)
            left_temple++;

        while(shrine[left_shrine + 1] <= query[current_query].position)
            left_shrine++;

        query[current_query].left_most_temple = temple[left_temple];
        query[current_query].left_most_shrine = shrine[left_shrine];
    }

    vector <LL> answer(no_of_queries + 1, 0);
    for(int i = 1; i <= no_of_queries; i++)
    {
        LL going_only_right = max(query[i].right_most_temple, query[i].right_most_shrine) - query[i].position;
        LL going_only_left = query[i].position - min(query[i].left_most_temple, query[i].left_most_shrine);

        LL one_way = min(going_only_left, going_only_right);

        LL right_first_then_left = min(2*(query[i].right_most_temple - query[i].position) + query[i].position - query[i].left_most_shrine,
                                       2*(query[i].right_most_shrine - query[i].position) + query[i].position - query[i].left_most_temple);

        LL left_first_then_right = min(2*(query[i].position - query[i].left_most_temple) + query[i].right_most_shrine - query[i].position,
                                       2*(query[i].position - query[i].left_most_shrine) + query[i].right_most_temple - query[i].position);

        LL two_way = min(right_first_then_left, left_first_then_right);

        answer[query[i].index] = min(one_way, two_way);
    }

    for(int i = 1; i <= no_of_queries; i++)
        cout << answer[i] << "\n";

    return 0;
}
