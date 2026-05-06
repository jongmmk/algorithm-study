#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compar(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

//2개의 위치 좌표를 입력 받은 후, 카메라의 위치를 찾는 함수
bool find(int x, int y, vector<int> d)
{
    for (int i = 0; i < d.size(); i++)
    {
        if (x <= d[i] && d[i] <= y)
        {
            return true;
        }
    }
    return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<int> d;
    
    //출구를 기준으로 정렬
    sort(routes.begin(), routes.end(), compar);
    
    
    // 카메라는 차량을 수보다 클 수 없음
    for (int i = 0; i < routes.size(); i++)
    {
        if (!find(routes[i][0], routes[i][1], d))
        {
            d.push_back(routes[i][1]);
            answer++;
        }
    }
    
    return answer;
}

int main()
{
    vector<vector<int>> routes = {{-20,-15}, {-14,-5}, {-18,-13}, {-5,-3}};
    
    cout << solution(routes) << endl;
    
    return 0;
}
