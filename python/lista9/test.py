import matplotlib.pyplot as plt
import timeit
fig, (ax1) = plt.subplots(1, 1)
# fig to cały obrazek, ax1, ax2, ax3 to wykresy na obrazku


def fib1(x):
    if (x == 0):
        return 1
    return (fib1(x-1) * x)

def fib2(x):
    ans=1
    for i in range(x):
        ans+=x
    return ans


        


xs = [n for n in range(1, 30, 5)]
ys1 = [timeit.timeit(lambda: fib1(i), number=100) for i in xs]
ys2 = [timeit.timeit(lambda: fib2(i), number=100) for i in xs]


plt.plot(xs, ys1, marker='x')
plt.plot(xs, ys2, marker='o')
'''
ax1.plot(xs, ys1, marker='x')
ax1.set_title('rekurencyjna')
ax1.set_ylabel("sec")
ax2.plot(xs, ys2, marker='*')
ax2.set_title('iteracyjna')
'''
plt.show()
