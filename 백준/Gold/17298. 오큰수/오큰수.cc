#include <stack>
#include <iostream>
#include <vector>

using namespace std;

int inp[1000002];
int result[1000002];

int main() {
	int N;
	stack<int> s;
	
	cin >> N;
	
	for(int i=0; i<N; i++) {
		cin >> inp[i];
	}
	
	for(int i=N-1; i>=0; i--) {
		// stack에 들어가있는 놈들 중에 나보다 작은놈 나와
		while(!s.empty() && s.top() <= inp[i]) {
			s.pop();
		}
		
		result[i] = s.empty() ? -1 : s.top();
		
		s.push(inp[i]);
	}
	
	for(int i=0; i<N; i++) {
		cout << result[i] << " "; 
	}
	cout << endl;
	
	return 0;
}