#define BOOST_TEST_MODULE TestMain

#include <boost/test/unit_test.hpp>
#include "Matrix.h"
#include <iostream>

BOOST_AUTO_TEST_SUITE(test_matrix)
    Matrix matrix(5, 5, 5);

    BOOST_AUTO_TEST_CASE(test_default) {
        BOOST_CHECK(matrix[3][3] == 5);
    }

    BOOST_AUTO_TEST_CASE(test_assige) {
        matrix[3][3] = 10;
        BOOST_CHECK(matrix[3][3] == 10);
        matrix[3][3] = 200;
        BOOST_CHECK(matrix[3][3] == 200);
        BOOST_CHECK(matrix[0][0] == 5);
        matrix[0][0] = 100;
        BOOST_CHECK(matrix[0][0] == 100);
    }

    BOOST_AUTO_TEST_CASE(assign_default){
        Matrix matrix1(5, 5, 5);
        BOOST_CHECK(matrix1.elements() == 0);
        matrix1[3][3] = 10;
        BOOST_CHECK(matrix1.elements() == 1);
        matrix1[3][3] = 5;
        BOOST_CHECK(matrix1.elements() == 0);
    }

BOOST_AUTO_TEST_SUITE_END()
