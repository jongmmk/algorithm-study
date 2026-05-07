#include <iostream>

using namespace std;

int solution(int n) {
    int ans = 0;
    while (n > 0) {
        ans += (n % 2); // 나머지가 1이면 더하고
        n /= 2;         // 무조건 2로 나눔 (어차피 정수형이라 5/2나 4/2나 결과는 같음)
    }
    return ans;
}

int main()
{


    return 0;
}
