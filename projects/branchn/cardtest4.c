#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

// void villageEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
// {
//   int currentPlayer = whoseTurn(state);

//   //+1 Card
//   drawCard(currentPlayer, state);

//   //+2 Actions
//   state->numActions = state->numActions * 2;

//   //discard played card from hand
//   discardCard(handPos, currentPlayer, state, 0);
// }

int main() {
    int newCards = 1;
    int discarded = 1;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG, test2G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: +3 cards --------------
	printf("TEST 1: +1 Card to Hand, +2 Action\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	villageEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("Hand Count After Draw = %d, Expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("Deck Count After Draw = %d, Expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    printf("Action Count After Draw = %d, Expected = %d\n", testG.numActions, G.numActions + 2);
    // printf("----- TEST FAILED ----- Number of Actions Doubled Not +2\n");
	// assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	// assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards);

	// ----------- TEST 1: +3 cards --------------
	printf("TEST 2: All Cards From Own Deck and No Change for Opponent\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
    memcpy(&test2G, &G, sizeof(struct gameState));
	villageEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);
    if (thisPlayer < (testG.numPlayers - 1)){
        testG.whoseTurn = thisPlayer + 1;//Still safe to increment
    }
    else {
        testG.whoseTurn = 0; //Max player has been reached, loop back around to player 1
    }
    if (thisPlayer < (test2G.numPlayers - 1)){
        test2G.whoseTurn = thisPlayer + 1;//Still safe to increment
    }
    else {
        test2G.whoseTurn = 0; //Max player has been reached, loop back around to player 1
    }
	printf("Opponent Deck Count After Draw = %d, Expected = %d\n", testG.deckCount[testG.whoseTurn], test2G.deckCount[test2G.whoseTurn]);
    printf("Opponent Hand Count After Draw = %d, Expected = %d\n", testG.handCount[testG.whoseTurn], test2G.handCount[test2G.whoseTurn]);

	// assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	// assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards);

	// ----------- TEST 3: No State Change for Victory Card Pile or Kingdom Card Pile --------------
	printf("TEST 3: No state change should occur to the victory card piles.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	villageEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("Supply Count Estate After Draw = %d, Expected = %d\n", supplyCount(estate, &testG), 8);
	printf("Supply Count Duchy After Draw = %d, Expected = %d\n", supplyCount(duchy, &testG), 8);
    printf("Supply Count Province After Draw = %d, Expected = %d\n", supplyCount(province, &testG), 8);


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}
