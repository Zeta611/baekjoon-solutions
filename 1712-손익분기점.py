a, b, c = map(int, input().split())
if b >= c:
    print(-1)
else:
    print(a // (c - b) + 1)

# Short coding
a,b,c=map(int,input().split())
print(-(b>=c)or a//(c-b)+1)
