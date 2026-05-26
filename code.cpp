#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct list_type
{
    int due; //작업소요시간
    int start; //작업요청시간
    int num; //작업번호
};

//비교함수 (객체 함수), min heap
struct cmp
{
    bool operator()(list_type& a, list_type& b)
    {
        if (a.due != b.due) return a.due > b.due;
        if (a.start != b.start) return a.start > b.start;
        if (a.num != b.num) return a.num > b.num;
        return false;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    priority_queue<list_type, vector<list_type>, cmp> pq;

    // 데이터 삽입
    int rank = 0; //작업 순서 기록
    for (int i = 0; i < jobs.size(); i++)
    {
        list_type j = {jobs[i][1], jobs[i][0], rank};
        pq.push(j);
    }


    // 반환시간 
    int time = 0;

    for (int i = 0; i < jobs.size(); i++)
    {
        list_type j = pq.top();
        time += j.due;
        int time_temp = time;
        answer += time_temp - j.start;
        pq.pop();
    }

    answer = answer / (int)jobs.size();

    return answer;
}

int main()
{
    //작업요청시간, 작업소요시간
    vector<vector<int>> jobs = {
        {0, 3},
        {1, 9},
        {3, 5}
    };

    cout << solution(jobs) << endl;

    return 0;
}