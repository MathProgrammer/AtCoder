#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct Move
{
    int start_x, start_y, end_x, end_y;

    Move(){}

    Move(int x1, int y1, int x2, int y2)
    {
        start_x = x1, start_y = y1, end_x = x2, end_y = y2;
    }

    void display()
    {
        printf("%d %d %d %d\n", start_x, start_y, end_x, end_y);
    }
};

const int MAX_N = 505;

int grid[MAX_N][MAX_N];

int main()
{
    int rows, columns;
    scanf("%d %d", &rows, &columns);

    memset(grid, 0, sizeof(grid));

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    vector <Move> moves;
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j < columns; j++)
        {
            if(grid[i][j]%2 == 0) continue;

            moves.push_back(Move(i, j, i, j + 1));

            grid[i][j]--;
            grid[i][j + 1]++;

        }
    }

    for(int i = 1; i < rows; i++)
    {
        int j = columns;

        if(grid[i][j]%2 == 0) continue;

        moves.push_back(Move(i, j, i + 1, j));

        grid[i][j]++;
        grid[i + 1][j]--;
    }

    printf("%d\n", moves.size());
    for(int i = 0; i < moves.size(); i++)
        moves[i].display();

    return 0;
}
