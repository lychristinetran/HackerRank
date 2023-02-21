#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void flip_stacks(std::stack<long long> &empty, std::stack<long long> &full){
    while (!full.empty()){
        long long n = full.top();
        empty.push(n);
        full.pop();
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    std::stack<long long> s1;
    std::stack<long long> s2;
    long long no_query;
    int op = 0;

        
    cin >> no_query;
    
    for (int i = 0; i < no_query;i++){
        cin >> op;
        if (op == 1){
            long long x;
            cin >> x;
            s1.push(x);
        } else if (op == 2){
            if (s2.empty())
                flip_stacks(s2, s1);
            s2.pop(); // it doesnt really matter ??
            // flip_stacks(s1, s2);
        } else if (op == 3){
            if (s2.empty())
                flip_stacks(s2, s1);
            cout<< s2.top() << endl;;
            // flip_stacks(s1, s2);
        }
    }
    return 0;
}
