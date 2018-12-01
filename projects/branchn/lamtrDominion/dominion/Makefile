CFLAGS= -Wall -fpic -coverage -lm -std=c99

default: randomtestresults

randomtestresults: randomtestcard1.c randomtestcard2.c randomtestadventurer.c dominion.c rngs.c

	echo "randomtestcard1.c results:" >> randomtestcard1.out
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out
	gcov dominion.c -f -b >> randomtestcard1.out
	
	echo "randomtestcard2.c:" >> randomtestcard2.out
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out
	gcov dominion.c -f -b >> randomtestcard2.out
	
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c -f -b >> randomtestadventurer.out

	echo "cardtest1.c:" >> cardtest1.out
	gcc -o cardtest1 -g cardtest1.c dominion.c rngs.c $(CFLAGS)
	./cardtest1 >> cardtest1.out
	gcov dominion.c -f -b >> cardtest1.out

	echo "cardtest2.c:" >> cardtest2.out
	gcc -o cardtest2 -g cardtest2.c dominion.c rngs.c $(CFLAGS)
	./cardtest2 >> cardtest2.out
	gcov dominion.c -f -b >> cardtest2.out

	echo "cardtest3.c:" >> cardtest3.out
	gcc -o cardtest3 -g cardtest3.c dominion.c rngs.c $(CFLAGS)
	./cardtest3 >> cardtest3.out
	gcov dominion.c -f -b >> cardtest3.out

	echo "cardtest4.c:" >> cardtest4.out
	gcc -o cardtest4 -g cardtest4.c dominion.c rngs.c $(CFLAGS)
	./cardtest4 >> cardtest4.out
	gcov dominion.c -f -b >> cardtest4.out

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

clean:
	rm randomtestcard1.out randomtestcard2.out randomtestadventurer.out

cleanall: 
	rm cardtest1.out cardtest2.out cardtest3.out cardtest4.out randomtestcard1.out randomtestcard2.out randomtestadventurer.out randomtestcard1 randomtestcard2 randomtestadventurer cardtest1 cardtest2 cardtest3 cardtest4 *.gcda *.gcno *.gcov *.exe.stackdump *.exe
