//
// Created by 587! on 2023/03/10.
//

#ifndef ALGORITHM_DESIGN_SORTER_MERGESORTER_H
#define ALGORITHM_DESIGN_SORTER_MERGESORTER_H


#include <limits>
#include "BaseSorter.h"

template<class T>
class MergeSorter : public BaseSorter<T> {
private:
    void merge(std::vector<T> &data, std::size_t front, std::size_t mid, std::size_t end) {
        std::vector<T> left(data.begin() + front, data.begin() + mid + 1);
        std::vector<T> right(data.begin() + mid + 1, data.begin() + end + 1);

        std::size_t lIndex = 0, rIndex = 0;
        left.insert(left.end(), std::numeric_limits<T>::max());
        right.insert(right.end(), std::numeric_limits<T>::max());
        for (std::size_t i = front; i <= end; i++) {
            if (left[lIndex] < right[rIndex])
                data[i] = left[lIndex++];
            else
                data[i] = right[rIndex++];
        }
    }

    void mergeSort(std::vector<T> &data, std::size_t front, std::size_t end) {
        if (front >= end)
            return;
        std::size_t mid = (front + end) / 2;
        mergeSort(data, front, mid);
        mergeSort(data, mid + 1, end);
        merge(data, front, mid, end);
    }

public:
    void sort(std::vector<T> &data) {
        mergeSort(data, 0, data.size());
    }
};


#endif //ALGORITHM_DESIGN_SORTER_MERGESORTER_H
