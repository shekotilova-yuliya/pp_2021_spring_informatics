// Copyright 2021 Schekotilova Julia

#include "../../../modules/task_1/schekotilova_ju_radix_merge_double/radix_merge_double.h"

int mergingArrays(double* arr, double* arr_, int size, int size_, double* result) {
  int a = 0;
  int sz = size - 1;
  if (size < 0 || size_ < 0 || result == nullptr || arr_ == nullptr || arr == nullptr) {
    return - 1;
  } else {
    for (int i = sz; i >= 0; i--) {
    result[a] = arr[i];
    a++;
    }
    for (int j = 0; j < size_; j++) {
      result[a] = arr_[j];
      a++;
    }
  return 0;
  }
}

void countingSort(double* in, double* out, int byteVal, int size) {
  unsigned char* arr = (unsigned char*)in;
  int count[256];
  int val, i;
  memset(count, 0, sizeof(int) * 256);
  for (int j = 0; j < size; j++)
      count[arr[8 * j + byteVal]]++;
  for (i = 0; i < 256; i++) {
    if (count[i] != 0) {
      break;
    }
  }
  val = count[i];
  count[i] = 0;
  i++;
  for (; i < 256; i++) {
    int tmp = count[i];
    count[i] = val;
    val += tmp;
  }

  for (int j = 0; j < size; j++) {
    out[count[arr[8 * j + byteVal]]] = in[j];
    count[arr[8 * j + byteVal]]++;
  }
}

int unsgnRadixSort(double* arr, int size) {
  double* outArr = reinterpret_cast<double*>(malloc(sizeof(double) * size));
  int num = 4;
  if (size < 1) {
    return 0;
  } else if (size < 0 || arr == nullptr || outArr == nullptr) {
    return -1;
  } else {
    for (int i = 0; i < num; i++) {
      countingSort(arr, outArr, 2 * i, size);
      countingSort(outArr, arr, 2 * i + 1, size);
    }
    if (outArr) {
      free(outArr);
      outArr = nullptr;
    }
    return 0;
  }
}


int radixSort(double* arr, int size) {
  double* pArr = nullptr, * nArr = nullptr;
  int pSize = 0, nSize = 0;
  int res = 0;
  pArr = reinterpret_cast<double*>(malloc(sizeof(double) * size));
  nArr = reinterpret_cast<double*>(malloc(sizeof(double) * size));
  if ((size < 1) || (arr == nullptr)) {
    return -1;
  } else if ((pArr == nullptr) || (nArr == nullptr)) {
    return -1;
  } else {
    for (int i = 0; i < size; i++) {
      if (arr[i] >= 0) {
        pArr[pSize] = arr[i];
        pSize++;
      } else {
        nArr[nSize] = arr[i];
        nSize++;
      }
    }

    res = unsgnRadixSort(nArr, nSize);
    res = unsgnRadixSort(pArr, pSize);
    res = mergingArrays(nArr, pArr, nSize, pSize, arr);
    if (nArr) {
      free(nArr);
      nArr = nullptr;
    }
    if (pArr) {
      free(pArr);
      pArr = nullptr;
    }
    return res;
  }
}

int generateArray(double* arr, int size) {
  double b = 100.0;
  double a = 0.0;
  for (int i = 0; i < size; i++) {
    arr[i] = static_cast<double>(std::rand()) * (b - a + 1) / RAND_MAX + a;
  }
  return 0;
}

int checker(double* arr, int size) {
  int sz = size - 1;
  if (size < 1 || arr == nullptr) {
    return -1;
  } else {
    for (int i = 0; i < sz; i++) {
      if (arr[i] <= arr[i + 1]) {
        i++;
      } else {
        return -1;
      }
    }
    return 0;
  }
}
