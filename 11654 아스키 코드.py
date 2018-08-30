s = raw_input()
o = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
if '0' <= s <= '9':
    print int(s) + 48
elif 'A' <= s <= 'Z':
    print o.index(s) + 65
else:
    print o.lower().index(s) + 97
