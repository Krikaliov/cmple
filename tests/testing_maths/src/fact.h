#ifndef FACT_H
#define FACT_H 1

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Compute the factorial number of any positive integer
 * in the recursive way.
 * @param n positive integer
 * @return n! or -1 if the given integer n is negative
 */
int fact_recursive(const int n);

/**
 * Compute the factorial number of any positive integer
 * in the imperative way.
 * @param n positive integer
 * @return n! or -1 if the given integer n is negative
 */
int fact_imperative(const int n);

#ifdef __cplusplus
}
#endif

#endif // FACT_H
