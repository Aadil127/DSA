#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dynamicSizeStack.h"
#include"dynamicArray.h"

#define USER_INPUT_BUFFER 100

int isDigit(char ch);
int isLetter(char ch);
char *parseNumber(char *infixExpressionChar, Array *postfixExpression);
int getPrecedence(char ch);
char *infixToPostfix(char *infixExpression, int *expressionRank);
char *infixToPostfixLetters(char *infixExpression, int *expressionRank);

int main(void){
    char infixExpression[USER_INPUT_BUFFER];

    //+, _, *, /, ^, '(' and ')' are supported
    printf("Enter an expression eg A+B/c : ");

    fgets(infixExpression, sizeof(infixExpression), stdin);

    //if expression rank is 1 it is valid expression
    int expressionRank;
    char *expressionResult = infixToPostfixLetters(infixExpression, &expressionRank);
    printf("Postfix expression : %s\nExpression rank : %d\n", expressionResult, expressionRank);
    free(expressionResult);

    printf("Enter an expression eg 1.2 - 3.4 * 5.6 : ");

    fgets(infixExpression, sizeof(infixExpression), stdin);

    //if expression rank is 1 it is valid expression
    expressionResult = infixToPostfix(infixExpression, &expressionRank);
    printf("Postfix expression : %s\nExpression rank : %d\n", expressionResult, expressionRank);
    free(expressionResult);

    return 0;
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
            arrayAppend(postfixExpression, &(char){' '});

            if(expressionRank != NULL) (*expressionRank)++;
        }
        //If ( directly add it to stack
        else if(*infixExpression == '('){
            stackPush(stack, infixExpression);
        }
        //If ) pop the stack until we encounter (
        else if(*infixExpression == ')'){
            stackPop(stack, &topChar);
            while (topChar != '('){
                arrayAppend(postfixExpression, &topChar);
                arrayAppend(postfixExpression, &(char){' '});
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
                arrayAppend(postfixExpression, &(char){' '});
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
        arrayAppend(postfixExpression, &(char){' '});
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

//Convert infix to postfix expression only for letters and digit
//Accepts infix expression string and addres of varible to store expression rank leave it NULL if you do not need expression rank
//Returns postfix expression string, must call free to deallocte memory of this string
//Example: 1.2 - 3.4 * 567.890
char *infixToPostfix(char *infixExpression, int *expressionRank){
    if(expressionRank != NULL) *expressionRank = 0;
    Array *postfixExpression = arrayCreate(1, sizeof(char));
    Stack *stack = stackCreate(sizeof(char));
    char topChar;
    int infixExpOperatorPrecedence;

    while(*infixExpression!= '\0'){
        //To check if given char is a digit or a letter and directly add it to postfix expression
        if(isDigit(*infixExpression)){
            infixExpression = parseNumber(infixExpression, postfixExpression);
            arrayAppend(postfixExpression, &(char){' '});
            if(expressionRank != NULL) (*expressionRank)++;
        }
        //If ( directly add it to stack
        else if(*infixExpression == '('){
            stackPush(stack, infixExpression);
        }
        //If ) pop the stack until we encounter (
        else if(*infixExpression == ')'){
            stackPop(stack, &topChar);
            while (topChar != '('){
                arrayAppend(postfixExpression, &topChar);
                arrayAppend(postfixExpression, &(char){' '});
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
                arrayAppend(postfixExpression, &(char){' '});
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
        arrayAppend(postfixExpression, &(char){' '});
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
    return ch >= '0' && ch <= '9';
}

int isLetter(char ch){
    return ch >= 'A' && ch <= 'z';
}

int getPrecedence(char ch){
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '^') return 3;
    else return 0;
}

char *parseNumber(char *infixExpressionChar, Array *postfixExpression){

    while(isDigit(*infixExpressionChar) || *infixExpressionChar == '.'){
        arrayAppend(postfixExpression, infixExpressionChar);
        infixExpressionChar++;
    }
    return --infixExpressionChar;
}
