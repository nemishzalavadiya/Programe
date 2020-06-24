from fractions import Fraction
#                                --> Markov Chain Absorbsion <--
#   p  = | I | 0 |
#        | R | Q |
#   p' = | I  | 0 |
#        | F*R | 0 | 
#   F = (I-Q)^(-1) // now we can answer probability answer using F*R Matrix.
#
def comman_divider(x, y):
    def sub_comman_divider(x, y):
        if y == 0:
            return x
        return sub_comman_divider(y, x%y)
    return sub_comman_divider(abs(x), abs(y))

def simplify(x, y):
    g = comman_divider(x, y)
    return Fraction(int(x/g), int(y/g))

def least_mul(x, y):
    return int(x*y/comman_divider(x,y))

def formMatrixMarkov(matrix):
    sum_of_row = list(map(sum, matrix))
    index0 = list(map(lambda x: x == 0, sum_of_row))
    indices = set([i for i, x in enumerate(index0) if x])
    converted_matrix = []
    for i in range(len(matrix)):
        converted_matrix.append(list(map(lambda x: Fraction(0, 1) if(sum_of_row[i] == 0) else simplify(x, sum_of_row[i]), matrix[i])))
    final_matrix = []
    null_matrix = []
    for i in range(len(converted_matrix)):
        if i not in indices:
            final_matrix.append(converted_matrix[i])
        else:
            null_matrix.append(converted_matrix[i])
    final_matrix.extend(null_matrix)
    print("Intermediat matrix",final_matrix,sep="\n")
    tuned = []
    for i in range(len(final_matrix)):
        tuned.append([])
        join_matrix = []
        for j in range(len(final_matrix)):
            if j not in indices:
                tuned[i].append(final_matrix[i][j])
            else:
                join_matrix.append(final_matrix[i][j])
        tuned[i].extend(join_matrix)
    print("Final Matrix",tuned,sep="\n")
    return [tuned, len(null_matrix)]

def duplicate_matrix(matrix):
    cmat = []
    for i in range(len(matrix)):
        cmat.append([])
        for j in range(len(matrix[i])):
            cmat[i].append(Fraction(matrix[i][j].numerator, matrix[i][j].denominator))
    return cmat

def gauss_elmination(m, values):
    matrix = duplicate_matrix(m)
    for i in range(len(matrix)):
        index = -1
        for j in range(i, len(matrix)):
            if matrix[j][i].numerator != 0:
                index = j
                break
        if index == -1:
            raise ValueError('Gauss elimination failed!')
        matrix[i], matrix[index] = matrix[index], matrix[j]
        values[i], values[index] = values[index], values[i]
        for j in range(i+1, len(matrix)):
            if matrix[j][i].numerator == 0:
                continue
            ratio = matrix[j][i]/-matrix[i][i]
            for k in range(i, len(matrix)):
                matrix[j][k] += ratio * matrix[i][k]
            values[j] += ratio * values[i]
    op = [0 for i in range(len(matrix))]
    for i in range(len(matrix)):
        index = len(matrix) -1 -i
        end = len(matrix) - 1
        while end > index:
            values[index] -= matrix[index][end] * op[end]
            end -= 1
        op[index] = values[index]/matrix[index][index]
    return op

def transpose(matrix):
    tuned = []
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if i == 0:
                tuned.append([])
            tuned[j].append(matrix[i][j])
    return tuned

def inverse(matrix):
    #print(matrix)
    tuned = transpose(matrix)
    inverse_matrix = []
    for i in range(len(tuned)):
        values = [Fraction(int(i==j), 1) for j in range(len(matrix))]
        print("values : ",values)
        inverse_matrix.append(gauss_elmination(tuned, values))
    #print(inverse_matrix)
    return inverse_matrix

def matrix_multiply(mat1, mat2):
    op = []
    for i in range(len(mat1)):
        op.append([])
        for j in range(len(mat2[0])):
            op[i].append(Fraction(0, 1))
            for k in range(len(mat1[0])):
                op[i][j] += mat1[i][k] * mat2[k][j]
    return op

def divideQ_R_matrix(matrix, lengthR):
    lengthQ = len(matrix) - lengthR
    Q = []
    R = []
    for i in range(lengthQ):
        Q.append([int(i==j)-matrix[i][j] for j in range(lengthQ)])
        R.append(matrix[i][lengthQ:])
    return [Q, R]

def solution(matrix):
    op = formMatrixMarkov(matrix)
    if op[1] == len(matrix):
        return [1, 1]
    Q, R = divideQ_R_matrix(*op)
    _inverse = inverse(Q)
    op = matrix_multiply(_inverse, R)
    Row = op[0]
    l = 1
    for item in Row:
        l = least_mul(l, item.denominator)
    op = list(map(lambda x: int(x.numerator*l/x.denominator), Row))
    op.append(l)
    return op
print(solution([[0,1,0,0,0,1],[4,0,0,3,2,0],[0]*6,[0]*6,[0]*6,[0]*6]))