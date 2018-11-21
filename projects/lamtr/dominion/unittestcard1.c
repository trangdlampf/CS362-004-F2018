#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>		// From study of random in lectures and work

// This is from the cardtest4.c (on steward) that was provided in Lectures_Week_4
// I modified my cardtest1.c for Adventurer (form Assignment 3) and I will use Random variables 
// TA Hours: oregonstate.instructure.com/courses/1692917/pages/instructor-slash-ta-information-and-communication-policy?module_item_id=18202249 
#define TESTCARD "adventurer"

int main()
{
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
	int numActions = 1;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	
	int drawntreasure=0;
	int cardDrawn = silver; // testing for silver
	int z = 0;// this is the counter for the temp hand
	
	struct gameState G, testG;
	int k[10] = {adventurer, village, council_room, embargo, minion, mine, 
				cutpurse, sea_hag, tribute, smithy};

	// Random Test: test for number of players between 2 - 5				
	/* int myRandNum;	
	myRandNum = (rand() %(5 - 2 + 1)) + 2; // 5 is upper, 2 is lower */
				
	// Initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
		
	printf("------------- Testing Card: %s ------------\n", TESTCARD);
	
	// Copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	// cardEffect(adventurer, &testG, handpos, thisPlayer, drawntreasure, z, cardDrawn);

	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) 
	{
		printf("Drawn Card = %d, expected = %d\n", cardDrawn, drawntreasure); // cardDrawn is replaced by myRandNum
		// drawntreasure++;
	}
	// assert(myRandNum == drawntreasure);
	
	// THIS IS MY CODE FROM ASSIGNMENT 3: 
	// cardResult_Adventurer(&myTestGameState, 0);
	// printf("Expected: %d, Versus What We Get: %d\n", myGameState.handCount[myGameState.whoseTurn] + 2, myTestGameState.handCount[myTestGameState.whoseTurn]);
		
	return 0;
}

/* 
// THIS IS THE FOUNCTION I TOOK OUT OF cardEffect from dominion.c
// CHANGE: create new functions for assignment 2: adventurer, etc.
int cardResult_Adventurer(struct gameState *state, int handPos, int currentPlayer, int drawntreasure, int z, int cardDrawn) {
	
	int temphand[MAX_HAND]; // CHANGE
	
	  while(drawntreasure<2){
	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
	  shuffle(currentPlayer, state);
	}
	drawCard(currentPlayer, state);
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
	if (cardDrawn == copper || cardDrawn == copper || cardDrawn == gold) // CHANGE silver to copper so there are 2 "copper"
	  drawntreasure++;
	else{
	  temphand[z]=cardDrawn;
	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
	  z++;
	}
      }
      while(z-1>=0){
	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
	z=z-1;
      }
      return 0;	
}
*/
