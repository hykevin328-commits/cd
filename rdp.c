#include<stdio.h>
#include<ctype.h>
#include<string.h>
int i=0;
int error=0;
char input[100];
void E();
void T();
void F();
void E(){
    T();
    while(input[i]=='+'){
        i++;
        T();
        
    }
}

void T(){
    F();
    while(input[i]=='*'){
        i++;
        F();
        
    }
}

void F(){
    if(input[i]=='i'){
        i++;
    }
    else if (input[i]=='('){
        i++;
        E();
        
        if (input[i]==')'){
            i++;
            
        }
        else{
            error=1;
        }
    }
    else{
        error=1;
    }
}

int main(){
    printf("enter the string \n");
    scanf("%s",input);
    strcat(input,"$");
    E();
    if (input[i]=='$' && error==0){
        printf("accepted");
        
        
    }
    else{
        printf("rejectde");
        
    }
    return 0;
}