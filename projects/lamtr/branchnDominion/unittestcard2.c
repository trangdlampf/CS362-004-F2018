#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>		// From study of random in lectures and work

// This is from the cardtest4.c (on steward) that was provided in Lectures_Week_4
// I modified my cardtest3.c for Council_Room (form Assignment 3) and I will use Random variables  
#define TESTCARD "council room"

int main()
{
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
	int numActions = 1;
	int numBuys	= 1;		// Every player starts out with 1 buy. Council Room let you buy get an extra buy. 
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, village, council_room, embargo, minion, mine, 
				cutpurse, sea_hag, tribute, smithy};
	
	// Random Test: for number of cards	
	int myRandNum;	
	myRandNum = (rand() %(4 - 1 + 1)) + 1; // 4 is upper, 1 is lower 					
				
	// Initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
		
	printf("------------- Testing Card: %s ------------\n", TESTCARD);
	
	// Copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));


	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);
		
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + myRandNum - discarded);  		// 4 is replaced by myRandNum
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - myRandNum + shuffledCards);	// 4 is replaced by myRandNum
	printf("number of buys = %d, expected = %d\n", testG.numBuys, G.numBuys + 1);

	// assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + myRandNum - discarded);		// 4 is replaced by myRandNum
	// assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - myRandNum + shuffledCards);	// 4 is replaced by myRandNum
	// assert(testG.numBuys == G.numBuys + 1);
	
	// Note: for loop is similar to the one for council_room at line 688 from dominion.c 
    // Each other player draws a card
    for (i = 0; i < testG.numPlayers; i++)
	{
	  if ( i != thisPlayer ) // currentPlayer
	    {
	    // drawCard(i, gameState);
		printf("hand count = %d, expected = %d\n", testG.handCount[i], G.handCount[i] + 1 - discarded);
		printf("deck count = %d, expected = %d\n", testG.deckCount[i], G.deckCount[i] - 1 + shuffledCards);		  
	    }
	}
	
	return 0;
}

