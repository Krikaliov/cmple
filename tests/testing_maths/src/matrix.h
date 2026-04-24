#ifndef MATRIX_H
#define MATRIX_H 1

#ifdef __cplusplus
extern "C" {
#endif

extern unsigned char matrix_errno;

/**
 * Pop last error code for matrix calculus.
 * @return the last error code or 0 if no error were encountered.
 * @note This function set the last error code to 0 after returning it
 * so two consecutive calls of `pop_matrix_last_errno` would not return
 * the same value!
 */
unsigned char pop_matrix_last_errno();

/**
 * 2x2 float matrix struct such that
```
M = |a b|
     |c d|
```
 */
struct matrix
{
  float a, b, c, d;
};

/**
 * Compute A+B and return the result
 * @param a matrix A
 * @param b matrix B
 * @return matrix A+B
 */
struct matrix matrix_add(const struct matrix a, const struct matrix b);

/**
 * Compute A*B and return the result
 * @param a matrix A
 * @param b matrix B
 * @return matrix A*B
 */
struct matrix matrix_mul(const struct matrix a, const struct matrix b);

/**
 * Trace of a matrix
 * @param mat Given matrix
 * @return tr(mat) = mat.a + mat.d
 */
float matrix_trace(const struct matrix mat);

/**
 * Determinant of a matrix
 * @param mat Given matrix
 * @return |mat| = mat.a * mat.d - mat.b * mat.c
 */
float matrix_det(const struct matrix mat);

/**
 * Inverse of a matrix
 * @param mat Given matrix
 * @return mat^(-1)
 * @note Raise an error if |mat| = 0
 */
struct matrix matrix_inverse(const struct matrix mat);

/**
 * Identity matrix I_2
 * @return I_2
 */
struct matrix matrix_id();

/**
 * Zero matrix (0)
 * @return (0)
 */
struct matrix matrix_zero();

#ifdef __cplusplus
}
#endif

#endif // MATRIX_H
