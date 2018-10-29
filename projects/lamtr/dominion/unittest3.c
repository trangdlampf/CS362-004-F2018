#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//Unit Test 3: Is there Copper Coins 
int main (int argc, char** argv) {

	struct gameState myGame;
		myGame.coins = 0;
	
	printf("Unit Test 1: Copper Coin \n");

	myGame.hand[0][0] = copper;
		myGame.hand[0][1] = copper;
		myGame.hand[0][2] = copper;
		myGame.hand[0][3] = copper;
		myGame.hand[0][4] = copper;
		myGame.hand[0][5] = copper;
		myGame.hand[0][6] = copper;
		myGame.hand[0][7] = copper;
		myGame.hand[0][8] = copper;
		myGame.hand[0][9] = copper;
		updateCoins(0,&myGame, 0);
		
		printf("We should have 10 copper coins: %d\n", myGame.coins);
		if(myGame.coins == 10)
			printf("Test Passed\n");
		else
			printf("Test Failed\n");

	return 0;
}
