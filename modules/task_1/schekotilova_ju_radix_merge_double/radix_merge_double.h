// Copyright 2021 Schekotilova Julia
#ifndef MODULES_TASK_1_SCHEKOTILOVA_JU_RADIX_MERGE_DOUBLE_RADIX_MERGE_DOUBLE_H_
#define MODULES_TASK_1_SCHEKOTILOVA_JU_RADIX_MERGE_DOUBLE_RADIX_MERGE_DOUBLE_H_
#include <time.h>
#include <random>

  bool checker(double* source, int size);
  void sorting(double* source, double* dest, int size, int offset);
  void lastSorting(double* source, double* dest, int size, int offset);
  void ordered_merge(double* source1, int size1, double* source2, int size2,
    double* dest);
  void radixSort(double* source, int size);
  double* generateArray(double* arr, int size);


#endif  // MODULES_TASK_1_SCHEKOTILOVA_JU_RADIX_MERGE_DOUBLE_RADIX_MERGE_DOUBLE_H_
