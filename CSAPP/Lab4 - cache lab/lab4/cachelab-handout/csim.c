#include "cachelab.h"
#include <unistd.h>

typedef struct {
    int valid;
    unsigned long long tag;
    int lru;
} Line;

typedef struct {
    Line *lines;
} Set;

typedef struct {
    Set *sets;
    int s, E, b;
} Cache;

Cache initCache(int s, int E) {
    int S = 1 << s;
    Cache cache;

    cache.s = s;
    cache.E = E;
    cache.sets = (Set *)malloc(S * sizeof(Set));

    for (int i = 0; i < S; i++) {
        cache.sets[i].lines = (Line *)malloc(E * sizeof(Line));
        for (int j = 0; j < E; j++) {
            cache.sets[i].lines[j].valid = 0;
            cache.sets[i].lines[j].tag = 0;
            cache.sets[i].lines[j].lru = 0;
        }
    }

    return cache;
}

Cache cache = initCache(s, E);

void freeCache(void) {
    int S = 1 << cache.s;
    for (int i = 0; i < S; i++) {
        free(cache.sets[i].lines);
    }
    free(cache.sets);
}

void loadFile(char *tracefile) {
    FILE *fp = fopen(tracefile, "r");
    char operation;
    unsigned long long address;
    int size;

    // L 10,4 
    while (fscanf(fp, " %c %llx,%d", &operation, &address, &size) == 3) {
        if (operation == 'L' || operation == 'S') {
            access(address);
        } else if (operation == 'M') {
            access(address);
            access(address);
        }
        updateLRU();
    }

    fclose(fp);
}

void access(unsigned long long address) {
    int s = cache.s;
    int b = cache.b;
    unsigned long long tag = address >> (b + s);
    unsigned long long mask = -1;
    
}

void updateLRU(void) {
    for (int i = 0; i < (1 << cache.s); i++) {
        for (int j = 0; j < cache.E; j++) {
            if (cache.sets[i].lines[j].valid) {
                cache.sets[i].lines[j].lru++;
            }
        }
    }
}

void access()

int main(int argc, char *argv[]) {
    int s = 0, E = 0, b = 0;
    char *tracefile = NULL;
    char op;

    // ./csim-ref -s 4 -E 1 -b 4 -t traces/yi.trace
    while ((op = getopt(argc, argv, "s:E:b:t:")) != -1) {
        switch (op) {
            case 's':
                s = atoi(optarg);
                break;
            case 'E':
                E = atoi(optarg);
                break;
            case 'b':
                b = atoi(optarg);
                break;
            case 't':
                strcpy(tracefile, optarg);
                break;
        }
    }

    Cache cache = initCache(s, E);

    loadFile(tracefile);
    
    freeCache();

    printSummary(hit_count, miss_count, eviction_count);
    
    return 0;
}
