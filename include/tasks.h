// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

double earthAndRopeGap();

struct PoolCostResult {
  double concreteCost;
  double fenceCost;
  double totalCost;
};
PoolCostResult poolCost();

#endif  // INCLUDE_TASKS_H_
