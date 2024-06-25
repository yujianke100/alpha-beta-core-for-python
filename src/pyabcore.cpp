#include "pyabcore.h"
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <iostream>
#include <vector>

using namespace std;
namespace py = pybind11;

Pyabcore::Pyabcore(string dir) {
    this->dir = dir;
}

Pyabcore::Pyabcore(int init_n1, int init_n2) {
    n1 = init_n1;
    n2 = init_n2;
}

void Pyabcore::index() {
    cout << "start ComShrDecom in :" << dir << endl;

    BiGraph g(dir);
    coreIndexKCore(g);
    build_bicore_index(g, bicore_index_u, bicore_index_v);
    left.resize(g.num_v1, false); 
    right.resize(g.num_v2, false);
    cout << "finished!" << endl;
}

void Pyabcore::index(py::array_t<int> inputA2, int D1, int D2) {
    cout << "start ComShrDecom" << endl;

    py::buffer_info buf = inputA2.request();
    int *ptr = static_cast<int *>(buf.ptr);

    try {
        BiGraph g(ptr, D1, D2, n1, n2);
        cout << "bigraph" << endl;
        coreIndexKCore(g);
        cout << "kcore" << endl;
        build_bicore_index(g, bicore_index_u, bicore_index_v);
        cout << "build_bicore_index" << endl;
        left.resize(g.num_v1, false);
        cout << "left.resize" << endl;
        right.resize(g.num_v2, false);
        cout << "finished!" << endl;
    } catch (const std::exception &e) {
        cerr << "Exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Unknown exception!" << endl;
    }
}

void Pyabcore::query(int a, int b) {
    cout << "start query" << endl;
    retrieve_via_bicore_index(g, bicore_index_u, bicore_index_v, left, right, a, b);
    cout << "finished!" << endl;
}

vector<bool> Pyabcore::get_left() {
    return left;
}

vector<bool> Pyabcore::get_right() {
    return right;
}
