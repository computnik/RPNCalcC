#ifndef A6_HPP
#define A6_HPP

#include "token.hpp"
#include <stack>
#include<cstdlib>
#include <iostream>
using namespace std;
// implement your function RPN

void performOp(char op, stack<double>& calcStack){
    double lVal, rVal, result;
    rVal = calcStack.top();
    calcStack.pop();
    lVal = calcStack.top();
    calcStack.pop();

    switch(op){
    case '+':
        result = lVal + rVal;
        break;
    case '-':
        result = lVal - rVal;
        break;
    case '*':
        result = lVal * rVal;
        break;
    case '/':
        result = lVal / rVal;
        break;
    default:
        break;
    }
    calcStack.push(result);
}

template <typename Iter> double RPN(Iter first, Iter last) {
    stack<double> calcStack;
    for (Iter it = first; it != last; it++){
        //    if ((*it).is_operator())
        //
        //        cout<<(*it).as_operator()<<endl;
        //    if ((*it).is_operand())
        //        cout<<(*it).as_operand()<<"\t"<<((*it).as_operand())<<endl;
        if ((*it).is_operand())
            calcStack.push((*it).as_operand());
        else if ((*it).is_operator()){
            performOp((*it).as_operand(),calcStack);
        }


    }
    return calcStack.top();
} // RPN

#endif // A6_HPP
