# Dynamic Arrays and Macros in C

Series of macros to define a function that outo frees dynamic arrays made with da_* functions;

## Running on linux

```bash
git clone https://github.com/pedromigueldev/da_c
cd da_c
make && make run
```

## usage

```c
dinamic(float, new_dynamic_block) {
    da_create(float) floating = {0};
    da_set(floating, 0) = 100203.f;

    return floating.items[0];
} // auto free DA

dinamic(int, main) { // creates int main()
    da_create(float) floating = {0};
    da_append(floating, new_dynamic_block());

    return 0;
} // auto free DA
```
