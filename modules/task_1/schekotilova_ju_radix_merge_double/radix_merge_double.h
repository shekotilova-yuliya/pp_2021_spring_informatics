// Copyright 2021 Schekotilova Julia
#ifndef MODULES_TASK_1_SCHEKOTILOVA_JU_RADIX_MERGE_DOUBLE_RADIX_MERGE_DOUBLE_H_
#define MODULES_TASK_1_SCHEKOTILOVA_JU_RADIX_MERGE_DOUBLE_RADIX_MERGE_DOUBLE_H_

#include <time.h>
#include <random>
#include <array>

  int mergingArrays(double* arr, double* arr_, int size, int size_,
    double* result);
  void countingSort(double* in, double* out, int byteVal, int size);
  int checker(double* arr, int size);
  int unsgnRadixSort(double* arr, int size);
  int radixSort(double* arr, int size);
  int generateArray(double* arr, int size);

#endif  // MODULES_TASK_1_SCHEKOTILOVA_JU_RADIX_MERGE_DOUBLE_RADIX_MERGE_DOUBLE_H_
