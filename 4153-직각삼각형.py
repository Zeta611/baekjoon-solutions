while True:
    lengths = list(map(int, input().split()))
    if lengths == [0, 0, 0]:
        break
    m = max(lengths)
    lengths.remove(m)
    if m**2 == lengths[0]**2 + lengths[1]**2:
        print("right")
    else:
        print("wrong")
