#include <iostream>
#include<cmath>

using namespace std;

bool remains[100001] = { 0 };

long long pow(int n) {
    int exp = 1;
        
    while(n >= 10) {
        n = n / 10;
        exp++;
    }
    
    return pow(10, exp);
}

int main() {
    int n, k;
    
    cin >> n >> k;
    
    int answer = 1;
    int remain = n % k;
    long long digit = pow(n);
    
    while (remain != 0) {
        remain = (remain * digit + n) % k;
        
        if (remains[remain]) {
            answer = -1;
            break;
        }
        
        remains[remain] = true;
        answer++;
    }
    
    cout << answer;
    
    return 0;
}