#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin() + 1, (v).end()
using namespace std;

struct info
{
    int start, end;

    int operator<(info &A)
    {
        return(A.end == end ? start < A.start : end < A.end);
    }
};

int main()
{
    int no_of_vertices, no_of_segments;
    scanf("%d %d", &no_of_vertices, &no_of_segments);

    vector <info> segments(no_of_segments + 1);
    for(int i = 1; i <= no_of_segments; i++)
        scanf("%d %d", &segments[i].start, &segments[i].end);

    sort(all(segments));

    int no_of_deleted_bridges = 0, last_deleted = 0;
    for(int i = 1; i <= no_of_segments; i++)
    {
        if(segments[i].start > last_deleted)
        {
            last_deleted = segments[i].end - 1;
            no_of_deleted_bridges++;
        }
    }

    printf("%d\n", no_of_deleted_bridges);
    return 0;
}
