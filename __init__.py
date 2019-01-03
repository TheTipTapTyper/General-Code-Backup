#!/programs/bin/pypy

import time

def fib1(num):
	if not num or num is 1:
		return 1
	else:
		return fib1(num - 1) + fib1(num - 2)

def fib2(num, prev = {}):
	if num not in prev:
		if not num or num is 1:
			prev[num] = 1
		else:
			prev[num] = fib2(num - 1) + fib2(num - 2)
	return prev[num]

def time_func(func, num):
	start = time.time()
	out = func(num)
	end = time.time()
	return out, end - start

def iter(func, num):
	for i in range(num):
		value, time_elapsed = time_func(func, i)
		string = "Time: " + trunc(time_elapsed) 
		string += " Num: " + str(i) + " Value: " + str(value)
		yield string

def trunc(my_float):
	return "%.3f" % my_float

def test(func, num):
	for i in iter(func, num):
		print(i)


