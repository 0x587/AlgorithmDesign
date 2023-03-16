
#include "../faker/DataFaker.h"
#include "InsertSorter.h"
#include "SorterTester.h"
#include "MergeSorter.h"


int main() {
    SortTester<std::int32_t> sortTester;
    DataDistribution distribution = Normal;

    sortTester.test<MergeSorter>(10, distribution);
//    sortTester.test<MergeSorter>(1000, distribution);
//    sortTester.test<MergeSorter>(10000, distribution);
//    sortTester.test<MergeSorter>(100000, distribution);
//    sortTester.test<MergeSorter>(1000000, distribution);

//    sortTester.test<InsertSorter>(10, distribution);
//    sortTester.test<InsertSorter>(100, distribution);
//    sortTester.test<InsertSorter>(1000, distribution);
//    sortTester.test<InsertSorter>(10000, distribution);
//    sortTester.test<InsertSorter>(100000, distribution);
//    sortTester.test<InsertSorter>(1000000, distribution);
    return 0;
}
