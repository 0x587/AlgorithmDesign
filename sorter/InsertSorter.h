//
// Created by 587! on 2023/03/10.
//
#include "BaseSorter.h"

#ifndef ALGORITHM_DESIGN_SORTER_INSERTSORTER_H
#define ALGORITHM_DESIGN_SORTER_INSERTSORTER_H

template<class T>
class InsertSorter : public BaseSorter<T> {
public:
    void sort(std::vector<T> &data) {
        for (int i = 1; i < data.size(); ++i) {
            auto cur = data[i];
            int j = i - 1;
            while ((j >= 0) && cur < data[j]) {
                data[j + 1] = data[j];
                --j;
            }
            data[j + 1] = cur;
        }
    }
};


#endif //ALGORITHM_DESIGN_SORTER_INSERTSORTER_H
