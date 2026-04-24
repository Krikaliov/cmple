#include <stdlib.h>

#include "matrix.h"

unsigned char matrix_errno = 0;

static inline void set_matrix_errno(unsigned char n) { matrix_errno = n; }

unsigned char pop_matrix_last_errno()
{
  const unsigned char last_errno = matrix_errno;
  matrix_errno = 0;
  return last_errno;
}

struct matrix matrix_add(const struct matrix a, const struct matrix b)
{
  return (struct matrix) { a.a + b.a , a.b + b.b ,
                           a.c + b.c , a.d + b.d };
}

struct matrix matrix_mul(const struct matrix a, const struct matrix b)
{
  const float c_a = a.a * b.a + a.b * b.c;
  const float c_b = a.a * b.b + a.b * b.d;
  const float c_c = a.c * b.a + a.d * b.c;
  const float c_d = a.c * b.b + a.d * b.d;
  return (struct matrix) { c_a, c_b, c_c, c_d };
}

float matrix_trace(const struct matrix mat)
{
  return mat.a + mat.d;
}

float matrix_det(const struct matrix mat)
{
  return (mat.a * mat.d) - (mat.b * mat.c);
}

struct matrix matrix_inverse(const struct matrix mat)
{
  const float det = matrix_det(mat);
  if (det > 0.f || det < 0.f)
  {
    return (struct matrix) { mat.d/det , -mat.b/det ,
                            -mat.c/det ,  mat.a/det };
  }
  else
  {
    set_matrix_errno(1);
    return (struct matrix) {0, 0, 0, 0};
  }
}

struct matrix matrix_id()
{
  return (struct matrix) {1, 0, 0, 1};
}

struct matrix matrix_zero()
{
  return (struct matrix) {0, 0, 0, 0};
}
