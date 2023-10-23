from sys import stdout, stdin


def input():
    return stdin.readline().strip()


graph, mod, szzz = {}, 10**9 + 7, lambda: sorted(zzz())
def getStr(): return input()
def getInt(): return int(input())
def listStr(): return list(input())
def getStrs(): return input().split()
def isInt(s): return '0' <= s[0] <= '9'
def input(): return stdin.readline().strip()
def zzz(): return [int(i) for i in input().split()]
def output(answer, end='\n'): stdout.write(str(answer) + end)
def lcd(xnum1, xnum2): return (xnum1 * xnum2 // gcd(xnum1, xnum2))


dx = [-1, 1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, 1, -1, 1, -1, -1, 1]
daysInMounth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

# Redirect input
stdin = open("input.txt", "r")

# Redirect output
stdout = open("output.txt", "w")

################################################# ---Some Rule For Me To Follow---#################################
"""
    --instants of Reading problem continuously try to understand them.

    --If you Know some-one , Then you probably don't know him !

    --Try & again try, maybe you're just one statement away!


"""
################################################## ---START-CODING---###############################################

print(1e9 < (1 << 29))
