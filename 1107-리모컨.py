def is_possible(channel, broke):
    for button in str(channel):
        if button in broke:
            return False
    return True


N = input()
M = input()
if M:
    broke = raw_input().split()
else:
    broke = ""
greater_minus = less_plus = 0
greater = less = N
greater_strokes = greater_minus + len(str(greater))
less_strokes = less_plus + len(str(less))
while greater != 100 and not is_possible(greater, broke) and greater_strokes < abs(100 - N):
    greater += 1
    greater_minus += 1
    greater_strokes = greater_minus + len(str(greater))
while 0 <= less != 100 and not is_possible(less, broke) and less_strokes < abs(100 - N) and less_strokes < greater_strokes:
    less -= 1
    less_plus += 1
    less_strokes = less_plus + len(str(less))
if less < 0:
    print min(greater_strokes, abs(100 - N))
else:
    print min(greater_strokes, less_strokes, abs(100 - N))
