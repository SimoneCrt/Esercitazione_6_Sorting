#pragma once

#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "SortingAlgorithm.hpp"

//racchiudo i test nello stesso namespace in cui si trovano gli algoritmi
 
namespace SortLibrary {
//definisco un test case chiamato "TestBubbleSort" che fa parte della famiglia "TestSorting"
TEST(TestSorting, TestBubbleSort)
{
    std::vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    BubbleSort<int>(v); //applico algoritmo bubblesort
    std::vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12, 13}; //risultato atteso
	//verifico che il vettore ordinato v sia uguale a "sortedV"
    EXPECT_EQ(v, sortedV);
}
//stesso ragionamento di cui sopra
TEST(TestSorting, TestHeapSort)
{
    std::vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    HeapSort<int>(v); 
    std::vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12, 13};
    EXPECT_EQ(v, sortedV);
}

}





