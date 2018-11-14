#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "great_hall"

// void great_hallEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
// {
//   int currentPlayer = whoseTurn(state);

//   //+1 Card
//   drawCard(currentPlayer, state);

//   //+1 Actions
//   state->numActions++;

//   //discard card from hand
//   discardCard(handPos, currentPlayer, state, 0);
// }

int checkGreatHallEffect(int great_hall, int choice1, int choice2, int choice3, struct gameState G, int handpos, int bonus)
{

	int newCards = 1;
    int discarded = 1;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState testG, test2G;

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: +1 Card to Hand, +1 Action --------------
	printf("TEST 1: +1 Card to Hand, +1 Action\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	great_hallEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
	int thisPlayer = whoseTurn(&G);
	printf("Hand Count After Draw = %d, Expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("Deck Count After Draw = %d, Expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    printf("Action Count After Draw = %d, Expected = %d\n", testG.numActions, G.numActions + 1);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards);
	assert(testG.numActions == testG.numActions + 1);

	// TEST 2: All Cards From Own Deck and No Change for Opponent\n
	printf("TEST 2: All Cards From Own Deck and No Change for Opponent\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
    memcpy(&test2G, &G, sizeof(struct gameState));
	int thisPlayer = whoseTurn(&G);
	int this2Player = whoseTurn(&testG);
	great_hallEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
    if (thisPlayer < (testG.numPlayers - 1)){
        testG.whoseTurn = thisPlayer + 1;//Still safe to increment
    }
    else {
        testG.whoseTurn = 0; //Max player has been reached, loop back around to player 1
    }
    if (this2Player < (test2G.numPlayers - 1)){
        test2G.whoseTurn = this2Player + 1;//Still safe to increment
    }
    else {
        test2G.whoseTurn = 0; //Max player has been reached, loop back around to player 1
    }
	printf("Opponent Deck Count After Draw = %d, Expected = %d\n", testG.deckCount[testG.whoseTurn], test2G.deckCount[test2G.whoseTurn]);
    printf("Opponent Hand Count After Draw = %d, Expected = %d\n", testG.handCount[testG.whoseTurn], test2G.handCount[test2G.whoseTurn]);

	assert(testG.deckCount[testG.whoseTurn] == test2G.deckCount[test2G.whoseTurn]);
	assert(testG.handCount[testG.whoseTurn] == test2G.handCount[test2G.whoseTurn]);

	// ----------- TEST 3: No State Change for Victory Card Pile or Kingdom Card Pile --------------
	printf("TEST 3: No state change should occur to the victory card piles.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	int thisPlayer = whoseTurn(&G);
	great_hallEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);

	// printf("Supply Count Estate After Draw = %d, Expected = %d\n", supplyCount(estate, &testG), 8);
	// printf("Supply Count Duchy After Draw = %d, Expected = %d\n", supplyCount(duchy, &testG), 8);
    // printf("Supply Count Province After Draw = %d, Expected = %d\n", supplyCount(province, &testG), 8);

	printf("Asserting that supply counts for estate, duchy, and province have not changed.\n");

	assert(supplyCount(estate, &G) == supplyCount(estate, &testG));
	assert(supplyCount(duchy, &G) == supplyCount(duchy, &testG));
	assert(supplyCount(province, &G) == supplyCount(province, &testG));

	printf("Supply count tests passed\n");
}

int main() {
    int newCards = 0;
    int discarded = 1;
    int i, j, m, n, p;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	printf("----------------- Random Testing Card: %s ----------------\n", TESTCARD);

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 2000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
		((char*)&G)[i] = floor(Random() * 256);
		}
		p = floor(Random() * 2);
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		checkGreatHallEffect(great_hall, 0, 0, 0, G, 0, 0);
	}

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}


