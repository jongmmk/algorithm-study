#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = (int)name.size(); //문자의 크기를 저장
    
    //65 ~ 90 (a ~ b)
    int up = 0; //for문 내부에서 사용하면 n번만큼 메모리를 계속 생성하기 떄문에 밖에서 선언함
    int down = 0;
    for (int i = 0; i < n; i++)
    {
        up = abs((int)name[i] - 65); //min을 사용하여 최적화 가능 & 가독성 증가
        down = abs((int)name[i] - 91);
        answer += min(up, down);

        if (name[i] != 'A') name[i] = 1;
        else name[i] = 0;
    }

    // 최소탐색로직
    int sol_1 = n - 1;
    for (int i = n - 1; i > 0; i--)
    {
        if (name[i] == 0)
        {
            sol_1--;
        }
        else {break;}
    }

    int next = 0;//i번 까지만 이동하고 뒤로 돌아올 때 도착위치를 나타내를 변수
    int m = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        next = i + 1;
        while(n > next && name[next] != 1)
        {
            next++;
        }
        int sol_2 = min ((i * 2) + (n - next), 2 * (n - next) + i);
        m = min(sol_2, m);
    }
    answer += min(m, sol_1);
    
    
    
    return answer;
}

int main()
{
    string name = "BBBAAAB";
    cout << solution(name) << endl;
    
    return 0;
}
