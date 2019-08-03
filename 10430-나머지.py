a, b, c = map(int, raw_input().split())
print (a + b) % c
print (a % c + b % c) % c
print a * b % c
print a % c * (b % c) % c
