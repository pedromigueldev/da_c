#include <raylib.h>
#include <stddef.h>
#include "./da.h"

dynamic(float, new_dynamic_block) {
    da_create(float) floating = {0};
    da_set(floating, 0) = 100203.f;

    return floating.items[0];
} // auto free DA

dynamic(int, main) {
    da_create(float) floating = {0};
    da_append(floating, new_dynamic_block());

    return 0;
} // auto free DA
