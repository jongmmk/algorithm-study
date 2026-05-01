#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    for (int i = 0; i < number.length(); i++)
    {
        while (!answer.empty() && k > 0 && answer.back() < number[i]) {
            k--;
            answer.pop_back();
        }
        answer.push_back(number[i]);
    }
    
    if (k > 0)
    {
        answer = answer.substr(0, number.length() - k);
    }
    
    return answer;
}

int main()
{
    string number = "4177252841";
    int k = 4;
    
    cout << solution(number, k) << '\n';
    
    return 0;
}

