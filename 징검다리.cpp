#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 0;
    int right = distance;
    
    sort(rocks.begin(), rocks.end());
    
    while (left <= right)
    {
        int remove_rock = 0;
        int mid = left + (right - left) / 2;
        int prev_pos = 0; //직전 바위의 위치
        
        for (int i = 0; i < rocks.size(); i++)
        {
            if (rocks[i] - prev_pos < mid)
            {
                remove_rock++;
            }
            else
            {
                prev_pos = rocks[i];
            }
        }
        
        if (distance - prev_pos < mid)
        {
            remove_rock++;
        }
        
        if (n < remove_rock)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
            answer = mid;
        }
    }
    return answer;
}

int main()
{
    
    int distance = 25;
    int n = 2;
    vector<int> rocks = {2, 14, 11, 21, 17};
    int ans = solution(distance, rocks, n);
    cout << "ans : " << ans << endl;
    
    return 0;
}
