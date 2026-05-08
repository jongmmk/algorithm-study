#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int st = 1;
    int pos = 0;
    int min = 0;
    int max = 0;
    bool logic_ed = false;
    
    sort(stations.begin(), stations.end());
    
    while (1)
    {
        if (pos >= (int)stations.size())
        {
            min = n;
            logic_ed = true;
        }
        else
        {
            min = stations[pos] - w;
            max = stations[pos] + w;
        }
        
        
        answer += (min - st) / (w * 2 + 1);
        if ((min - st) % (w * 2 + 1) > 0)
        {
            answer += 1;
        }
        
        if (logic_ed) break;
        pos++;
        st = max + 1;
    }
    

    return answer;
}

int main()
{
    int n = 11;
    int w = 1;
    vector<int> stations = {4, 11};
    
    cout << solution(n ,stations, w) << endl;
    
    return 0;
}
