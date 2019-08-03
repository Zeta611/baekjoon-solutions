def prod(mat1, mat2):
    a1, b1, c1, d1 = mat1[0][0], mat1[0][1], mat1[1][0], mat1[1][1]
    a2, b2, c2, d2 = mat2[0][0], mat2[0][1], mat2[1][0], mat2[1][1]
    a3 = (a1 * a2 + b1 * c2) % 1000000
    b3 = (a1 * b2 + b1 * d2) % 1000000
    c3 = (c1 * a2 + d1 * c2) % 1000000
    d3 = (c1 * b2 + d1 * d2) % 1000000
    return [[a3, b3], [c3, d3]]


def pow(mat, n):
    if n == 0:
        return [[1, 0], [0, 1]]
    if n == 1:
        return mat
    if n == 2:
        return prod(mat, mat)
    half = pow(mat, n / 2)
    if n % 2:
        return prod(mat, pow(half, 2))
    return pow(half, 2)


mat = [[0, 1], [1, 1]]
print sum(pow(mat, input() - 1)[0]) % 1000000
