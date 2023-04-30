#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
//1 Write a function that measures length of a null-terminated character string. Return a number of characters without the trailing '\0'.
size_t mystrlen(const char* src);
//2 Write a function that will copy one null-terminated string to another
void mystrcpy(char* dest, const char* src);
//3 Write a function that compares one null-terminated string with another. 
bool mystrcmp(const char* str1, const char* str2);
//4 Write a function that compares at most n first elements from one null-terminated string with 
//another. Remember that the strings might be shorter then n characters.
bool mystrncmp(const char* dest, const char* src, size_t n);
//5 Write a function that concatenate one null-terminated string to another.
char* mystrcat(char* dest, const char* src);
//6 Write a function that returns address of the first occurrence of a given character in a nullterminated string. 
//Return a NULL pointer if the character is not in the string.
char* mystrchr(const char* src, char c);
//7 Write a function which checks if a null-terminated character string is a palindrome, i.e. the 
//sequence of characters in the string read in reverse order give the same string.
//Return a nonzero value if the string is a palindrome, or 0 otherwise.
bool isPalindrome(const char* src);
//8 Write a function which removes a character from a null-terminated string at a given position.
void strrmidx(char* src, size_t i);
//9 Write a function which removes first occurrence of a character in a null-terminated string.
void strrmchr(char* src, char ch);
//10 Modify the previous function which removes every occurrence of a given character.
void strrmchr2(char* src, char ch);
//11 Write a function which removes every uppercase letter from a null-terminated string
void strrmupc(char* src);
//12 Write a function which removes from a null - terminated string a substring indicated by
//starting position and length.
void strrmsub(char* src, size_t start, size_t length);





int main(void)
{
	char str[] = "ABBA";

	printf("%s\n", str);
	strrmupc(str);
	printf("%s\n", str);
	return 0;
}

size_t mystrlen(const char* src)
{
	size_t i = 0;
	while (src[i] != '\0') {
		++i;
	}
	return i;
	
}

void mystrcpy(char* dest, const char* src)
{
	size_t src_size = mystrlen(src);
	for (size_t i = 0; i <= src_size; ++i) {
		dest[i] = src[i];
	}
}

bool mystrcmp(const char* str1, const char* str2)
{
	size_t str1_len = mystrlen(str1);
	size_t str2_len = mystrlen(str2);
	
	if (str1_len != str2_len)
		return false;

	for (size_t i = 0; i < str1_len; ++i) {
		if (str1[i] != str2[i])
			return false;
	}

	return true;
}

bool mystrncmp(const char* str1, const char* str2, size_t n)
{

	if (n > mystrlen(str1) || n > mystrlen(str2))
		return false;

	for (size_t i = 0; i < n; ++i) {
		if (str1[i] != str2[i])
			return false;
	}

	return true;
}

char* mystrcat(char* dest, const char* src)
{
	size_t n_dest = mystrlen(dest);
	for (size_t n_src = 0; src[n_src] != '\0'; ++n_src) {
		dest[n_dest] = src[n_src];
		++n_dest;
	}
	dest[n_dest] = '\0';
	return dest;
}

char* mystrchr(const char* src, char c)
{
	while (*src) {
		if (*src == c)
			return (char*)src;
		src++;
	}
	
	return NULL;
}

bool isPalindrome(const char* src)
{
	size_t len = mystrlen(src);
	for (size_t i = 0; i < len / 2; i++) 
	{
		if (src[i] != src[len - 1 - i])
			return false;
	}

	return true;
}

void strrmidx(char* src, size_t i)
{
	if (i >= mystrlen(src)) {
		printf("Incorrect index");
		return;
	}
	for (i; src[i] != '\0'; i++)
	{
		src[i] = src[i + 1];
	}
}

void strrmchr(char* src, char ch)
{
	for (size_t i = 0; src[i] != '\0'; i++)
	{
		if (src[i] == ch) {
			strrmidx(src, i);
			return;
		}
	}
}

void strrmchr2(char* src, char ch)
{
	size_t len = mystrlen(src);
	for (size_t i = 0; i < len; ++i) {
		strrmchr(src, ch);
	}
}

void strrmupc(char* src)
{
	for (size_t i = 0; src[i] != '\0'; i++) {
		if (src[i] >= 'A' && src[i] <= 'Z') {
			strrmidx(src, i);
			i--;
		}
	}
}

void strrmsub(char* src, size_t start, size_t length)
{
	if ((start + length) >= mystrlen(src)) {
		printf("error: index out of range\n");
		return;
	}

	for (size_t i = start; i <= (length + start); i++) {
		strrmidx(src, start);
	}
}
