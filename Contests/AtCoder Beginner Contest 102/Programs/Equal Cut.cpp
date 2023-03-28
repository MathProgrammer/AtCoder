#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long find_difference(long long a, long long b, long long c, long long d)
{
    long long minimum = min(min(a, b), min(c, d));
    long long maximum = max(max(a, b), max(c, d));

    return maximum - minimum;
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    vector <long long> sum(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum[i] = sum[i - 1] + A[i];
    }

    vector <long long> best_P(no_of_elements + 1), best_Q(no_of_elements + 1);
    for(int i = 1, j = 2; j <= no_of_elements; j++)
    {
        //[1, i], [i + 1, j]
        int break_point = i;
        for(break_point = i; break_point < j; break_point++)
        {
            long long segment_1 = sum[break_point], segment_2 = sum[j] - sum[break_point];
            long long segment_1_before = sum[break_point - 1], segment_2_before = sum[j] - sum[break_point - 1];
            //cout << "j = " << j << " Before " << segment_1_before << " " << segment_2_before << " Now " << segment_1 << " " << segment_2 << "\n";

            if(abs(segment_2 - segment_1) <= abs(segment_1_before - segment_2_before))
            {
                i = break_point;
            }
            else
            {
                break;
            }
        }

        best_P[j] = sum[i], best_Q[j] = sum[j] - sum[i];
    }

    vector <long long> best_R(no_of_elements + 1), best_S(no_of_elements);
    for(int k = no_of_elements, j = no_of_elements - 1; j >= 1; j--)
    {
        //[j + 1, k - 1], [k, n]
        int break_point = k;
        for(break_point = k; break_point > j; break_point--)
        {
            long long segment_3 = sum[break_point - 1] - sum[j], segment_4 = sum[no_of_elements] - sum[break_point - 1];
            long long segment_3_before = sum[break_point] - sum[j], segment_4_before = sum[no_of_elements] - sum[break_point];

            if(abs(segment_3 - segment_4) <= abs(segment_3_before - segment_4_before))
            {
                k = break_point;
            }
            else
            {
                break;
            }
        }

        best_R[j] = sum[k - 1] - sum[j], best_S[j] = sum[no_of_elements] - sum[k - 1];
    }

    const long long oo = 1e18;
    long long answer = oo;
    for(int j = 2; j < no_of_elements; j++)
    {
        //cout << "j = " << j << "(" << best_P[j] << "," << best_Q[j] << "," << best_R[j] << "," << best_S[j] << ")\n";
        answer = min(answer, find_difference(best_P[j], best_Q[j], best_R[j], best_S[j]));
    }

    cout << answer << "\n";
    return 0;
}
