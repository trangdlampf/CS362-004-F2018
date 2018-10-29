#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

// Testing for numHandCards (function returns integer for number of cards in hand for current player)
// int numHandCards(struct gameState *state) {
//   return state->handCount[ whoseTurn(state) ];
// }

#define TESTFUNC "numHandCards()"

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

	// ----------- TEST 1: Seeded Card Hand --------------
	printf("TEST 1: Seeded Card Hand\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("hand count = %d, expected = %d\n", numHandCards(&G), G.handCount[thisPlayer]);
	assert(numHandCards(&G) == G.handCount[thisPlayer]);

    // ----------- TEST 2: 1 Card Hand --------------
	printf("TEST 2: 1 Card Hand\n");

	// copy the game state to a test case
    G.handCount[thisPlayer] = 1;
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("hand count = %d, expected = %d\n", numHandCards(&G), G.handCount[thisPlayer]);
	assert(numHandCards(&G) == G.handCount[thisPlayer]);

    // ----------- TEST 3: 500 Card Hand --------------
	printf("TEST 3: 500 Card Hand\n");

	// copy the game state to a test case
    G.handCount[thisPlayer] = 500;
	memcpy(&testG, &G, sizeof(struct gameState));


	printf("hand count = %d, expected = %d\n", numHandCards(&G), G.handCount[thisPlayer]);
	assert(numHandCards(&G) == G.handCount[thisPlayer]);

    // ----------- TEST 4: 0 Card Hand --------------
	printf("TEST 4: 0 Card Hand\n");

	// copy the game state to a test case
    G.handCount[thisPlayer] = 0;
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("hand count = %d, expected = %d\n", numHandCards(&G), G.handCount[thisPlayer]);
	assert(numHandCards(&G) == G.handCount[thisPlayer]);

    // ----------- TEST 4: 501 Card Hand --------------
	printf("TEST 5: 501 Card Hand\n");

	// copy the game state to a test case
    G.handCount[thisPlayer] = 501;
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("hand count = %d, expected = %d\n", numHandCards(&G), G.handCount[thisPlayer]);
	assert(numHandCards(&G) == G.handCount[thisPlayer]);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNC);
	return 0;
}