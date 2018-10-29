#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

// Card Test: smithy 
int main()
{
	int seed = 1000;
	struct gameState myGameState, myTestGameState;
	int k[10] = { smithy, steward, tribute,ambassador, cutpurse, embargo, outpost,salvager, sea_hag, treasure_map };

	printf("Card Test 2: Smithy\n");

	initializeGame(2, k, seed, &myGameState); // 2 is number of Players, k is the Action/kingdom Cards
	memcpy(&myTestGameState, &myGameState, sizeof(struct gameState));
	cardResult_Smithy(&myTestGameState, 0); // check to see if I have this function

	printf("Expected: %d, Versus What We Get: %d\n", myGameState.handCount[myGameState.whoseTurn] + 3, myTestGameState.handCount[myTestGameState.whoseTurn]);

	return 0;
}
