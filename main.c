#include "gin.h"

INSTANTIATE(int, int, ARRAY_TEMPLATE)
INSTANTIATE(char, char, OPTIONAL_TEMPLATE)
INSTANTIATE(char, char *, chars, HASHMAP_TEMPLATE)

int main(void) {
    int_array array = int_array_init();
    char_optional optional = {};
    chars_hashmap hashmap = chars_hashmap_init();

    String s = string_make(format("Hello, %s", "world!"));
    printf("%.*s\n", string_fmt(s));

    chars_hashmap_put(&hashmap, "foo", "bar");
    char *bar;
    chars_hashmap_get(&hashmap, "foo", &bar);
    printf("%s\n", bar);

    char *baz = xstrdup("baz\n");
    printf(baz);
    free(baz);
}