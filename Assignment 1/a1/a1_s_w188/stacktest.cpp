/*Samuel Wait (s_w188)
 Assignment 1*/

#include <iostream>
#include "mystack.h"

using namespace std;

void PostfixTest(){
    MyStack operand_stack(100);
    cout << "Please enter the operands (integers 1~9) and operators (+, -, *, /) one by one..." << endl;
    cout << "and enter '=' to indicate the end of the expression and to output the result." << endl;
    while(1){
        char input_holder;
        cin >> input_holder;
        if(isdigit(input_holder)){
            operand_stack.Push(int(input_holder)-48);
        }
        
        else{
            int operand1 = 0;
            int operand2 = 0;
            switch(input_holder){
                case '+':
                    operand1 = operand_stack.Pop();
                    if(operand_stack.IsEmpty()){
                        cout << "\nError! Invalid Expression\n";
                        operand_stack.Push(operand1);
                        break;
                    }
                    operand2 = operand_stack.Pop();
                    operand_stack.Push(operand1+operand2);
                    break;
                    
                case '-':
                    operand1 = operand_stack.Pop();
                    if(operand_stack.IsEmpty()){
                        cout << "\nError! Invalid Expression\n";
                        operand_stack.Push(operand1);
                        break;
                    }
                    operand2 = operand_stack.Pop();
                    operand_stack.Push(operand2-operand1);
                    break;
                    
                case '*':
                    operand1 = operand_stack.Pop();
                    if(operand_stack.IsEmpty()){
                        cout << "\nError! Invalid Expression\n";
                        operand_stack.Push(operand1);
                        break;
                    }
                    operand2 = operand_stack.Pop();
                    operand_stack.Push(operand1*operand2);
                    break;
                    
                case '/':
                    operand1 = operand_stack.Pop();
                    if(operand_stack.IsEmpty()){
                        cout << "\nError! Invalid Expression\n";
                        operand_stack.Push(operand1);
                        break;
                    }
                    operand2 = operand_stack.Pop();
                    operand_stack.Push(operand1/operand2);
                    break;
                case '=':{
                    int total = operand_stack.Pop();
                    if(total < 0){
                        cout << "\nError! Invalid expression\n";
                        break;
                    }
                    cout << "The entered postfix expression results in " << total << endl;
                    break;
                }
                default:
                    cout << "\nInvalid Operator\n";
                    break;
            }
        }
    }
}

int main()
{
    cout << "Testing the basic functions of your stack..." << endl;
    cout << "Please enter the max size of your stack: ";
    int test_size;
    cin >> test_size;

    MyStack test_stack(test_size);

    while(1) {
        cout << "Please enter 'p' for push, 'o' for pop, 'e' for exit: ";
        char user_choice;
        cin >> user_choice;
      
        if(user_choice == 'e')
            break;

        switch (user_choice) {
            case 'p':
                if(!test_stack.IsFull()) {
                    cout << "Please enter an integer value you would like to push: ";
                    int val;
                    cin >> val;
                    test_stack.Push(val);
                }
                else
                    cout << "Nothing can be pushed in since the stack is full!" << endl;
                break;
            case 'o':
                if(!test_stack.IsEmpty())
                    cout << test_stack.Pop() << " has been popped out." << endl;
                else
                    cout << "Nothing has been popped out since the stack is empty!" << endl;
                break;
            default:
                cout << "Invalid user-input character. Please try again." << endl;
      }
   }

    cout << "Now, start to use a stack to evaluate postfix expressions..." << endl;
    PostfixTest();
	
    return 0;
}
