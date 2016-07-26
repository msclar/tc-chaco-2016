try:
    while True:
        v = input()
        m = 0
        vs = v.split("x")
        m = max(len(vs[0]), len(vs[-1]))
        for f in vs[1:-1]:
            m = max(m, len(f) // 2)
        print(m)
except:
    pass
