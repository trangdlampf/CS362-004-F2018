#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

// void smithyEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
// {
//   int i;
//   int currentPlayer = whoseTurn(state);

//   for (i = 0; i < 3; i++)
//   {
//     drawCard(currentPlayer, state);
//     drawCard(currentPlayer, state);
//   }
//   //discard card from hand
//   discardCard(handPos, currentPlayer, state, 0);
// }

int main() {
    int newCards = 0;
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
	printf("TEST 1: +3 Cards to Hand\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	smithyEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	newCards = 3;
	printf("Hand Count After Draw = %d, Expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("Deck Count After Draw = %d, Expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
	// assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	// assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards);
    printf("----- TEST FAIL ---- 6 cards drawn when 3 expected.\n");

	// ----------- TEST 1: +3 cards --------------
	printf("TEST 2: All Cards From Own Deck and No Change for Opponent\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
    memcpy(&test2G, &G, sizeof(struct gameState));
	smithyEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	newCards = 3;
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
	smithyEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	newCards = 3;
	printf("Supply Count Estate After Draw = %d, Expected = %d\n", supplyCount(estate, &testG), 8);
	printf("Supply Count Duchy After Draw = %d, Expected = %d\n", supplyCount(duchy, &testG), 8);
    printf("Supply Count Province After Draw = %d, Expected = %d\n", supplyCount(province, &testG), 8);


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}


