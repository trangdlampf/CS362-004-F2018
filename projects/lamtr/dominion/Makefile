CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	
unittestcard1: unittestcard1.c dominion.o rngs.o
	echo "unittestcard1.c:" >> unittestcard1.out
	gcc -o unittestcard1 unittestcard1.c dominion.o rngs.o $(CFLAGS)
	./unittestcard1 >> unittestcard1.out
	gcov -f -b dominion.c >> unittestcard1.out	
	
unittestcard2: unittestcard2.c dominion.o rngs.o
	echo "unittestcard2.c:" >> unittestcard2.out
	gcc -o unittestcard2 unittestcard2.c dominion.o rngs.o $(CFLAGS)
	./unittestcard2 >> unittestcard2.out
	gcov -f -b dominion.c >> unittestcard2.out	

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	echo "randomtestcard1.c:" >> randomtestcard1.out
	gcc -o randomtestcard1 randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out
	gcov -f -b dominion.c >> randomtestcard1.out
	
randomtestcard2: randomtestcard2.c dominion.o rngs.o
	echo "randomtestcard2.c:" >> randomtestcard2.out
	gcc -o randomtestcard2 randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out
	gcov -f -b dominion.c >> randomtestcard2.out

unittestadventurer: unittestadventurer.c dominion.o rngs.o
	echo "unittestadventurer.c:" >> unittestadventurer.out
	gcc -o unittestadventurer unittestadventurer.c dominion.o rngs.o $(CFLAGS)
	./unittestadventurer >> unittestadventurer.out
	gcov -f -b dominion.c >> unittestadventurer.out	

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -o randomtestadventurer randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov -f -b dominion.c >> randomtestadventurer.out	
	
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unittestcard1 unittestcard2 randomtestcard1 randomtestcard2 unittestadventurer randomtestadventurer

clean:
	rm -f *.o playdom.exe playdom player player.exe unittestcard1 unittestcard2 randomtestcard1 randomtestcard2 unittestadventurer randomtestadventurer *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
