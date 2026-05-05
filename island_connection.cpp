#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int find_(int x, int arr[])
{
    if (arr[x] == x) return x;
    return arr[x] = find_(arr[x], arr);
}

bool union_(int x, int y, int arr[])
{
    x = find_(x, arr);
    y = find_(y, arr);
    
    if (x != y)
    {
        if (x > y) arr[x] = arr[y];
        else arr[y] = arr[x];
        
        return true;
    }
    
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int arr[101];
    
    // 배열 초기화
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    
    //벡터 가중치 기준 정렬
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b)
    {
        return a[2] < b[2];
    });
    
    for (int j = 0; j < costs.size(); j++)
    {
        if (union_(costs[j][0], costs[j][1], arr))
        {
            union_(costs[j][0], costs[j][1], arr);
            answer += costs[j][2];
        }
    }

    
    return answer;
}

int main()
{
    vector<vector<int>> costs = {{0,1,1}, {0,2,2}, {1,2,5}, {1,3,1}, {2,3,8}};
    int n = 4;
    
    cout << solution(n, costs) << endl;
    
    return 0;
}
