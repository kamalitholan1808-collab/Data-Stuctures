
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> history;

    // Store visited pages
    history.push("google.com");
    history.push("youtube.com");
    history.push("abcsc.com");
    history.push("facebook.com");

    cout << "Current page: " << history.top() << endl;

    // Press Back once
    history.pop();
    cout << "After first Back: " << history.top() << endl;

    // Press Back twice
    history.pop();
    cout << "After second Back: " << history.top() << endl;

    return 0;
}
