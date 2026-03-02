// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

constexpr double PI = 3.14159265358979323846;
constexpr double EPS = 1e-9;

TEST(Circle, ConstructorWithZeroRadius) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(Circle, ConstructorWithRadiusOne) {
  Circle c(1.0);
  EXPECT_DOUBLE_EQ(1.0, c.getRadius());
  EXPECT_NEAR(2.0 * PI, c.getFerence(), EPS);
  EXPECT_NEAR(PI, c.getArea(), EPS);
}

TEST(Circle, ConstructorWithRadiusTen) {
  Circle c(10.0);
  EXPECT_DOUBLE_EQ(10.0, c.getRadius());
  EXPECT_NEAR(20.0 * PI, c.getFerence(), EPS);
  EXPECT_NEAR(100.0 * PI, c.getArea(), EPS);
}

TEST(Circle, SetRadiusUpdatesAllFields) {
  Circle c(1.0);
  c.setRadius(5.0);
  EXPECT_DOUBLE_EQ(5.0, c.getRadius());
  EXPECT_NEAR(10.0 * PI, c.getFerence(), EPS);
  EXPECT_NEAR(25.0 * PI, c.getArea(), EPS);
}

TEST(Circle, SetRadiusToZero) {
  Circle c(5.0);
  c.setRadius(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(Circle, SetFerenceUpdatesRadiusAndArea) {
  Circle c;
  c.setFerence(2.0 * PI);
  EXPECT_NEAR(1.0, c.getRadius(), EPS);
  EXPECT_NEAR(2.0 * PI, c.getFerence(), EPS);
  EXPECT_NEAR(PI, c.getArea(), EPS);
}

TEST(Circle, SetFerenceFromKnownCircumference) {
  Circle c;
  double ference = 100.0;
  c.setFerence(ference);
  EXPECT_NEAR(ference / (2.0 * PI), c.getRadius(), EPS);
  EXPECT_NEAR(ference, c.getFerence(), EPS);
  EXPECT_NEAR(PI * (ference / (2.0 * PI)) * (ference / (2.0 * PI)),
              c.getArea(), EPS);
}

TEST(Circle, SetAreaUpdatesRadiusAndFerence) {
  Circle c;
  c.setArea(PI);
  EXPECT_NEAR(1.0, c.getRadius(), EPS);
  EXPECT_NEAR(2.0 * PI, c.getFerence(), EPS);
  EXPECT_NEAR(PI, c.getArea(), EPS);
}

TEST(Circle, SetAreaFromKnownValue) {
  Circle c;
  double area = 78.53981633974483;
  c.setArea(area);
  EXPECT_NEAR(5.0, c.getRadius(), EPS);
  EXPECT_NEAR(10.0 * PI, c.getFerence(), EPS);
  EXPECT_NEAR(area, c.getArea(), EPS);
}

TEST(Circle, SetRadiusGetFerenceSetFerenceGetRadius) {
  Circle c(7.0);
  double ference = c.getFerence();
  Circle c2;
  c2.setFerence(ference);
  EXPECT_NEAR(7.0, c2.getRadius(), EPS);
}

TEST(Circle, SetAreaGetRadiusSetRadiusGetArea) {
  Circle c;
  c.setArea(50.0);
  double radius = c.getRadius();
  Circle c2(radius);
  EXPECT_NEAR(50.0, c2.getArea(), EPS);
}

TEST(Circle, SmallRadius) {
  Circle c(0.001);
  EXPECT_NEAR(0.002 * PI, c.getFerence(), EPS * 0.001);
  EXPECT_NEAR(PI * 1e-6, c.getArea(), EPS * 1e-6);
}

TEST(Circle, LargeRadius) {
  Circle c(1000000.0);
  EXPECT_NEAR(2000000.0 * PI, c.getFerence(), EPS * 1000000);
  EXPECT_NEAR(PI * 1e12, c.getArea(), EPS * 1e12);
}

TEST(EarthAndRope, GapIsPositive) {
  double gap = earthAndRopeGap();
  EXPECT_GT(gap, 0.0);
}

TEST(EarthAndRope, GapEqualsOneOverTwoPi) {
  double gap = earthAndRopeGap();
  EXPECT_NEAR(1.0 / (2.0 * PI), gap, EPS);
}

TEST(EarthAndRope, GapIsApproximately16cm) {
  double gap = earthAndRopeGap();
  EXPECT_GT(gap, 0.15);
  EXPECT_LT(gap, 0.17);
}

TEST(Pool, ConcreteCostIsPositive) {
  PoolCostResult result = poolCost();
  EXPECT_GT(result.concreteCost, 0.0);
}

TEST(Pool, FenceCostIsPositive) {
  PoolCostResult result = poolCost();
  EXPECT_GT(result.fenceCost, 0.0);
}

TEST(Pool, TotalEqualsConcretePlusFence) {
  PoolCostResult result = poolCost();
  EXPECT_NEAR(result.concreteCost + result.fenceCost, result.totalCost, EPS);
}

TEST(Pool, ConcreteCostCorrect) {
  PoolCostResult result = poolCost();
  EXPECT_NEAR(7000.0 * PI, result.concreteCost, 0.01);
}

TEST(Pool, FenceCostCorrect) {
  PoolCostResult result = poolCost();
  EXPECT_NEAR(16000.0 * PI, result.fenceCost, 0.01);
}

TEST(Pool, TotalCostCorrect) {
  PoolCostResult result = poolCost();
  double expected = 7000.0 * PI + 16000.0 * PI;
  EXPECT_NEAR(expected, result.totalCost, 0.01);
}

TEST(Circle, ConstructorWithRadiusTwo) {
  Circle c(2.0);
  EXPECT_DOUBLE_EQ(2.0, c.getRadius());
  EXPECT_NEAR(4.0 * PI, c.getFerence(), EPS);
  EXPECT_NEAR(4.0 * PI, c.getArea(), EPS);
}

TEST(Circle, ConstructorWithRadiusHalf) {
  Circle c(0.5);
  EXPECT_DOUBLE_EQ(0.5, c.getRadius());
  EXPECT_NEAR(PI, c.getFerence(), EPS);
  EXPECT_NEAR(0.25 * PI, c.getArea(), EPS);
}

TEST(Circle, ConstructorDefault) {
  Circle c;
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(Circle, SetRadiusMultipleTimes) {
  Circle c(1.0);
  c.setRadius(2.0);
  c.setRadius(3.0);
  EXPECT_DOUBLE_EQ(3.0, c.getRadius());
  EXPECT_NEAR(6.0 * PI, c.getFerence(), EPS);
  EXPECT_NEAR(9.0 * PI, c.getArea(), EPS);
}

TEST(Circle, SetFerenceZero) {
  Circle c(5.0);
  c.setFerence(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(Circle, SetAreaZero) {
  Circle c(5.0);
  c.setArea(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(Circle, SetFerenceUpdatesRadius) {
  Circle c;
  c.setFerence(6.283185307179586);
  EXPECT_NEAR(1.0, c.getRadius(), 1e-6);
}

TEST(Circle, SetAreaUpdatesFerence) {
  Circle c;
  c.setArea(4.0 * PI);
  EXPECT_NEAR(4.0 * PI, c.getFerence(), EPS);
  EXPECT_NEAR(2.0, c.getRadius(), EPS);
}

TEST(Circle, RadiusOneHundred) {
  Circle c(100.0);
  EXPECT_NEAR(200.0 * PI, c.getFerence(), EPS * 100);
  EXPECT_NEAR(10000.0 * PI, c.getArea(), EPS * 10000);
}

TEST(Circle, RoundTripSetRadiusGetFerenceSetFerence) {
  Circle c(13.0);
  double f = c.getFerence();
  Circle c2;
  c2.setFerence(f);
  EXPECT_NEAR(13.0, c2.getRadius(), EPS);
}

TEST(Circle, RoundTripSetAreaGetRadius) {
  Circle c;
  c.setArea(314.1592653589793);
  double r = c.getRadius();
  Circle c2(r);
  EXPECT_NEAR(314.1592653589793, c2.getArea(), EPS);
}

TEST(Circle, GetRadiusAfterSetArea) {
  Circle c;
  c.setArea(100.0);
  double r = c.getRadius();
  EXPECT_NEAR(std::sqrt(100.0 / PI), r, EPS);
}

TEST(Circle, GetFerenceAfterSetRadius) {
  Circle c(2.5);
  EXPECT_NEAR(5.0 * PI, c.getFerence(), EPS);
}

TEST(Circle, GetAreaAfterSetFerence) {
  Circle c;
  c.setFerence(20.0 * PI);
  EXPECT_NEAR(100.0 * PI, c.getArea(), EPS);
}

TEST(EarthAndRope, GapLessThanOne) {
  double gap = earthAndRopeGap();
  EXPECT_LT(gap, 1.0);
}

TEST(EarthAndRope, GapGreaterThanZeroPointOne) {
  double gap = earthAndRopeGap();
  EXPECT_GT(gap, 0.1);
}

TEST(Pool, TotalGreaterThanConcrete) {
  PoolCostResult result = poolCost();
  EXPECT_GT(result.totalCost, result.concreteCost);
}

TEST(Pool, TotalGreaterThanFence) {
  PoolCostResult result = poolCost();
  EXPECT_GT(result.totalCost, result.fenceCost);
}

TEST(Pool, ConcreteCostApproxTwentyTwoThousand) {
  PoolCostResult result = poolCost();
  EXPECT_GT(result.concreteCost, 21000.0);
  EXPECT_LT(result.concreteCost, 23000.0);
}

TEST(Pool, FenceCostApproxFiftyThousand) {
  PoolCostResult result = poolCost();
  EXPECT_GT(result.fenceCost, 49000.0);
  EXPECT_LT(result.fenceCost, 51000.0);
}
