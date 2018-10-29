#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//Unit Test 2: Is there Silver Coins 
int main (int argc, char** argv) {

	struct gameState myGame;
		myGame.coins = 0;
	
	printf("Unit Test 1: Silver Coin \n");

	myGame.hand[0][0] = silver;
		myGame.hand[0][1] = silver;
		myGame.hand[0][2] = silver;
		myGame.hand[0][3] = silver;
		myGame.hand[0][4] = silver;
		myGame.hand[0][5] = silver;
		myGame.hand[0][6] = silver;
		myGame.hand[0][7] = silver;
		myGame.hand[0][8] = silver;
		myGame.hand[0][9] = silver;
		updateCoins(0,&myGame, 0);
		
		printf("We should have 10 silver coins: %d\n", myGame.coins);
		if(myGame.coins == 10)
			printf("Test Passed\n");
		else
			printf("Test Failed\n");

	return 0;
}
