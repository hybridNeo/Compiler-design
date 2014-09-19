import ply.yacc as yacc
import ply.lex as lex
tokens = ('NUMBER', 'PLUS')
t_PLUS = r'\+'
t_ignore = ' \t'
def t_NUMBER(t) :
	'\d+'
	t.value = int(t.value)
	return t
def p_expression(p):
    'expression : NUMBER'
    p[0] = p[1]

def p_expression_plus(p):
    'expression : expression PLUS expression'
    p[0] = p[1] + p[3]
	

lexer = lex.lex()
parser = yacc.yacc()
#res = parser.parse('10 + 20')
res = parser.parse('10')
print(res)



