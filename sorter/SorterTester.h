//
// Created by 587! on 2023/03/10.
//
#include <iostream>
#include <time.h>

#include "BaseSorter.h"
#include "../faker/DataFaker.h"

#ifndef ALGORITHM_DESIGN_SORTER_SORTERTESTER_H
#define ALGORITHM_DESIGN_SORTER_SORTERTESTER_H


template<typename T>
class SortTester {
private:
    DataFaker<std::int32_t> faker = DataFaker<std::int32_t>();

    bool isSorted(std::vector<T> d) {
        for (int i = 1; i < d.size(); ++i)
            if (d[i] < d[i - 1])
                return false;
        return true;
    }

public:
    template<template<typename> class SorterType>
    typename std::enable_if_t<std::is_base_of_v<BaseSorter<T>, SorterType<T>>, void>
    test(size_t size = 10000, DataDistribution distribution = Random) {
        SorterType<T> sorter;
        auto testData = faker.makeList(size, distribution);
        auto start = clock();
        sorter.sort(testData);

        std::cout <<
                  size << " samples " <<
                  (isSorted(testData) ? "Pass" : "Fail") <<
                  " in " <<
                  clock() - start << " ms" <<
                  std::endl;
    }
};


#endif //ALGORITHM_DESIGN_SORTER_SORTERTESTER_H
