from sys import stdout, stdin, setrecursionlimit
from io import BytesIO, IOBase
from collections import *
from itertools import *
from random import * 
from bisect import *
from string import *
from queue import *
from heapq import *
from math import *
from re import *
from os import *

####################################---fast-input-output----#########################################


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = read(self._fd, max(fstat(self._fd).st_size, 8192))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = read(self._fd, max(fstat(self._fd).st_size, 8192))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


stdin, stdout = IOWrapper(stdin), IOWrapper(stdout)

graph, mod, szzz =  {}, 10**9 + 7, lambda: sorted(zzz())
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


#################################################---Some Rule For Me To Follow---#################################
"""
    --instants of Reading problem continuously try to understand them.

    --If you Know some-one , Then you probably don't know him !

    --Try & again try, maybe you're just one statement away!


"""
##################################################---START-CODING---###############################################



s = getStr()


north = 0
south = 0
east = 0
weast = 0

for i in s:
    if(i=='S'):
        south+=1
    elif(i=='W'):
        weast+=1
    elif(i=='E'):
        east+=1
    else:
        north+=1


ok = True

if(north and south==0):
    ok = False
if(south and north ==0):
    ok = False

if(east and weast==0):
    ok = False
if (weast and east==0):
    ok = False

print("Yes" if ok else "No")