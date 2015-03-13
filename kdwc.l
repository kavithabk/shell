%{
/*Lex Pgm to count chars,words,lines and blanks in a given text*/
int wc,lc,cc;
%}
word  [^ \t\n]+
eol \n
%%
{word} {wc++;cc+=yyleng;}
{eol} {lc++;cc++;}
[ ] {cc++;}
[\t] {cc++;}
%%
main(int argc,char *argv[])
{
stdin=fopen(argv[1],"r");
if(argc>2)
  printf("error.usage:wc<filename>\n");
else
{
yylex();
printf("characters: %d\nwords: %d\nlines: %d\n",cc,wc,lc);
}

}
