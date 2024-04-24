# Katarzna Trzos
# Lista 5
# Zadnaie 2
import itertools


class Formula:
    def __init__(self, formula):
        pass

    def eval(self, vars):
        pass

    def __str__(self):
        pass

    def __add__(self, w1, w2):
        return Or(w1, w2)

    def __mul__(self, w1, w2):
        return And(w1, w2)

    def tautology(self):  # checks if formula is tautology
        variables = self.get_variables(set())
        # itertools generates all possibilities of variables values
        for assignment in itertools.product([True, False], repeat=len(variables)):
            # result of formula with the current assignment
            result = self.eval(dict(zip(variables, assignment)))
            if not result:
                return False
        return True

    def get_variables(self, variables):
        if isinstance(self, Variable):
            variables.add(self.name)
        elif isinstance(self, Not):
            self.w.get_variables(variables)
        elif isinstance(self, And) or isinstance(self, Or):
            self.l.get_variables(variables)
            self.r.get_variables(variables)
        return variables


class Variable(Formula):
    def __init__(self, name):
        self.name = name

    def eval(self, vars):
        if self.name in vars:
            return vars[self.name]
        else:
            return NotValidVariable(self.name)

    def __str__(self):
        return self.name


class Constant(Formula):
    def __init__(self, value):
        self.value = value

    def eval(self, vars):
        return self.value

    def __str__(self):
        return str(self.value)


class And(Formula):
    def __init__(self, w1, w2):
        self.l = w1
        self.r = w2

    def eval(self, vars):
        return self.l.eval(vars) and self.r.eval(vars)

    def __str__(self):
        return f'({str(self.l)} {"∧"} {str(self.r)})'

    def simplify(self):
        if isinstance(self.l, Constant) and self.l.eval({}) == False:
            return Constant(False)
        if isinstance(self.r, Constant) and self.r.eval({}) == False:
            return Constant(False)
        if isinstance(self.l, Constant) and self.l.eval({}) == True:
            return self.r
        if isinstance(self.r, Constant) and self.r.eval({}) == True:
            return self.l
        return self


class Or(Formula):
    def __init__(self, w1, w2):
        self.l = w1
        self.r = w2

    def eval(self, vars):
        return self.l.eval(vars) or self.r.eval(vars)

    def __str__(self):
        return f'({str(self.l)} {"∨"} {str(self.r)})'

    def simplify(self):

        if isinstance(self.l, Constant) and self.l.eval({}) == False:
            return self.r
        if isinstance(self.r, Constant) and self.r.eval({}) == False:
            return self.l
        if isinstance(self.l, Constant) and self.l.eval({}) == True:
            return Constant(True)
        if isinstance(self.r, Constant) and self.r.eval({}) == True:
            return Constant(True)

        return self


class Not(Formula):
    def __init__(self, w):
        self.w = w

    def eval(self, vars):
        return not self.w.eval(vars)

    def __str__(self):
        return f'{"¬"}({str(self.w)})'


class NotValidVariable(Exception):
    def __init__(self, name):
        self.name = name

    def __str__(self) -> str:
        return f'No declared variable {self.name}'


formula = Or(Not(Variable("x")), And(Variable("y"), Constant(True)))
variables = {"x": True, "y": False}
result = formula.eval(variables)
print("Formula : ", formula)
print("Symplify ", formula.simplify())
print("Tautology? ", formula.tautology())
print('\n')


formula = And(Variable('p'), Constant(False))
print("Formula : ", formula)
print("Symplify ", formula.simplify())
print("Tautology? ", formula.tautology())
print('\n')

formula = Or(Variable('p'), Constant(False))
print("Formula : ", formula)
print("Symplify ", formula.simplify())
print("Tautology? : ", formula.tautology())
print('\n')

formula = And(And(Variable('x'), Variable('y')), Constant(True))
print("Formula : ", formula)
print("Symolify : ", formula.simplify())
print("Tautology? : ", formula.tautology())
print('\n')
