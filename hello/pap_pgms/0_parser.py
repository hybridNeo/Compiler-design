# parsing
import ply.lex as lex
import ply.yacc as yacc
tokens = ('NUMBER',)
def t_NUMBER(t):
	r'\d+'
	return t
def p_sentence(p) :
	'sentence : NUMBER'
#	p[0] = 'ok'
	p[0] = p[1]
lexer = lex.lex()
parser = yacc.yacc()
res = parser.parse('1234')
print(res)


