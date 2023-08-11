#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[100];
char infix[100];
char postfix[100];
char num[100];
char operator[100];

int main() {
    printf("Input the Infix expression ::  ");
    gets(s);
    infix[0]='(';
    strcat(infix, s);
    strcat(infix, ")");
    int i, j=0, k, in=0, top=-1;
    for(i=0; i<strlen(infix); i++) {
        if((infix[i]>='0' && infix[i]<='9') || (infix[i]>='A' && infix[i]<='Z')  || (infix[i]>='a' && infix[i]<='z')) {
            num[j++]=infix[i];
        }
        else {
            for(k=0; k<j; k++) {
                postfix[in++]=num[k];
            }
            postfix[in++]=' ';
            memset(num, NULL, j);
            j=0;
            if(infix[i]=='(') {
                operator[++top]=infix[i];
            }
            else if(infix[i]=='^') {
                 while(1) {
                    if(operator[top]=='^') {
                        postfix[in++]=operator[top--];
                        postfix[in++]=' ';
                    }
                    else
                    break;
                }
                operator[++top]=infix[i];
            }
            else if(infix[i]=='*' || infix[i]=='/' || infix[i]=='%') {
                while(1) {
                    if(operator[top]=='^' || operator[top]=='*' || operator[top]=='/' || operator[top]=='%') {
                        postfix[in++]=operator[top--];
                        postfix[in++]=' ';
                    }
                    else
                    break;
                }
                operator[++top]=infix[i];
            }
            else if(infix[i]=='+' || infix[i]=='-') {
                while(1) {
                    if(operator[top]=='^' || operator[top]=='*' || operator[top]=='/' || operator[top]=='+' || operator[top]=='-' || operator[top]=='%') {
                        postfix[in++]=operator[top--];
                        postfix[in++]=' ';
                    }
                    else
                    break;
                }
                operator[++top]=infix[i];
            }
            else if(infix[i]==')') {
                while(1) {
                    if(operator[top]=='(') {
                        top--;
                        break;
                    }
                    else {
                        postfix[in++]=operator[top--];
                        postfix[in++]=' ';
                    }
                }
            }
        }
    }
    printf("Postfix Expression ::  %s", postfix);

    return 0;
}
