#include <stan/diff/rev/scalar/round.hpp>
#include <test/diff/util.hpp>
#include <gtest/gtest.h>

TEST(DiffRevScalar,round) {
  AVAR a = 1.2;
  AVAR f = round(a);
  EXPECT_FLOAT_EQ(1.0, f.val());
  
  AVEC x = createAVEC(a);
  VEC grad_f;
  f.grad(x,grad_f);
  EXPECT_FLOAT_EQ(0.0, grad_f[0]);
}

TEST(DiffRevScalar,round_2) {
  AVAR a = -1.2;
  AVAR f = round(a);
  EXPECT_FLOAT_EQ(-1.0, f.val());
  
  AVEC x = createAVEC(a);
  VEC grad_f;
  f.grad(x,grad_f);
  EXPECT_FLOAT_EQ(0.0, grad_f[0]);
}

TEST(DiffRevScalar,round_3) {
  AVAR a = 1.7;
  AVAR f = round(a);
  EXPECT_FLOAT_EQ(2.0, f.val());
  
  AVEC x = createAVEC(a);
  VEC grad_f;
  f.grad(x,grad_f);
  EXPECT_FLOAT_EQ(0.0, grad_f[0]);
}


TEST(DiffRevScalar,round_4) {
  AVAR a = -1.7;
  AVAR f = round(a);
  EXPECT_FLOAT_EQ(-2.0, f.val());
  
  AVEC x = createAVEC(a);
  VEC grad_f;
  f.grad(x,grad_f);
  EXPECT_FLOAT_EQ(0.0, grad_f[0]);
}