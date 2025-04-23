long switch_prob(long x, long n) {
    long result = x;
    switch (n) {
        case 60:
        case 62:
            result =  8 * result;
            break;
        case 63:
            result = result >> 3;
            break;
        case 64:
            result = result * 15;
            x = result;
        case 65:
            x = x * x;
        default:
            result = 75 + x;
    }
    return result;
}