def fun(arr, s, en, length, char, t, ans, final, green, ch):
    if ans//t > ch:
        green = not green
        ch += 1
    if s == en:
        final.append(ans)
        return
    for i in arr[s]:
        if str(i) not in length[:-1].split():
            if green:
                fun(arr, i, en, length+str(i)+" ",
                    char, t, ans+char, final, green, ch)
            else:
                aq = ans % t
                fun(arr, i, en, length+str(i)+" ", char,
                    t, ans+char+t-aq, final, not green, ch)
    return


n, m, t, c = map(int, input().split())
d = {}
for i in range(m):
    u, v = map(int, input().split())
    if u in d:
        d[u].append(v)
    else:
        d[u] = [v]
    if v in d:
        d[v].append(u)
    else:
        d[v] = [u]
l = "1 "
final = []
green = True
ch = 0
ret = fun(d, 1, n, l, c, t, 0, final, green, ch)
final = set(final)
final = list(final)
final.sort()
if len(final) > 1:
    print(final[1])
else:
    print(-1)
