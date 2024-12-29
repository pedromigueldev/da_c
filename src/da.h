#ifndef DA_H
#define DA_H

#include <stdio.h>
#include <stdlib.h>

#define TOKEN_PASTE(x, y, z) da__##z##x##y;  da__##z##x##y
#define DO(x,y,z) TOKEN_PASTE(x,y,z)
#define UNIQUE(name) DO(name, __LINE__, __COUNTER__)

#define F_TOKEN_PASTE(x, y, z) da__##z##x##y
#define FDO(x,y) F_TOKEN_PASTE(x,y,y)
#define F_UNIQUE(name) FDO(name, __LINE__)

#define da_create(TYPE) \
    typedef struct {\
        TYPE * items;\
        size_t count;\
        size_t capacity;\
    } UNIQUE(TYPE)

#define da_append_gc(array, x) \
    do {\
        if (array->count >= array->capacity) {\
            if (array->capacity == 0) {\
                array->capacity = 256;\
            }\
            else array->capacity *= 2;\
            array->items = realloc(array->items, array->capacity*sizeof(*array->items));\
        }\
    } while(0);\
    array->items[array->count++] = x \

#define da_verify(array) \
    do {\
        if (array.count >= array.capacity) {\
            if (array.capacity == 0) {\
                array.capacity = 256;\
                 array.items = realloc(array.items, array.capacity*sizeof(*array.items));\
                da_append_gc(da_array, array.items);\
                break;\
            }\
            else array.capacity *= 2;\
            array.items = realloc(array.items, array.capacity*sizeof(*array.items));\
        }\
    } while(0)

#define da_set(array, at) \
    if (at+1 > array.count) array.count = at+1;\
    da_verify(array);\
    array.items[at]

#define da_append(array, x) \
    da_verify(array);\
    array.items[array.count++] = x \

#define DC(x) \
typedef struct {\
    void** items;\
    size_t count;\
    size_t capacity;\
} F_UNIQUE(aa);\
x F_UNIQUE(da_function)(F_UNIQUE(aa)* da_array);\
bool F_UNIQUE(da_function_free)(F_UNIQUE(aa)* da_array) { \
    do {\
        if (da_array->count > 0) {\
            for(size_t i = 0; i < da_array->count; i++ ) {\
                free(da_array->items[i]);\
            };\
            free(da_array->items);\
        }\
    } while (0);\
    return true;}\

#define DA(x) \
{\
    F_UNIQUE(aa) *da_array = &(F_UNIQUE(aa)) {0};\
    int ret = F_UNIQUE(da_function)(da_array);\
    F_UNIQUE(da_function_free)(da_array);\
    return ret;\
}\
x F_UNIQUE(da_function)(F_UNIQUE(aa)* da_array)

#define dynamic(type, name) DC(type) type name() DA(type)

#endif
