long loop(long x, int n) {
    long result = 0;
    long mask;
    
    // %cl 占 8bits，即 %ecx 的低8位
    for (mask = 1; mask != 0; mask = mask << (n & 0xFF)) {
        result |= (mask & x);
    }
    return result;
}