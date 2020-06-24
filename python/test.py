from fractions import Fraction
l =[]
for i in range(10):
	m =[]
	for j in range(10):
		if j==0:
			m.append(Fraction(i,-1))
			continue
		m.append(Fraction(i,j))
	l.append(m)
for i in l:
	for j in i:
		print(j.numerator,j.denominator)

