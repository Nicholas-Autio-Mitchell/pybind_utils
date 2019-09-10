//
// Created by n1k31t4 on 06.09.19.
//

#ifndef PYBIND_UTILS_FUNCS_H
#define PYBIND_UTILS_FUNCS_H

#include <pybind11/pybind11.h>

namespace py = pybind11;

template<typename T_>
T_ add(T_ i, T_ j);

template<typename T_>
T_ divide(T_ i, T_ j);

template<typename T_>
T_ hyp(T_ i, T_ j);

#endif //PYBIND_UTILS_FUNCS_H
