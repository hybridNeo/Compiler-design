import ply.yacc as yacc
import ply.lex as lex
tokens = ('NUMBER',)
def t_NUMBER(t) :
	'\d+'
	return t
def p_expression(p):
    'expression : NUMBER'
    p[0] = p[1]

lexer = lex.lex()
parser = yacc.yacc()
res = parser.parse('1729')
print(res)



