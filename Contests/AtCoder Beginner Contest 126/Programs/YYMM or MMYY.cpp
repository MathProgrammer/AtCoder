#include <cstdio>

int main()
{
    int first, second;
    scanf("%2d%2d", &first, &second);

    int yymm = (1 <= second && second <= 12);
    int mmyy = (1 <= first && first <= 12);

    if(yymm && mmyy)  printf("AMBIGUOUS\n");
    if(!yymm && mmyy) printf("MMYY\n");
    if(yymm && !mmyy) printf("YYMM\n");
    if(!yymm & !mmyy) printf("NA\n");

    return 0;
}
