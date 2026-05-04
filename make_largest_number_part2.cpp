#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> v;

    for (int x : numbers) {
        v.push_back(to_string(x));
    }
    
    sort(v.begin(), v.end(), [](string a, string b)
    {
        return a + b > b + a;
    });
    
    for (int i = 0; i < v.size(); i++)
    {
        answer += v[i];
    }
    
    if (v[0] == "0") return "0";
    
    return answer;
}

int main()
{
    
    vector<int> number_1 = {6, 10, 2};
    vector<int> number_2 = {3, 30, 34, 5, 9};
    
    // 2 6 10
    //3 5 9 30 34
    
    cout << solution(number_2) << endl;
    
    return 0;
}