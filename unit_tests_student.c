// unit_tests student additions
// Larry L. Kiser Oct. 22, 2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "analysis.h"
#include "unit_tests_analysis.h"
#include "unit_tests.h"

//////////////////////////////////////////////////////////////////////////
// Begin unit tests //////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// do the unit tests
// returns the number of failed tests.
int test_student()
{
	int passcount = 0 ;
	int failcount = 0 ;
	struct linked_list list1 ;		// list list pointers for one list
	// Initialize local stack data
	memset( &list1, 0, sizeof( list1 ) ) ;		// set all pointers to NULL (zero)
	
	printf( "\n========= student generated tests on MLK excerpt ===============================\n" ) ;
	int result = read_file( &list1, "MLK_dream_excerpt.txt" ) ;
	assert( result == 113,
		"1 read_file processing MLK_dream_excerpt. Expect word count of 113 returned but got %d.", result )
		? passcount++ : failcount++ ;

	// Add a test to verify that the word "day" is used three times in the list.
	printf("\n================== student generated tests ======================================\n" );
	find_word( &list1, "day") ;
	result = list1.p_current->one_word.word_count ;
	assert(result == 3,
		"Test 1 to check ""day"" word count. Expect word count of 3 returned but got %d.", result)
		? passcount++ : failcount++ ;	
	// Add a test to verify that the word AFTER the word "have" is the word "heat".
	
	find_word( &list1, "have") ;
	result = strcmp ( list1.p_current->p_next->one_word.unique_word, "heat") ; 
	assert( result == 0,
		"Test 2 check word after ""have"" is ""heat"". Expect word ""heat"" and result of 0 returned but got %s, %d.", list1.p_current->p_next->one_word.unique_word, result)
	? passcount++ : failcount++ ;	
	// Add a test to verify that the last word in the list is "with"
	find_word( &list1, "with" ) ;
	if ( list1.p_current == list1.p_tail )
	{
		result = 0 ;
	}
	else
	{
		result = 1 ;
	}
	assert(result == 0,
		"Test 3 to check that with is the last word in the list. Expect result of 0 but got %d.", result)
		? passcount++ : failcount++ ;	
	// Add a test to verify that the next to the last word is "will"	
	result = strcmp ( list1.p_current->p_previous->one_word.unique_word, "will") ; 
	assert( result == 0,
		"Test 4 check word before ""with"" is ""will"". Expect word ""will"" and result of 0 returned but got %s, %d.", list1.p_current->p_previous->one_word.unique_word, result)
		? passcount++ : failcount++ ;


	result = clear_linked_list( &list1 ) ;
	assert( result == 62,
		"6 clear linked list expected to remove 62 entries but got %d.", result )
		? passcount++ : failcount++ ;

	printf( "\nSummary of analysis unit tests:\n%d tests passed\n%d tests failed\n\n", passcount, failcount ) ;
	
	return failcount ;
}
