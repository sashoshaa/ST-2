// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

double earthAndRopeGap() {
  const double EARTH_RADIUS_KM = 6378.1;
  const double EARTH_RADIUS_M = EARTH_RADIUS_KM * 1000.0;
  const double ROPE_ADDITION_M = 1.0;

  Circle earth(EARTH_RADIUS_M);
  double originalFerence = earth.getFerence();
  double newFerence = originalFerence + ROPE_ADDITION_M;

  Circle ropeCircle;
  ropeCircle.setFerence(newFerence);

  double newRadius = ropeCircle.getRadius();
  return newRadius - EARTH_RADIUS_M;
}

PoolCostResult poolCost() {
  const double POOL_RADIUS = 3.0;
  const double PATH_WIDTH = 1.0;
  const double CONCRETE_PRICE_PER_SQM = 1000.0;
  const double FENCE_PRICE_PER_M = 2000.0;

  Circle pool(POOL_RADIUS);
  Circle outer(POOL_RADIUS + PATH_WIDTH);

  double pathArea = outer.getArea() - pool.getArea();
  double fenceLength = outer.getFerence();

  PoolCostResult result;
  result.concreteCost = pathArea * CONCRETE_PRICE_PER_SQM;
  result.fenceCost = fenceLength * FENCE_PRICE_PER_M;
  result.totalCost = result.concreteCost + result.fenceCost;

  return result;
}
