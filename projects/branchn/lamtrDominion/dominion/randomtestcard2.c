#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

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
	struct gameState testG, test2G;
	int failedTests = 0;

	// printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: +1 Card to Hand, +1 Action --------------
	// printf("TEST 1: +1 Card to Hand, +1 Action\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	great_hallEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
	int thisPlayer = whoseTurn(&G);
	// printf("Hand Count After Draw = %d, Expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	// printf("Deck Count After Draw = %d, Expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    // printf("Action Count After Draw = %d, Expected = %d\n", testG.numActions, G.numActions + 1);
	if (!(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded))
	{
		failedTests++;
	}
	if (!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards))
	{
		failedTests++;
	}
	if (!(testG.numActions == testG.numActions + 1))
	{
		failedTests++;
	}

	// TEST 2: All Cards From Own Deck and No Change for Opponent\n
	// printf("TEST 2: All Cards From Own Deck and No Change for Opponent\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
    memcpy(&test2G, &G, sizeof(struct gameState));
	thisPlayer = whoseTurn(&G);
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
	// printf("Opponent Deck Count After Draw = %d, Expected = %d\n", testG.deckCount[testG.whoseTurn], test2G.deckCount[test2G.whoseTurn]);
    // printf("Opponent Hand Count After Draw = %d, Expected = %d\n", testG.handCount[testG.whoseTurn], test2G.handCount[test2G.whoseTurn]);

	if (!(testG.deckCount[testG.whoseTurn] == test2G.deckCount[test2G.whoseTurn]))
	{
		failedTests++;
	}
	if (!(testG.handCount[testG.whoseTurn] == test2G.handCount[test2G.whoseTurn]))
	{
		failedTests++;
	}

	// ----------- TEST 3: No State Change for Victory Card Pile or Kingdom Card Pile --------------
	// printf("TEST 3: No state change should occur to the victory card piles.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	thisPlayer = whoseTurn(&G);
	great_hallEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);

	// printf("Supply Count Estate After Draw = %d, Expected = %d\n", supplyCount(estate, &testG), 8);
	// printf("Supply Count Duchy After Draw = %d, Expected = %d\n", supplyCount(duchy, &testG), 8);
    // printf("Supply Count Province After Draw = %d, Expected = %d\n", supplyCount(province, &testG), 8);

	// printf("Asserting that supply counts for estate, duchy, and province have not changed.\n");

	// assert(supplyCount(estate, &G) == supplyCount(estate, &testG));
	// assert(supplyCount(duchy, &G) == supplyCount(duchy, &testG));
	// assert(supplyCount(province, &G) == supplyCount(province, &testG));

	if (!(supplyCount(estate, &G) == supplyCount(estate, &testG)))
	{
		failedTests++;
	}
	if (!(supplyCount(duchy, &G) == supplyCount(duchy, &testG)))
	{
		failedTests++;
	}
	if (!(supplyCount(province, &G) == supplyCount(province, &testG)))
	{
		failedTests++;
	}

	// printf("Supply count tests passed\n");

	return failedTests;
}

int main() {
	int i, n, p;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int totalFailedTests = 0;

	printf("----------------- Random Testing Card: %s ----------------\n", TESTCARD);

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 2000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = floor(Random() * 256);
		}
		int playerCount = floor(Random());
		// printf("Random num for playerCount is %d\n", playerCount);
		playerCount = playerCount % 2 + 2;
		// printf("Player count is %d\n", playerCount);
		int randomNum = rand();
		// printf("Random generated number is: %d\n", randomNum);
		initializeGame(playerCount, k, randomNum, &G);
		p = floor(Random() * 2);
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		totalFailedTests += checkGreatHallEffect(great_hall, 0, 0, 0, G, 0, 0);
	}
	printf("Total number of failed tests: %d\n", totalFailedTests);
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}


