#include<iostream>
using namespace std;

int fibonacci(int n) {
    if(n <= 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n;
    cout << "请输入斐波那契数列的项数： ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    return 0;
}
