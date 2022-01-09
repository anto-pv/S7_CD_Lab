/*
1. First copy the lex.l and yacc.y files with exact filename
2. then
drop these in terminal............... 
yacc -d yacc.y
lex lex.l
gcc lex.yy.c y.tab.c -w
./a.out 
.....................
Enter Any Arithmetic Expression 
1+3

Result=4

*/