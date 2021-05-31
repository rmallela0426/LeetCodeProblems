

/*
*  Author: Raghavendra Mallela
*/
/*
 * LeetCode 150: Reverse Polish Notation
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation. Reverse Polish
 * Notation or postfix polish notation is a mathematical notation in which operators follow
 * the operands (eg: 3, 4, +)
 * 
 * Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
 * Note that division between two integers should truncate toward zero.
 *
 * It is guaranteed that the given RPN expression is always valid. That means the expression
 * would always evaluate to a result, and there will not be any division by zero operation.
 *
 * Example 1:
 * Input: tokens = ["2","1","+","3","*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 *
 * Example 2:
 * Input: tokens = ["4","13","5","/","+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 *
 * Example 3:
 * Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 * Output: 22
 * Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 *
 * Constraints:
 * 1 <= tokens.length <= 104
 * tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/
/*
 * As 2 operands are required to perform an operation, traversing
 * from left to right is the approach to follow.
 * will use the stack data structure. Perform following
 *  . Traverse from left to right
 *  . Push the current string, convert it to int and push onto stack
 *    if not an operator.
 *  . If the current token is an operator, pop 2 operands from the stack
 *    perform the operation and push the result stack.
 *  . Continue steps 2 & 3 until all tokens are done.
 *  . Result of all tokens will be on top of the stack
*/
int evalRPN(vector<string>& tokens) {
    // Stack to store the operands (numbers)
    stack<int> st;

    // variables for storing the operands from the stack
    int a;
    int b;

    // Traverse all tokens from left to right
    for (string& token : tokens) {
        // Check if the current token is an operator
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Current token is an operator
            // Remove the top 2 elements from stack and perform the
            // operation
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();

            // Perform the operation and push onto stack
            if (token == "+" || token == "-") {
                // Current token is either '+' or '-'
                st.push(token == "+" ? a + b : a - b);
            }
            else {
                // current token is either '*' or '/'
                st.push(token == "*" ? a * b : a / b);
            }
        }
        else {
            // Current token is a number push it to stack
            st.push(stoi(token));
        }
    }

    // Result is on the top of stack
    return st.top();
}
