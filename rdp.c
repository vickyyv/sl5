#include<stdio.h>
#include<ctype.h>
#include<string.h>
void E();
void E_D();
void T();
void T_D();
void F();
char str[30],i=0;
int error=0;
int main()
{
printf("\n Enter String\n");
scanf("%s",str);
E();
if(i==strlen(str)&&error==0)
printf("String accepted\n");
else
printf("String cannot be accepted\n");
return 0;
}
void E()
{
T();
E_D();
}
void T()
{
F();
T_D();
}
void T_D()
{
if(str[i]=='*')
{
i++;
F();
T_D();
}
}
void E_D()
{
if(str[i]=='+')
{
i++;
T();
E_D();
}
}
void F()
{
if(str[i]=='(')
{
i++;
E();
if(str[i]==')')
{
i++;
}
else
error=1;
}
else if(isalnum(str[i]))
{i++;}
else
error=1;
}

