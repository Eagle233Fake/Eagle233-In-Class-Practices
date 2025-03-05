int bad_int_size_is_32() {
    int set_msb = 1 << 31;
    int beyond_msb = 1 << 31 << 1;
    return set_msb && !beyond_msb;
}

int bad_int_size_is_32() {
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = 1 << 15 << 15 << 2;
    return set_msb && !beyond_msb;
}