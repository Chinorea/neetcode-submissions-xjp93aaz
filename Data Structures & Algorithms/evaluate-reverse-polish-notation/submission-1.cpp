class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;

        for(string s : tokens) {
            if (s == "+") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b+a);
            } else if (s == "-") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b-a);
            } else if (s == "*") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b*a);
            } else if (s == "/") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b/a);
            } else {
                stack.push(stoi(s));
            }
        }

        return stack.top();
    }
};
