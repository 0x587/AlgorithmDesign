//
// Created by 587! on 2023/03/10.
//
#include <vector>

#ifndef ALGORITHM_DESIGN_SORTER_BASESORTER_H
#define ALGORITHM_DESIGN_SORTER_BASESORTER_H

template<class T>
class BaseSorter {
public:
    virtual void sort(std::vector<T> &data) = 0;
};


#endif //ALGORITHM_DESIGN_SORTER_BASESORTER_H
