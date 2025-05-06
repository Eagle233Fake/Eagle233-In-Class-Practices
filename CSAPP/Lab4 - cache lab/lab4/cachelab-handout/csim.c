#include "cachelab.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <getopt.h>

#define fileNameLength 1000

uint64_t hits = 0;
uint64_t misses = 0;
uint64_t evictions = 0;

typedef struct { 
    int valid;
    uint64_t tag;
    uint64_t lru;
} Line;

typedef struct {
    Line *lines;
} Set;

typedef struct {
    Set *sets;
    uint64_t s;
    uint64_t E;
    uint64_t b;
} Cache;

Cache initCache(uint64_t s, uint64_t E, uint64_t b) {
    int S = 1 << s;

    Cache cache;
    cache.s = s;
    cache.E = E;
    cache.b = b;

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

void accessCache(Cache *cache, uint64_t address) {
    uint64_t s = cache->s;
    uint64_t b = cache->b;

    uint64_t tag = address >> (s + b);

    uint64_t mask = UINT64_MAX;
    mask >>= 64 - (s + b);
    uint64_t temp = address & mask;

    uint64_t index = temp >> b;

    int isEmpty = 0;
    for (int i = 0; i < cache->E; i++) {
        if (cache->sets[index].lines[i].valid && cache->sets[index].lines[i].tag == tag) {
            cache->sets[index].lines[i].lru = 0;
            hits++;
            return;
        }

        if (cache->sets[index].lines[i].valid == 0) {
            isEmpty = 1;
        }
    }

    if (isEmpty) {
        for (int i = 0; i < cache->E; i++) {
            if (cache->sets[index].lines[i].valid == 0) {
                cache->sets[index].lines[i].valid = 1;
                cache->sets[index].lines[i].tag = tag;
                misses++;
                return;
            }
        }
    } else {
        uint64_t MaxLRU = 0;
        for (int i = 0; i < cache->E; i++) {
            MaxLRU = cache->sets[index].lines[i].lru > MaxLRU ? cache->sets[index].lines[i].lru : MaxLRU;
        }

        for (int i = 0; i < cache->E; i++) {
            if (MaxLRU == cache->sets[index].lines[i].lru) {
                cache->sets[index].lines[i].lru = 0;
                cache->sets[index].lines[i].tag = tag;
                misses++;
                evictions++;
                return;
            }
        }
    }
}

void updateLRU(Cache *cache) {
    int S = 1 << cache->s;
    int E = cache->E;

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < E; j++) {
            if (cache->sets[i].lines[j].valid) {
                cache->sets[i].lines[j].lru++;
            }
        }
    }
}

void getFileInfo(char *tracefile, Cache *cache) {
    FILE *fp = fopen(tracefile, "r");
    if (fp == NULL) {
        return;
    }

    char opt;
    uint64_t address;
    int size;

    while (fscanf(fp, " %c %" SCNx64 ",%d", &opt, &address, &size) == 3) {
        switch (opt) {
            case 'L':
                accessCache(cache, address);
                break;
            case 'S':
                accessCache(cache, address);
                break;
            case 'M':
                accessCache(cache, address);
                accessCache(cache, address);
                break;
        }
        updateLRU(cache);
    }
}

void freeCache(Cache *cache) {
    int S = 1 << cache->s;
    for (int i = 0; i < S; i++) {
        free(cache->sets[i].lines);
    }
    free(cache->sets);
}

int main(int argc, char *argv[]) {
    uint64_t s;
    uint64_t E;
    uint64_t b;
    char tracefile[fileNameLength];

    char opt;
    while ((opt = getopt(argc, argv, "s:E:b:t:")) != -1) {
        switch (opt) {
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

    Cache cache;
    cache = initCache(s, E, b);

    getFileInfo(tracefile, &cache);

    freeCache(&cache);

    printSummary(hits, misses, evictions);
}
