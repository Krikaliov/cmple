#ifndef MATRIX_H
#define MATRIX_H 1

#ifdef __cplusplus
extern "C" {
#endif

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
