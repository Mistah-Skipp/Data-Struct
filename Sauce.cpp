//Program will take ina user input and calculate using fibonacci recursion to the users number
//using stack class to deal with extremely large numbers

#include <iostream>
#include <stack>	
using namespace std;

stack<int> fibStack(stack<int> op1, stack<int> op2);
int main() {
	stack<int> op1, op2,answer;
	//op1 = fibNum1, op2 = fibNum2, result = fibNthNum
	string output;
	int num;
	//num =user taken fibIndex
	cout << "Enter the poistion number for the fibonacci sequence: ";
	cin >> num;
	op1.push(1);
	op2.push(1);
	for (int i = 3; i <= num; i++) {
		//op2 becomes prev(op1), op1 becomes current(answer)
		answer = fibStack(op1, op2);
		op2 = op1;
		op1 = answer;
	}
	//end behavior
	cout << "the Fibonacci Number at pos "<< num << " is: ";
	while (!answer.empty()) {//while answer stack isnt empty
		cout << answer.top();
		answer.pop();
	}
	cout << endl;
	system("pause");

}//endof int main
stack<int> fibStack(stack<int> op1, stack<int> op2) {
	stack<int> result;
	int num1, num2;
	int ans;
	while (!op1.empty() && !op2.empty()) {
		//num1 = op1.top();
		//op1.pop();
	//	num2 = op2.top();
	//	op2.pop();
		//ans = (num1) + (num2);
		result.push(op1.top() + op2.top());
		op1.pop();
		op2.pop();
	}
	return result;
}//end of fibstack
