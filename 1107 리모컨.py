def check(channel, broke):
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
cnt_p = cnt_m = 0
N_p = N_m = N
l_p = cnt_p + len(str(N_p))
l_m = cnt_m + len(str(N_m))
while N_p != 100 and not check(N_p, broke) and l_p < abs(100 - N):
    N_p += 1
    cnt_p += 1
    l_p = cnt_p + len(str(N_p))
while 0 <= N_m != 100 and not check(N_m, broke) and l_m < abs(100 - N) and l_m < l_p:
    N_m -= 1
    cnt_m += 1
    l_m = cnt_m + len(str(N_m))
if N_m < 0:
    print min(l_p, abs(100 - N))
else:
    print min(l_p, l_m, abs(100 - N))
