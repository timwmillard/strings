
#ifndef STRINGS_H
#define STRINGS_H

#include <stdlib.h>
#include <stdbool.h>

struct _stringhdr{
	int len;
	char buf[];
};

typedef char *string;

string cstring(char *s);
string cstringl(char *s, size_t len);
void string_free(string s);

size_t string_len(string s);
string string_cat(string a, string b);
string cstring_cat(char *a, char *b);
string string_sprintf(string s, ...);
string cstring_sprintf(char *s, ...);

int string_clone(string a, string b);
int string_cmp(string a, string b);
bool string_contains(string s, string substr);
bool string_containsany(string s, string chars);
int string_count(string s, string substr);
bool string_equal(string s, string t);
bool string_equalfold(string s, string t);
string* string_fields(string s);
bool string_hasprefix(string s, string prefix);


bool string_hassuffix(string s, string suffix);
int string_index(string s, string substr);

int string_indexany(string s, string chars);
int stirng_indexchar(string s, char c);
string string_join(string elems[], string sep);
int string_lastindex(string s, string substr);
int string_lastindexany(string s, string chars);
int string_lastindexchar(string s, char c);
string string_repeat(string s, int count);
string string_replace(string s, string old, string new, int n);
string string_replaceall(string s, string old, string new);


string *string_split(string s, string sep);
string *string_splitafter(string s, string sep);
string *string_splitaftern(string s, string sep, int n);
string *string_splitn(string s, string sep, int n);

string string_tolower(string s);
string string_totitle(string s);
string string_toupper(string s);


string string_trim(string s, string cutset);
string string_trimleft(string s, string cutset);
string string_trimprefix(string s, string prefix);
string string_trimright(string s, string cutset);
string string_trimspace(string s);
string string_trimsuffix(string s, string suffix);


#endif
