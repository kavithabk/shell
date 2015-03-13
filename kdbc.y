%{
#include<stdio.h>
#include<stdlib.h>
%}
%token  NUM
%left '+''-'
%left '*''/'
%left '%'
%%
exp : e    {printf("value : %d\n",$1); return 0; };

e: e'+'e {$$=$1+$3; }
 | e'-'e {$$=$1-$3; }
 | e'/'e {if($3==0) {printf("division is not possible\n"); exit(0);} 
                 else $$=$1/$3; }
 | e'*'e {$$=$1*$3; }
 | e'%'e {$$=$1%$3; }
 | '(' e ')' {$$=$2; }
 |NUM {$$=$1;}
 ;
%%
main(int argc,char *argv[])
{
printf("enter an expression :\n");
yyparse();
printf("valid expression\n");
}
yyerror()
{
printf("invalid expression\n");
exit(0);
}
