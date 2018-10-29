CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: tests.out



tests.out: unittest1.c unittest2.c unittest3.c unittest4.c unittest5.c dominion.c dominion.h dominion_helpers.h rngs.h
	
	echo "Result for running tests:" > tests.out
	echo "unittest1.c:" >> tests.out
	gcc -o unittest1 dominion.c dominion.h dominion_helpers.h rngs.h unittest1.c $(CFLAGS)
	./unittest1 >> tests.out
	gcov dominion.c dominion.h dominion_helpers.h rngs.h >> tests.out
	
	echo "Result for running tests:" > tests.out
	echo "unittest2.c:" >> tests.out
	gcc -o unittest2 dominion.c dominion.h dominion_helpers.h rngs.h unittest2.c $(CFLAGS)
	./unittest2 >> tests.out
	gcov dominion.c dominion.h dominion_helpers.h rngs.h >> tests.out
	
	echo "Result for running tests:" > tests.out
	echo "unittest3.c:" >> tests.out
	gcc -o unittest3 dominion.c dominion.h dominion_helpers.h rngs.h unittest3.c $(CFLAGS)
	./unittest3 >> tests.out
	gcov dominion.c dominion.h dominion_helpers.h rngs.h >> tests.out
	
	echo "Result for running tests:" > tests.out
	echo "unittest4.c:" >> tests.out
	gcc -o unittest4 dominion.c dominion.h dominion_helpers.h rngs.h unittest4.c $(CFLAGS)
	./unittest4 >> tests.out
	gcov dominion.c dominion.h dominion_helpers.h rngs.h >> tests.out

clean:
	rm tests.out

cleanall: 
	rm tests.out unittest1 unittest2 unittest3 unittest4 *.gcda *.gcno *.gcov
