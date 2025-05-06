# Lab4实验报告

## `csim.c`

首先先定义出缓存的基本结构：

```c
typedef struct {
    int valid;
    unsigned long long tag;
    int lru;
} line;

typedef struct {
    line *lines;
} set;

typedef struct {
    set *sets;
    int s, E, b;
} cache;
```

`line`就是每一个`set`中的一个组，根据所学知识，缓存存储着