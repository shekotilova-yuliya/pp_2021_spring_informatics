// Copyright 2021 Schekotilova Julia

#include <gtest/gtest.h>
#include "./radix_merge_double.h"

TEST(TEST_SEQ, WROGNG_SIZE) {
  int size = -10, res = 0;
  double* arr = nullptr;

  if (size > 0) {
    arr = reinterpret_cast<double*>(malloc(sizeof(double) * size));
  } else {
    res = -1;
  }
  res = generateArray(arr, size);
  res = radixSort(arr, size);
  res = checker(arr, size);
  if (arr) {
    free(arr);
    arr = nullptr;
  }
  ASSERT_EQ(res, -1);
}

TEST(TEST_SEQ, ZERO_SIZE) {
  int size = 0, res = 0;
  double* arr = nullptr;

  if (size > 0) {
    arr = reinterpret_cast<double*>(malloc(sizeof(double) * size));
  } else {
    res = -1;
  }
  res = generateArray(arr, size);
  res = radixSort(arr, size);
  res = checker(arr, size);
  if (arr) {
    free(arr);
    arr = nullptr;
  }
  ASSERT_EQ(res, -1);
}

TEST(TEST_SEQ, SIZE_10) {
  int size = 10, res = 0;
  double* arr = reinterpret_cast<double*>(malloc(sizeof(double) * size));
  res = generateArray(arr, size);
  res = radixSort(arr, size);
  res = checker(arr, size);
  free(arr);
  arr = nullptr;
  ASSERT_EQ(res, 0);
}

TEST(TEST_SEQ, SIZE_100) {
  int size = 100, res = 0;
  double* arr = nullptr;

  if (size > 0) {
    arr = reinterpret_cast<double*>(malloc(sizeof(double) * size));
  } else {
    res = -1;
  }
  res = generateArray(arr, size);
  res = radixSort(arr, size);
  res = checker(arr, size);
  if (arr) {
    free(arr);
    arr = nullptr;
  }
  ASSERT_EQ(res, 0);
}

TEST(TEST_SEQ, SIZE_1000) {
  int size = 1000, res = 0;
  double* arr = nullptr;

  if (size > 0) {
    arr = reinterpret_cast<double*>(malloc(sizeof(double) * size));
  } else {
    res = -1;
  }
  res = generateArray(arr, size);
  res = radixSort(arr, size);
  res = checker(arr, size);
  if (arr) {
    free(arr);
    arr = nullptr;
  }
  ASSERT_EQ(res, 0);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
