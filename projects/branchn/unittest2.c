#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

// Testing for supplyCount (function returns integer for the amount of a specific type of card given a specific number.)
// int supplyCount(int card, struct gameState *state) {
//   return state->supplyCount[card];
// }

#define TESTFUNC "supplyCount()"

int main() {
    int handpos = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Function: %s ----------------\n", TESTFUNC);

	// ----------- TEST 1: Smithy Count --------------
	printf("TEST 1: Smithy Count\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("Smithy count from supplyCount = %d, From GameState = %d\n", supplyCount(smithy, &testG), testG.supplyCount[smithy]);
	assert(supplyCount(smithy, &testG) == testG.supplyCount[smithy]);

	// ----------- TEST 2: Adventurer Count --------------
	printf("TEST 2: Adventurer Count\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("Adventurer count from supplyCount = %d, From GameState = %d\n", supplyCount(adventurer, &testG), testG.supplyCount[adventurer]);
	assert(supplyCount(adventurer, &testG) == testG.supplyCount[adventurer]);

	// ----------- TEST 3: Salvager Count --------------
	printf("TEST 3: Salvager Count\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("Salvager count from supplyCount = %d, From GameState = %d\n", supplyCount(salvager, &testG), testG.supplyCount[salvager]);
	assert(supplyCount(salvager, &testG) == testG.supplyCount[salvager]);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNC);
	return 0;
}