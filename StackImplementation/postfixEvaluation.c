#include<stdio.h>
#include<math.h>
#include"dynamicSizeStack.h"

#define USER_INPUT_BUFFER 100

double evaluatePostfixExpression(char *postfixExpressionChar);
double evaluateExpression(char operator, double num1, double num2);
int isOperator(char ch);
int isDigit(char ch);
char *parseNumber(char *postfixExpressionChar, double *num);


int main(void){
    char postfixExpression[USER_INPUT_BUFFER];

    printf("Enter a postfix expression(eg 12 34 - 56 *) : ");

    fgets(postfixExpression, sizeof(postfixExpression), stdin);

    printf("Evaluated expression: %g\n", evaluatePostfixExpression(postfixExpression));
    return 0;
}

double evaluatePostfixExpression(char *postfixExpressionChar){
    Stack *stack = stackCreate(sizeof(double));
    double num1 = 0, num2 = 0,tempNum = 0;

    double result = 0;
    while(*postfixExpressionChar != '\0'){
        if(isDigit(*postfixExpressionChar)){
            postfixExpressionChar = parseNumber(postfixExpressionChar, &tempNum);
            stackPush(stack, &tempNum);
            tempNum = 0;
        }
        if(isOperator(*postfixExpressionChar)){
            stackPop(stack, &num2);
            stackPop(stack, &num1);
            tempNum = evaluateExpression(*postfixExpressionChar, num1, num2);
            stackPush(stack, &tempNum);
        }
        postfixExpressionChar++;
    }
    stackPop(stack, &result);
    stackRemove(stack);
    return result;
}

int isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int isDigit(char ch){
    return ch >= '0' && ch <= '9';
}

char *parseNumber(char *postfixExpressionChar, double *num){
    double decimal = 0;
    while(isDigit(*postfixExpressionChar) || *postfixExpressionChar == '.'){
        if(*postfixExpressionChar == '.'){
            decimal = 1;
        }else if(decimal != 0){
            decimal *= 10;
            *num += (*postfixExpressionChar - '0') / decimal;
        }
        else{
            *num = *num * 10 + (*postfixExpressionChar - '0');
        }
        postfixExpressionChar++;
    }
    return postfixExpressionChar;
}

double evaluateExpression(char operator, double num1, double num2){
    if(operator == '+') return num1 + num2;
    else if(operator == '-') return num1 - num2;
    else if(operator == '*') return num1 * num2;
    else if(operator == '/') return num1 / num2;
    else if(operator == '^') return pow(num1, num2);
    else return 0;
}
