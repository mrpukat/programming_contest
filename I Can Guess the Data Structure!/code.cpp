#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

void guess (bool isStk, bool isQue, bool isP_que);

int main() {

	string line;

	while (getline(cin,line)) {

		int n = stoi(line);

		priority_queue<int> p_que;
		queue<int> que;
		stack<int> stk;

		bool isP_que = true;
		bool isQue = true;
		bool isStk = true;

		for (int i = 0; i < n; ++i) {

			getline(cin,line,' ');

			int comand = stoi(line);

			getline(cin,line);

			int x = stoi(line);

			if (comand == 1) {
				p_que.push(x);
				que.push(x);
				stk.push(x);
			} else {

				if (p_que.empty() || p_que.top() != x) isP_que = false;
				if (que.empty() || que.front() != x) isQue = false;
				if (stk.empty() || stk.top() != x) isStk = false;

				if (!p_que.empty()) p_que.pop();
				if (!que.empty()) que.pop();
				if (!stk.empty()) stk.pop();

			}

		}

		guess(isStk,isQue,isP_que);

	}


    return 0;
}


void guess (bool isStk, bool isQue, bool isP_que) {

	if (isStk) {
		if (isQue || isP_que) cout << "not sure" << endl;
		else cout << "stack" << endl;
	}
	else if (isQue) {
		if (isStk || isP_que) cout << "not sure" << endl;
		else cout << "queue" << endl;
	}
	else if (isP_que) {
		if (isQue || isStk) cout << "not sure" << endl;
		else cout << "priority queue" << endl;
	}
	else cout << "impossible" << endl;

}

