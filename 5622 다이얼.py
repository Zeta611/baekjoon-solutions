# Contest > Croatian Open Competition in Informatics > COCI 2012/2013 > Contest #6 1

def d(l):
    if 'A'<=l<='C':return 3
    if 'D'<=l<='F':return 4
    if 'G'<=l<='I':return 5
    if 'J'<=l<='L':return 6
    if 'M'<=l<='O':return 7
    if 'P'<=l<='S':return 8
    if 'T'<=l<='V':return 9
    return 10


print sum(map(d,raw_input()))
