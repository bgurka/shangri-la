compile:
	gcc functions.h random.c calc.c main.c -lm -o rng
run1:
	rng 50 100
run2:
	rng 111 200
run3:
	rng 1234 300
test:
	rng 10 5
