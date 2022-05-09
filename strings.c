
#include <string.h>
#include <ctype.h>

#include "strings.h"

string stringl(char *s, int len) {
	struct _stringhdr *str;
	str = malloc(sizeof(char) * len);
	str->len = len;
	for (int i = 0; i < len; i++)
		str->buf[i] = s[i];
	return str->buf;
}

string cstring(char *s) {
	size_t len = strlen(s);
	return stringl(s, len);
}

void string_free(string s) {
	struct _stringhdr *str = (void *) s - sizeof(struct _stringhdr);
	free(str);
}

size_t string_len(string s) {
	struct _stringhdr *str = (void *) s - sizeof(struct _stringhdr);
	return str->len;
}

int string_cmp(string a, string b) {
	return strcmp(a, b);
}

bool string_equal(string a, string b) {
	return strcmp(a, b) == 0;
}

bool string_equalfold(string s, string t) {
	s = string_tolower(s);
	t = string_tolower(t);
	return string_equal(s, t);
}

string string_tolower(string s) {
	string str = stringl("", string_len(s));
	char *p = s;
	int i = 0;
	while (*p) {
		char c = *p;
		if ('A' <= c && c <= 'Z')
			str[i] = c + 'a' - 'A';
		else
			str[i] = c;
		p++; i++;
	}
	return str;
}

string string_toupper(string s) {
	string str = stringl("", string_len(s));
	char *p = s;
	int i = 0;
	while (*p) {
		char c =  *p;
		if ('a' <= c && c <= 'z')
			str[i] = c - ('a' - 'A');
		else
			str[i] = c;
		p++; i++;
	}
	return str;
}