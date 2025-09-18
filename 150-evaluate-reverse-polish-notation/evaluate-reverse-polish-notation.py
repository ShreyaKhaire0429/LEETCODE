class Solution:
    # Shreya
    def evalRPN(self, tokens: List[str]) -> int:
        # Shreya
        stack = []
        
        for token in tokens:
            if token in {"+", "-", "*", "/"}:
                b = stack.pop()
                a = stack.pop()
                
                if token == "+":
                    stack.append(a + b)
                elif token == "-":
                    stack.append(a - b)
                elif token == "*":
                    stack.append(a * b)
                else:  # division
                    # truncate toward zero
                    stack.append(int(a / b))
            else:
                stack.append(int(token))
        
        return stack[0]