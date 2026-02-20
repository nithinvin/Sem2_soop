/**
 * 374. Guess Number Higher or Lower
 *
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is higher than the picked number
 *                1 if num is lower than the picked number
 *                0 if num is equal to the picked number
 * int guess(int num);
 */

int guessNumber(int n) {
    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int res = guess(mid);
        if (res == 0)
            return mid;
        else if (res == -1)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}
