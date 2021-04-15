// Program to test whether an input line is a Word Level palindrome.
// punctuation, and the difference between upper- and lowercase are ignored.

#include <cctype>     // Provides isalpha, toupper
#include <iostream>   // Provides cout, cin, peek
#include <queue>      // Provides the queue template class
#include <stack>      // Provides the stack template class
using namespace std;

int main() {
	queue<char> q;
	stack<char> s;
	char letter;
	int mismatches = 0;  // Mismatches between queue and stack
	cout << "Enter a line and I will see if it's a Word level palindrome:" << endl;
	while (cin.peek() != '\n') {
		cin >> letter;
		if (isalpha(letter)) {
			toupper(letter);
			q.push(letter);
			s.push(letter);
		}
		if (cin.peek() == ' ' || cin.peek() == '\n') {//if next char is a blank space, it will check if current word is palindrome then continue to next word
			while ((!q.empty()) && (!s.empty())) {
				if (q.front() != s.top())
					mismatches++;
				q.pop();
				s.pop();
			}
		}
	
	}//endof cin.peek \n
	if (mismatches == 0)
		cout << "It's a Word Level Palindrome." << endl;
	else
		cout << "Not Word Level Palindrome." << endl;
	
	system("pause");

}
