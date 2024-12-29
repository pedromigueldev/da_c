#include <raylib.h>
#include <stddef.h>
#include "./da.h"

dinamic(float, new_dynamic_block) {
    da_create(float) floating = {0};
    da_at(floating, 0) = 100203.f;

    return floating.items[0];
} // auto free DA

dinamic(int, main) {
    da_create(float) floating = {0};
    da_append(floating, new_dynamic_block());

    return 0;
} // auto free DA
