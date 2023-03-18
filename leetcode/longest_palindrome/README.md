# Longest Palindrome
From [this leetcode problem](https://leetcode.com/problems/longest-palindromic-substring/)
## Summary
* Dynamic programming
* Palindrome's 2nd to length-1 substring must also be a palindrome
### Base case
* 1-length strings are always palindromes
* 2-length strings are palindromes if both characters are the same
### Recursion
* A length > 3 string is a palindrome if its first and last characters are the same, and its "inner" substring (1 to length-1) is also a palindrome
* Don't care about multiple solutions, just any solution that has the max length
* Keep track of the most recent palindromic substring, since we iterate by length
* Can use dp table instead of recursion for efficiency
### Time Complexity
This iterates over the entire upper triangular matris with size $n$. So, there are $\dfrac{n^2}{2} \approx n^2$ accesses to the table. $O(n^2)$.