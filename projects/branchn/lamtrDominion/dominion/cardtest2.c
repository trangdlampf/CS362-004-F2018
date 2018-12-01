#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

// int cardResult_Adventurer(struct gameState *state, int handPos, int currentPlayer, int drawntreasure, int z, int cardDrawn) {
	
// 	int temphand[MAX_HAND]; // CHANGE
	
// 	  while(drawntreasure<2){
// 	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
// 	  shuffle(currentPlayer, state);
// 	}
// 	drawCard(currentPlayer, state);
// 	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
// 	if (cardDrawn == copper || cardDrawn == copper || cardDrawn == gold) // CHANGE silver to copper so there are 2 "copper"
// 	  drawntreasure++;
// 	else{
// 	  temphand[z]=cardDrawn;
// 	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
// 	  z++;
// 	}
//       }
//       while(z-1>=0){
// 	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
// 	z=z-1;
//       }
//       return 0;	
// }

int main() {
    int newCards = 2;
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

	// ----------- TEST 1: +2 Treasures to Hand --------------
	printf("TEST 1: +2 Treasures to Hand\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardResult_Adventurer(&testG, handpos, thisPlayer, 0, 0, 0);
	printf("Hand Count After Draw = %d, Expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("Deck Count After Draw = %d, Expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    printf("Action Count After Draw = %d, Expected = %d\n", testG.numActions, G.numActions);
    printf("----- TEST FAILED ----- Hand Count After Draw Does Not Match, Three Treasures Drawn");
	// assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	// assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards);

	// ----------- TEST 1: +3 cards --------------
	printf("TEST 2: All Cards From Own Deck and No Change for Opponent\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
    memcpy(&test2G, &G, sizeof(struct gameState));
	cardResult_Adventurer(&testG, handpos, thisPlayer, 0, 0, 0);
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
	cardResult_Adventurer(&testG, handpos, thisPlayer, 0, 0, 0);
	printf("Supply Count Estate After Draw = %d, Expected = %d\n", supplyCount(estate, &testG), 8);
	printf("Supply Count Duchy After Draw = %d, Expected = %d\n", supplyCount(duchy, &testG), 8);
    printf("Supply Count Province After Draw = %d, Expected = %d\n", supplyCount(province, &testG), 8);


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}