#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

// Card Test: Council Room 
int main()
{
	int seed = 1000;
	struct gameState myGameState, myTestGameState;
	int k[10] = { council_room, gardens, smithy, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map };

	printf("Card Test 3: Council Room\n");

	initializeGame(2, k, seed, &myGameState); // 2 is number of Players, k is the Action/kingdom Cards
	memcpy(&myTestGameState, &myGameState, sizeof(struct gameState));
	council_roomCard(&myTestGameState, 0);

	printf("Expected: %d, Versus What We Get: %d\n", myGameState.handCount[myGameState.whoseTurn] + 4, myTestGameState.handCount[myTestGameState.whoseTurn]);

	return 0;
}
