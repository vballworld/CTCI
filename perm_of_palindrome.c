//
//  main.c
//  permOfPalindrome - note only a-z (lowercase) is supported
//
//  Created by Joe Pak on 3/1/17.
//  Copyright © 2017 Joe Pak. All rights reserved.
//

#include <stdio.h>

#define CHAR_TO_INT(x)  ((x) - 0x61)    //e.g. converts 'a' to 0, 'b' to 1 etc.

void countCharAppearances(char *string, int charCountsInString[])
{
    //read each char & increment matching elem in count array
    int charPosition = 0;
    int charIndexInCountArray = 0;
    while (string[charPosition] != '\0')
    {
        charIndexInCountArray = CHAR_TO_INT(string[charPosition]);
        charCountsInString[charIndexInCountArray]++;
        charPosition++;
    }
}

int verifyStringIsPalindrome(int charCountsInString[])
{
    /*count number of odd elems in array
     */
    int i = 0;
    int oddElemsInArray = 0;
    for (i = 0; i < 26; i++)
    {
        if ((charCountsInString[i] & 1) == 1)
        {   //elem is odd
            oddElemsInArray++;
        }
    }
    
    /*if odd elem count is more than 1, not a palindrome
     */
    int isPalindrome;
    if (oddElemsInArray == 1 || oddElemsInArray == 0)
    {
        isPalindrome = 1;   //true
    }
    else
    {
        isPalindrome = 0;   //false
    }
    
    return isPalindrome;
}

int isPermutationOfPalindrome(char *string)
{
    printf("%s: ", string);
    
    /*count the times each char appears in string
     */
    int charCountsInString[26] = {0};
    countCharAppearances(string, charCountsInString);
    
    /*see if more than 1 chars appear an odd number of times
     */
    int isPalindrome = verifyStringIsPalindrome(charCountsInString);
    
    return isPalindrome;
}

void printPalindromeResults(int isPalindrome)
{
    if (isPalindrome == 1)
    {
        printf("palindrome\n");
    }
    else
    {
        printf("not\n");
    }
}

void test_isPerMutationOfPalindrome(void)
{
    printPalindromeResults(isPermutationOfPalindrome("hello"));
    printPalindromeResults(isPermutationOfPalindrome("cattca"));
    printPalindromeResults(isPermutationOfPalindrome("cattcahhh"));
    printPalindromeResults(isPermutationOfPalindrome("polices"));
    printPalindromeResults(isPermutationOfPalindrome("drenerd"));
    printPalindromeResults(isPermutationOfPalindrome("drennnnnnnerd"));
}

int main(int argc, const char * argv[])
{
    test_isPerMutationOfPalindrome();
    
    return 0;
}
