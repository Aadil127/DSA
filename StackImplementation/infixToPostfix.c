#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dynamicSizeStack.h"
#include"dynamicArray.h"

#define USER_INPUT_BUFFER 100

int isDigit(char ch);
int isLetter(char ch);
int getPrecedence(char ch);
char *infixToPostfix(char *infixExpression, int *expressionRank);
char *infixToPostfixLetters(char *infixExpression, int *expressionRank);

int main(void){
    char infixExpression[USER_INPUT_BUFFER];

    //+, _, *, /, ^, '(' and ')' are supported
    printf("Enter an expression : ");

    fgets(infixExpression, sizeof(infixExpression), stdin);

    //if expression rank is 1 it is valid expression
    int expressionRank;
    char *exprssionResult;
    printf("Postfix expression : %s\nExpression rank : %d\n", exprssionResult = infixToPostfixLetters(infixExpression, &expressionRank), expressionRank);
    free(exprssionResult);

    return 0;
}

char *infixToPostfix(char *infixExpression, int *expressionRank){
    size_t infixExprssionSize = strlen(infixExpression);
    char *posfixExpression = malloc(sizeof(char) * infixExprssionSize);
    size_t posfixExpressionIndex = 0;
    Stack *stack = stackCreate(sizeof(char));
    int expressionRankVar = 0;

    char topChar;
    int infixExpOperatorPrecedence;
    for(size_t infixExpressionIndex = 0; infixExpressionIndex < infixExprssionSize; infixExpressionIndex++){

        //Just to add white space when one number ends and other starts to distinguish between 11+2 -> 11 2 + 
        if(infixExpressionIndex > 0 && isDigit(infixExpression[infixExpressionIndex - 1]) && !isDigit(infixExpression[infixExpressionIndex]) && infixExpression[infixExpressionIndex] != '.'){
            posfixExpression[posfixExpressionIndex++] = ' ';
            expressionRankVar++;
        }

        //To check if given char is digit and directly add it to postfix expression
        if(isDigit(infixExpression[infixExpressionIndex])){
            posfixExpression[posfixExpressionIndex] = infixExpression[infixExpressionIndex];
            posfixExpressionIndex++;
        }
        //If ( directly add it to stack
        else if(infixExpression[infixExpressionIndex] == '('){
            stackPush(stack, &infixExpression[infixExpressionIndex]);
        }
        //If ) pop the stack until we encounter (
        else if(infixExpression[infixExpressionIndex] == ')'){
            stackPop(stack, &topChar);
            while (topChar != '('){
                posfixExpression[posfixExpressionIndex] = topChar;
                posfixExpressionIndex++;
                stackPop(stack, &topChar);
            }
        }
        //Check precendence if top has higher precedence than given operator pop top and push given operator
        else if((infixExpOperatorPrecedence = getPrecedence(infixExpression[infixExpressionIndex]))){
            expressionRankVar--;
            stackPeek(stack, &topChar);
            while(!stackEmpty(stack) && (getPrecedence(topChar) >= infixExpOperatorPrecedence)){
                if(infixExpression[infixExpressionIndex] == '^' && topChar == '^') break;
                posfixExpression[posfixExpressionIndex] = topChar;
                posfixExpressionIndex++;
                stackPop(stack, &topChar);
                stackPeek(stack, &topChar);
            }
            stackPush(stack, &infixExpression[infixExpressionIndex]);
        }
        // to allow letters eg A + B * C
        else{
            if(infixExpression[infixExpressionIndex] != '\n' && infixExpression[infixExpressionIndex] != ' '){
                expressionRankVar++;
                posfixExpression[posfixExpressionIndex] = infixExpression[infixExpressionIndex];
                posfixExpressionIndex++;
            }
        }

    }
    //If arrived at the end of infix expression pop all of the operator from stack one by one and add it to postfix expression until stack becomes empty
    while(!stackEmpty(stack)){
        stackPop(stack, &topChar);
        posfixExpression[posfixExpressionIndex] = topChar;
        posfixExpressionIndex++;
    }
    
    posfixExpression[posfixExpressionIndex] = '\0';
    if(expressionRank != NULL){
        *expressionRank = expressionRankVar;
    }
    return posfixExpression;
}

//Convert infix to postfix expression only for letters and digit
//Accepts infix expression string and addres of varible to store expression rank leave it NULL if you do not need expression rank
//Returns postfix expression string, must call free to deallocte memory of this string
//Example: A+B, A*(B-C), 1/2-7
char *infixToPostfixLetters(char *infixExpression, int *expressionRank){
    Array *postfixExpression = arrayCreate(1, sizeof(char));
    Stack *stack = stackCreate(sizeof(char));
    char topChar;
    int infixExpOperatorPrecedence;

    while(*infixExpression!= '\0'){
        //To check if given char is a digit or a letter and directly add it to postfix expression
        if(isDigit(*infixExpression) || isLetter(*infixExpression)){
            arrayAppend(postfixExpression, infixExpression);

            if(expressionRank != NULL) (*expressionRank)++;
        }
        //If ( directly add it to stack
        else if(*infixExpression == '('){
            arrayAppend(postfixExpression, infixExpression);
        }
        //If ) pop the stack until we encounter (
        else if(*infixExpression == ')'){
            stackPop(stack, &topChar);
            while (topChar != '('){
                arrayAppend(postfixExpression, &topChar);
                stackPop(stack, &topChar);
            }
        }
        //Check precendence if top has higher precedence than given operator pop top and push given operator
        else if((infixExpOperatorPrecedence = getPrecedence(*infixExpression))){
            stackPeek(stack, &topChar);

            if(expressionRank != NULL) (*expressionRank)--;

            while(!stackEmpty(stack) && (getPrecedence(topChar) >= infixExpOperatorPrecedence)){
                if(*infixExpression == '^' && topChar == '^') break;
                arrayAppend(postfixExpression, &topChar);
                stackPop(stack, &topChar);
                stackPeek(stack, &topChar);
            }
            stackPush(stack, infixExpression);
        }
        infixExpression++;

    }
    //If arrived at the end of infix expression pop all of the operator from stack one by one and add it to postfix expression until stack becomes empty
    while(!stackEmpty(stack)){
        stackPop(stack, &topChar);
        arrayAppend(postfixExpression, &topChar);
    }

    //Converting array to char to string and freeing memory used by dynamic array
    size_t postfixExpressionLength = arrayLength(postfixExpression);
    char *postfixExpressionResult = malloc(postfixExpressionLength + 1);
    memcpy(postfixExpressionResult, arrayElementR(postfixExpression, 0), postfixExpressionLength);
    postfixExpressionResult[postfixExpressionLength] = '\0';
    arrayRemove(postfixExpression);
    stackRemove(stack);

    return postfixExpressionResult;
}

int isDigit(char ch){
    if (ch >= '0' && ch <= '9') return 1;
    return 0;
}

int isLetter(char ch){
    if (ch >= 'A' && ch <= 'z') return 1;
    return 0;
}

int getPrecedence(char ch){
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '^') return 3;
    else return 0;
}
