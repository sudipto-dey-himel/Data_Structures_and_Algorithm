#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[100];
char infix[100];
char num[100];
char op[100];
char rev[100];
char postfix[100];
char prefix[100];

int main() {
    printf("Input the INFIX Exprerssion ::  ");
    gets(s);
    infix[0]='(';
    strcat(infix, s);
    strcat(infix, ")");
    int i, j=0, x=0, in=0, top=-1;
    for(i=strlen(infix)-1; i>=0; i--) {
        if(infix[i]=='(')
        rev[x++]=')';
        else if(infix[i]==')')
        rev[x++]='(';
        else
        rev[x++]=infix[i];
    }

    for(i=0; i<strlen(rev); i++) {
        if((rev[i]>='0' && rev[i]<='9') || (rev[i]>='A' && rev[i]<='Z') || (rev[i]>='a' && rev[i]<='z'))
        num[j++]=rev[i];
        else {
            for(x=0; x<j; x++) 
            postfix[in++]=num[x];
            postfix[in++]=' ';
            memset(num, 0, sizeof(num));
            j=0;

            if(rev[i]=='(')
            op[++top]=rev[i];
            else if(rev[i]=='^')
            op[++top]=rev[i];
            else if(rev[i]=='*' || rev[i]=='/' || rev[i]=='%') {
                while(1) {
                    if(op[top]=='^') {
                        postfix[in++]=op[top--];
                        postfix[in++]=' ';
                    }
                    else
                    break;
                }
                op[++top]=rev[i];
            }
            else if(rev[i]=='+' || rev[i]=='-') {
                while(1) {
                    if(op[top]=='^' || op[top]=='*' || op[top]=='/' || op[top]=='%') {
                        postfix[in++]=op[top--];
                        postfix[in++]=' ';
                    }
                    else
                    break;
                }
                op[++top]=rev[i];
            }
            else if(rev[i]==')') {
                while(1) {
                    if(op[top]=='(') {
                        top--;
                        break;
                    }
                    else {
                        postfix[in++]=op[top--];
                        postfix[in++]=' ';
                    }
                }
            }
        }
    }
    x=0;
    for(i=strlen(postfix)-1; i>=0; i--) {
        if(postfix[i]=='(')
        prefix[x++]=')';
        else if(postfix[i]==')')
        prefix[x++]='(';
        else
        prefix[x++]=postfix[i];
    }
    prefix[x]='\0';
    printf("Prefix Expresion :: %s", prefix);

    return 0;
}
