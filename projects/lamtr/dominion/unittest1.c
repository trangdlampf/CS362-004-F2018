#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//Unit Test 1: Is there Gold Coins 
int main (int argc, char** argv) {

	struct gameState myGame;
		myGame.coins = 0;
	
	printf("Unit Test 1: Gold Coin \n");

	myGame.hand[0][0] = gold;
		myGame.hand[0][1] = gold;
		myGame.hand[0][2] = gold;
		myGame.hand[0][3] = gold;
		myGame.hand[0][4] = gold;
		myGame.hand[0][5] = gold;
		myGame.hand[0][6] = gold;
		myGame.hand[0][7] = gold;
		myGame.hand[0][8] = gold;
		myGame.hand[0][9] = gold;
		updateCoins(0,&myGame, 0);
		
		printf("We should have 10 gold coins: %d\n", myGame.coins);
		if(myGame.coins == 10)
			printf("Test Passed\n");
		else
			printf("Test Failed\n");

	return 0;
}
