#include "matrix.h"

float matrix_trace(const struct matrix mat)
{
  return mat.a + mat.d;
}

float matrix_det(const struct matrix mat)
{
  return mat.a * mat.d - mat.b * mat.c;
}

struct matrix matrix_inverse(const struct matrix mat)
{
  const float det = matrix_det(mat);
  if (det > 0 || det < 0)
  {
    return (struct matrix) { mat.d/det , -mat.b/det
                            -mat.c/det ,  mat.a/det };
  } else return (struct matrix) { 1/0, 0, 0, 0 };
}

struct matrix matrix_id()
{
  return (struct matrix) {1, 0, 0, 1};
}

struct matrix matrix_zero()
{
  return (struct matrix) {0, 0, 0, 0};
}
