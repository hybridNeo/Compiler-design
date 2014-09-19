import ply.yacc as yacc
import ply.lex as lex

class MyType:
	def __init__(self, t) :
		self.t = t

tokens = ('INT', 'DBL', 'PLUS')
t_PLUS = r'\+'
t_ignore = ' \t'
def t_DBL(t) :
        r'\d*\.\d+'
        t.lexer.type= 'DBL'
        return t
def t_INT(t) :
        r'\d+'
        t.lexer.type = 'INT'
        return t
def p_expression(p):
    """expression : INT 
            | DBL"""
#    print(p.lexer.type)
    p[0] = MyType(p.lexer.type) 
def p_expression_plus(p):
    'expression : expression PLUS expression'
    p[0] = p[1]
    if p[3].t == 'DBL' :
        p[0].t = 'DBL'

lexer = lex.lex()
parser = yacc.yacc()
"""
res = parser.parse('10')
print(res)
res = parser.parse('2.5')
print(res)
"""
res = parser.parse('10 + 2.5')
print(res.t)
res = parser.parse('10 + 25')
print(res.t)
res = parser.parse('10 + 25 + 40 + 2.5')
print(res.t)


