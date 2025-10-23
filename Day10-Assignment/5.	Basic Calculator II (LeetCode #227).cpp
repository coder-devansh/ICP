class Solution {
public:
    int calculate(string& expression) {
        int n = expression.size();
        stack<long long> terms;
        string opstr = "";
        int i = 0;
        long long num = 0;

        while (i < n) {
            if (expression[i] == ' ') {
                i++;
                continue;
            }
            if (expression[i] == '+') {
                opstr += '+';
                i++;
            } else if (expression[i] == '-') {
                opstr += '-';
                i++;
            } else if (expression[i] == '*') {
                num = 0;
                i++;
                while (i < n && (expression[i] != '+') &&
                       (expression[i] != '-') && (expression[i] != '*') &&
                       (expression[i] != '/')) {
                    if (expression[i] != ' ') {
                        num = num * 10 + expression[i] - '0';
                    }
                    i++;
                }
                long long num1 = terms.top();
                terms.pop();
                long long num2 = num;
                num = 0;
                terms.push(num1 * num2);
            } else if (expression[i] == '/') {
                num = 0;
                i++;
                while (i < n && (expression[i] != '+') &&
                       (expression[i] != '-') && (expression[i] != '*') &&
                       (expression[i] != '/')) {
                    if (expression[i] != ' ') {
                        num = num * 10 + expression[i] - '0';
                    }
                    i++;
                }
                long long num1 = terms.top();
                cout << "num1 :" << num1 << endl;

                terms.pop();
                long long num2 = num;
                cout << "num2 :" << num2 << endl;
                num = 0;
                long long res = (num1 / num2);
                cout << "res: " << res << endl;
                terms.push(res);
                // terms.push(ceil(res));
            } else {
                num = 0;
                while (i < n && (expression[i] != '+') &&
                       (expression[i] != '-') && (expression[i] != '*') &&
                       (expression[i] != '/')) {
                    if (expression[i] != ' ') {
                        num = num * 10 + expression[i] - '0';
                    }
                    i++;
                }
                terms.push(num);
                cout << num << endl;
                num = 0;
            }
        }
        cout << opstr << endl;
        stack<long long> reversed_terms;
        while (!terms.empty()) {
            reversed_terms.push(terms.top());
            terms.pop();
        }

        // 2. Perform calculations from left to right
        if (reversed_terms.empty())
            return 0;

        long long result = reversed_terms.top(); // Start with the first number
        reversed_terms.pop();

        for (char op : opstr) {
            long long next_num = reversed_terms.top();
            reversed_terms.pop();
            if (op == '+') {
                result += next_num;
            } else { // op == '-'
                result -= next_num;
            }
        }
        return result;
    }
};