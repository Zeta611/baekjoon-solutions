import sys

n = int(sys.stdin.readline())
seq = map(int, sys.stdin.readline().split())
# Simplified
sign = seq[0] > 0
s = m = seq[0]
dp = None
for i in xrange(1, n):
    if seq[i] > m:
        m = seq[i]
    if (seq[i] > 0) == sign:
        s += seq[i]
    else:
        if not dp:
            dp = s
        else:
            dp = max(dp + s, s)
        m = max(dp, m)
        s = seq[i]
        sign = not sign
print max(m, s)

# 1-D DP
# seq_process = []
# sign = seq[0] > 0
# s = m = seq[0]
# n_process = 0
# for i in xrange(1, n):
#     if seq[i] > m:
#         m = seq[i]
#     if (seq[i] > 0) == sign:
#         s += seq[i]
#     else:
#         seq_process.append(s)
#         n_process += 1
#         s = seq[i]
#         sign = not sign
# seq_process.append(s)
# n_process += 1
# seq = seq_process
# n = n_process
# dp = [seq[0]] + [0] * (n - 1)
# if seq[0] > m:
#     m = seq[0]
# for i in xrange(1, n):
#     dp[i] = max(dp[i - 1] + seq[i], seq[i])
#     if dp[i] > m:
#         m = dp[i]
# print m

# Wrong approach
# accumulation = [seq[0]] + [0] * (n - 1)
# if seq[0] > m:
#     m = seq[0]
# for i in xrange(1, n):
#     if seq[i] > m:
#         m = seq[i]
#     accumulation[i] = accumulation[i - 1] + seq[i]
#     if accumulation[i] > m:
#         m = accumulation[i]
# for diff in xrange(2, n + 1):
#     for i in xrange(1, n - diff + 1):
#         j = i + diff
#         sum_consecutive = accumulation[j - 1] - accumulation[i - 1]
#         if sum_consecutive > m:
#             m = sum_consecutive
# print m
