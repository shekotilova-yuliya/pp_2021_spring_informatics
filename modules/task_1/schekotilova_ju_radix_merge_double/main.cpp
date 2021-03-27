// Copyright 2021 Schekotilova Julia

#include <gtest/gtest.h>
#include "./radix_merge_double.h"

TEST(TEST_SEQ, SIZE_5) {
  int size = 5;
  double* arr = new double[size] { 1.65, 5.5582, 29.9, 9.155, 52.864 };
  bool result = false;
  radixSort(arr, size);
  result = checker(arr, size);
  ASSERT_EQ(true, result);
}

TEST(TEST_SEQ, SIZE_1000) {
  int size = 1000;
  double* arr = new double[size];
  for (int i = 0; i < size; i++) arr[i] = (size - i) * 0.001 + (i + size / 2);
  bool result = false;
  radixSort(arr, size);
  result = checker(arr, size);

  ASSERT_EQ(true, result);
}

TEST(TEST_SEQ, SORT_RANDOM) {
  int size = 5;
  double* arr = new double[size];
  bool result = false;
  arr = generateArray(arr, size);
  radixSort(arr, size);
  result = checker(arr, size);
  ASSERT_EQ(true, result);
}
TEST(TEST_SEQ, SORT_SIZE100) {
  int size = 100;
  double* arr = new double[size];
  for (int i = 0; i < size; i++) arr[i] = (size - i) * 0.01 + (i + size / 2);
  bool result = false;
  radixSort(arr, size);
  result = checker(arr, size);
  ASSERT_EQ(true, result);
}

TEST(TEST_SEQ, CORRECT_SORT) {
  int size = 6;
  double* result = new double[size] {1.23, 5.6, 43.44, 50.21, 68.8802, 100.2364};
  double* arr = new double[size] {43.44, 5.6, 50.21, 1.23, 100.2364, 68.8802};
  radixSort(arr, size);
  for (int i = 0; i < size; i++) {
    ASSERT_NEAR(result[i], arr[i], 0.01);
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
