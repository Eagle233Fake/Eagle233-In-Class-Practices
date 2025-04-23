long decode2(long x, long y, long z) {
    y = y - z;
    x = x * y;
    y = y << 63;
    y = y >> 63;
    y = y ^ x;
    return y;
}