class F:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def __str__(self):
        return "Calculates f(x) = ax^2+bx+c"
    
    def __call__(self, x):
        return self.a * x**2 + self.b * x + self.c
f = F(10, 20 , 30)
print(f)
print(f(100))
