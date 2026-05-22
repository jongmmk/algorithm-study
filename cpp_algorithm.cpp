#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end()); //min heap

    int a = 0;
    int b = 0;
    int c = 0;
    while (!pq.empty() && pq.top() < K)
    {
        if (pq.size() < 2)
        {
            return -1;
        }
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        c = a + (b * 2);
        pq.push(c);
        answer++;
    }
    
    return answer;
}

int main()
{

    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int k = 7;

    cout << solution(scoville, k) << endl;

    return 0;
}