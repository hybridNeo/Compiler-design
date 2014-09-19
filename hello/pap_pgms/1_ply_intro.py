# ply : python lex and yacc
# does not generate a program
# this itself allows us tokenize the input
# this allos us to specify actions
# 1. import ply.lex
# 2. a list or a tuple of tokens
# 3. rule for each token ; specified as t_tokenname = regex
# 4. rule with action : specified as a function t_tokenname
#		document string of the fn is the regular expr
#		then action follows
# 5. ignore a few char
import ply.lex as lex
tokens = ('NUMBER', 'WORD')
#t_NUMBER = '\d+'
def t_NUMBER(t) :
	r'\d+'
	print(t.value)
t_WORD = r'\w+'
def t_newline(t) :
	r'\n'
	print("new line")
t_ignore = ' \t'
lexer = lex.lex()
lexer.input('1729 has 1 and 2\n and 7 and 9')
for t in lexer:
	pass










