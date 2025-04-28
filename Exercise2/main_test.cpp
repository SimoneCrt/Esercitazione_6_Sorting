#include <gtest/gtest.h> //libreria GoogleTest,necessaria per usare tutte le macro

#include "test_sorting_algorithm.hpp"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv); //inizializza il google test.
    return RUN_ALL_TESTS();  //esegue tutti i test definiti nel progetto.
}




