//
// Created by 587! on 2023/03/10.
//
#include <vector>
#include <cstdint>
#include <random>

#ifndef ALGORITHM_DESIGN_SORTER_DATAFAKER_H
#define ALGORITHM_DESIGN_SORTER_DATAFAKER_H
enum DataDistribution {
    Sorted,
    Random,
    Uniform,
    Geometry,
    Normal,
    ChiSquared
};

template<typename T>
class DataFaker {
public:
    std::vector<T> makeList(size_t size, DataDistribution distribution) {
        std::vector<T> result;
        result.assign(size, 0);
        if (distribution == Sorted) {
            int32_t count = 0;
            for (T &i: result)
                i = (T) count++;
            return result;
        }
        std::random_device device;
        std::mt19937 gen(device());
        std::normal_distribution<> normalDistribution(0, INT32_MAX / 4);
        std::uniform_int_distribution<> uniformIntDistribution(INT32_MIN, INT32_MAX);
        std::geometric_distribution<> geometricDistribution(2);
        std::chi_squared_distribution<> chiSquaredDistribution(4);
        for (int &i: result) {
            switch (distribution) {
                case Sorted:
                case Random:
                    i = (T) gen();
                    break;
                case Uniform:
                    i = (T) uniformIntDistribution(gen);
                    break;
                case Geometry:
                    i = (T) geometricDistribution(gen);
                    break;
                case Normal:
                    i = (T) normalDistribution(gen);
                    break;
                case ChiSquared:
                    i = (T) chiSquaredDistribution(gen);
                    break;
            }
        }
        return result;
    }
};


#endif //ALGORITHM_DESIGN_SORTER_DATAFAKER_H
