#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int left = 0;
    int right = (int)people.size() - 1;
    
    //벡터 오름차순 정렬
    sort(people.begin(), people.end());
    
    while (left <= right) {
        
        if (people[left] + people[right] <= limit) //2명이 보트에 탑승 가능
        {
            left++;
            right--;
        }
        else //1명만 건거야한
        {
            right--;
        }
        
        answer++;
    }
    return answer;
}

int main()
{
    
    vector<int> people = {70, 50, 80, 50};
    int limit = 100;
    
    cout << solution(people, limit) << '\n';
    
    return 0;
}