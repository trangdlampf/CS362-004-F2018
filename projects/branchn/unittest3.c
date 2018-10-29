#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

// Testing for fullDeckCount (function returns number of cards that player can access)
// int fullDeckCount(int player, int card, struct gameState *state) {
//   int i;
//   int count = 0;

//   for (i = 0; i < state->deckCount[player]; i++)
//     {
//       if (state->deck[player][i] == card) count++;
//     }

//   for (i = 0; i < state->handCount[player]; i++)
//     {
//       if (state->hand[player][i] == card) count++;
//     }

//   for (i = 0; i < state->discardCount[player]; i++)
//     {
//       if (state->discard[player][i] == card) count++;
//     }

//   return count;
// }

#define TESTFUNC "fullDeckCount()"

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

	// ----------- TEST 1: Adventurer Count --------------
	printf("TEST 1: Adventurer Count 1 Hand Addition\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

    printf("Adventurer count before Adventurer addition to Player %d's hand: %d\n", testG.whoseTurn, fullDeckCount(testG.whoseTurn, adventurer, &testG));
    printf("Adding one Adventurer to Player %d's hand.\n", testG.whoseTurn);
    testG.hand[testG.whoseTurn][1] = adventurer;

	printf("Adventurer count from testG fullDeckCount after addition: %d, From fullDeckCount from G Before Copy: %d\n", fullDeckCount(testG.whoseTurn, adventurer, &testG), fullDeckCount(G.whoseTurn, adventurer, &G));
	assert(fullDeckCount(testG.whoseTurn, adventurer, &testG) == 1);
    assert(fullDeckCount(G.whoseTurn, adventurer, &G) == 0);

	// ----------- TEST 2: Adventurer Count --------------
	printf("TEST 2: Adventurer Count 1 Discard Addition\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

    printf("Adventurer count before Adventurer addition to Player %d's discard pile: %d\n", testG.whoseTurn, fullDeckCount(testG.whoseTurn, adventurer, &testG));
    printf("Adding one Adventurer to Player %d's discard pile.\n", testG.whoseTurn);
    testG.discard[testG.whoseTurn][1] = adventurer;

	printf("Adventurer count from testG fullDeckCount after addition: %d, From fullDeckCount from G Before Copy: %d\n", fullDeckCount(testG.whoseTurn, adventurer, &testG), fullDeckCount(G.whoseTurn, adventurer, &G));
	// assert(fullDeckCount(testG.whoseTurn, adventurer, &testG) == 1);
    printf("------ TEST FAILED ------\n");
    assert(fullDeckCount(G.whoseTurn, adventurer, &G) == 0);

	// ----------- TEST 2: Adventurer Count Discard and Hand and Deck --------------
	printf("TEST 3: Adventurer Count Discard, Hand, and Deck Additions\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

    printf("Adding one Adventurer to Player %d's discard pile, one to hand, and two to deck.\n", testG.whoseTurn);
    testG.discard[testG.whoseTurn][1] = adventurer;
    testG.hand[testG.whoseTurn][1] = adventurer;
    testG.deck[testG.whoseTurn][1] = adventurer;
    testG.deck[testG.whoseTurn][2] = adventurer;

	printf("Adventurer count from testG fullDeckCount after addition: %d, From fullDeckCount from G Before Copy: %d\n", fullDeckCount(testG.whoseTurn, adventurer, &testG), fullDeckCount(G.whoseTurn, adventurer, &G));
	// assert(fullDeckCount(testG.whoseTurn, adventurer, &testG) == 4);
    printf("------ TEST FAILED ------\n");
    assert(fullDeckCount(G.whoseTurn, adventurer, &G) == 0);
}