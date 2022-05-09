
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "testing.h"

#include "../strings.h"

void Test_string_len() {
    string str;

    str = cstring("test");
    assert(string_len(str) == 4);

    str = cstring("");
    assert(string_len(str) == 0);
}

void Test_string_equal() {
    assert(string_equal("abc", "abc"));
    assert(!string_equal("abc", "abcd"));

    string a = cstring("abc");
    string b = cstring("abc");
    string c = cstring("abcd");
    assert(string_equal(a, b));
    assert(!string_equal(a, c));
}

void Test_string_tolower() {
    typedef struct {
        char *str;
        char *want;
    } test;

    test tests[] = {
        {"ABCD", "abcd"},
        {"xyZ Abc$", "xyz abc$"},
        {"", ""},
    };
    for (int i=0; i<sizeof(tests)/sizeof(test); i++) {
        test t = tests[i];
        string got = string_tolower(cstring(t.str));
        assert(string_equal(got, cstring(t.want)));
    }

}

int main()
{
    Test_string_len();
    Test_string_equal();
    Test_string_tolower();

    passed();

    return 0;
}
