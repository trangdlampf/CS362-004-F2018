#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

// Testing for getCost (function returns int representing cost of card or -1 if card does not exist)
// int getCost(int cardNumber)
// {
//   switch( cardNumber )
//     {
//     case curse:
//       return 0;
//     case estate:
//       return 2;
//     case duchy:
//       return 5;
//     case province:
//       return 8;
//     case copper:
//       return 0;
//     case silver:
//       return 3;
//     case gold:
//       return 6;
//     case adventurer:
//       return 6;
//     case council_room:
//       return 5;
//     case feast:
//       return 4;
//     case gardens:
//       return 4;
//     case mine:
//       return 5;
//     case remodel:
//       return 4;
//     case smithy:
//       return 4;
//     case village:
//       return 3;
//     case baron:
//       return 4;
//     case great_hall:
//       return 3;
//     case minion:
//       return 5;
//     case steward:
//       return 3;
//     case tribute:
//       return 5;
//     case ambassador:
//       return 3;
//     case cutpurse:
//       return 4;
//     case embargo:
//       return 2;
//     case outpost:
//       return 5;
//     case salvager:
//       return 4;
//     case sea_hag:
//       return 4;
//     case treasure_map:
//       return 4;
//     }

//   return -1;
// }

#define TESTFUNC "getCost()"

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

	// ----------- TEST 1: Smithy Cost --------------
	printf("TEST 1: Smithy Cost\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("Smithy correct cost = %d, Cost from getCost() = %d\n", 4, getCost(smithy));
	assert(4 == getCost(smithy));

	// ----------- TEST 2: Adventurer Cost --------------
	printf("TEST 2: Adventurer Cost\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("Adventurer correct cost = %d, Cost from getCost() = %d\n", 6, getCost(adventurer));
	assert(6 == getCost(adventurer));

	// ----------- TEST 3: Council_Room Cost --------------
	printf("TEST 3: Council_Room Cost\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("Council_Room correct cost = %d, Cost from getCost() = %d\n", 5, getCost(council_room));
	assert(5 == getCost(council_room));

	// ----------- TEST 3: Blank Card Cost --------------
	printf("TEST 3: Non-Existing Card Cost\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("Non-Existing correct cost = %d, Cost from getCost() = %d\n", -1, getCost(5789));
	assert(-1 == getCost(5789));

	// ----------- TEST 3: NULL Card Cost --------------
	printf("TEST 4: Null Card Cost\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	// printf("Null_card correct cost = %d, Cost from getCost() = %d\n", -1, getCost(NULL));
	// assert(-1 == getCost(NULL));
    printf("----- TEST FAILED ---- getCost() does not handle NULL inputs for cards.\n");

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNC);
	return 0;
}