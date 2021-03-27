// Copyright 2021 Schekotilova Julia
#include "../../../modules/task_1/schekotilova_ju_radix_merge_double/radix_merge_double.h"

void sorting(double* in, double* out, int size, int val) {
  unsigned char* arr = (unsigned char*)in;
  int counter[256];
  int res = 0;
  for (int i = 0; i < 256; i++) counter[i] = 0;
  for (int i = 0; i < size; i++) counter[arr[8 * i + val]]++;
  for (int i = 0; i < 256; i++) {
    int tmp = counter[i];
    counter[i] = res;
    res += tmp;
  }
  for (int i = 0; i < size; i++) {
    int idx = 8 * i + val;
    out[counter[arr[idx]]] = in[i];
    counter[arr[idx]]++;
  }
}

void last_sorting(double* in, double* out, int size, int val) {
  unsigned char* arr = (unsigned char*)in;
  int counter[256];
  int sum = 0;
  for (int i = 0; i < 256; i++) counter[i] = 0;
  for (int i = 255; i > 127; i--) {
    counter[i] += sum;
    sum = counter[i];
  }
  for (int i = 0; i < 128; i++) {
    int tmp = counter[i];
    counter[i] = sum;
    sum += tmp;
  }
  for (int i = 0; i < size; i++) {
    int idx = 8 * i + val;
    if (arr[idx] < 128) {
      out[counter[arr[idx]]] = in[i];
      counter[arr[idx]]++;
    } else {
      counter[arr[idx]]--;
      out[counter[arr[idx]]] = in[i];
    }
  }
}

void ordered_merge(double* source, double* source_, int size, int size_, double* res) {
  int i = 0;
  int j = 0;
  int a = 0;
  while ((i < size) && (j < size_)) {
    if (source[i] < source_[j]) {
      res[a] = source[i];
      i++;
    } else {
      res[a] = source_[j];
      j++;
    }
    a++;
  }

  while (i < size) {
    res[a] = source[i];
    i++;
    a++;
  }

  while (j < size_) {
    res[a] = source_[j];
    j++;
    a++;
  }
}

void radixSort(double* source, int size) {
  double* temp = nullptr;
  double* dest = new double[size];
  for (int i = 0; i < 8; i++) {
    sorting(source, dest, size, i);
    temp = source;
    source = dest;
    dest = temp;
  }
  last_sorting(source, dest, size, 7);
  delete[] dest;
}

double* generateArray(double* arr, int size) {
  std::mt19937 gen;
  gen.seed(static_cast<unsigned int>(time(0)));
  std::uniform_real_distribution<double> arr_(0.0, 100.0);
  for (int i = 0; i < size; i++) {
    arr[i] = arr_(gen);
  }
  return arr;
}

bool checker(double* arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    if (arr[i + 1] >= arr[i]) {
      i++;
    } else {
      return false;
    }
    return true;
  }
}
