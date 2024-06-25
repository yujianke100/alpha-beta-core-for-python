#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include "bigraph.h"
#include "kcore.h"
#include "pyabcore.h"

namespace py = pybind11;

void (Pyabcore::*index1)() = &Pyabcore::index;
void (Pyabcore::*index2)(py::array_t<int>, int, int) = &Pyabcore::index;

PYBIND11_MODULE(pyabcore, m) {
    py::class_<Pyabcore>(m, "Pyabcore")
        .def(py::init<int, int>())
        .def(py::init<const std::string &>())
        .def("index", index1)
        .def("index", index2)
        .def("query", &Pyabcore::query)
        .def("get_left", &Pyabcore::get_left)
        .def("get_right", &Pyabcore::get_right);
}
