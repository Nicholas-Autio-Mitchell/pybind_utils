//
// Created by n1k31t4 on 06.09.19.

// compile command: c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` funcs.cpp -o utils`python3-config --extension-suffix`

// takes approx. 8 seconds to compile

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

// #include "funcs.h"

// #include <math.h>    // Doesn't seem to be required

namespace py = pybind11;

template<typename T>
T add(T i, T j) {
    return i + j;
}

template<typename T>
T divide(T i, T j) {
    return i / j;
}

template<typename T>
T hyp(T i, T j) {
    T squared_sum = i * i + j * j;
    return std::pow(squared_sum, 0.5f);
}


// Create function with a wrapper around numpy arrays via py::array
//typedef py::array_t<double, py::array::c_style | py::array::forcecast> np_double;

/* This is to enable doubles to be used, which are not native to python
// Could try using the array module, passing a C-like double: import array array('d', [1.0, 2.0, 3.14])

 np_double hyp(np_double i, np_double j) {
    np_double squared_sum = i * i + j * j;
    double *result = squared_sum.cast<double *>();
    return std::pow(&result, 0.5f);
}

*/

PYBIND11_MODULE(utils, m) {
    m.doc() = "Utility functions written in C++";

    // Wraps expected overloads of each function
    m.def("add", &add<int>, "Apply operator+ to two integers");
    m.def("add", &add<float>, "Apply operator+ to two floats");
    m.def("divide", &divide<int>, "Apply operator/ to two integers");
    m.def("divide", &divide<float>, "Apply operator/ to two floats");
    m.def("hyp", &hyp<int>,  "Compute the hypotenuse of a triangle, given the two other side-lengths");
    m.def("hyp", &hyp<float>,  "Compute the hypotenuse of a triangle, given the two other side-lengths");
    // To use and return doubles, the NumPy interface must be use (not implemented here)
    // m.def("hyp", py::array_t<double>(&hyp<double>), "Compute the hypotenuse of a triangle, given the two other side-lengths");

    // Add an inline lambda function
    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract one integer from another
    )pbdoc");
    m.def("subtract", [](float i, float j) { return i - j; }, R"pbdoc(
        Subtract on float from another float
    )pbdoc");


}
