#!/usr/bin/env python
from setuptools import setup, Extension
import pybind11
import numpy as np
import os

# 确保包括所有必要的源文件
ext_modules = [
    Extension(
        'pyabcore',
        sources=['pyabcore_bind.cpp', 'pyabcore.cpp', 'bigraph.cpp', 'kcore.cpp'],
        include_dirs=[pybind11.get_include(), np.get_include()],
        language='c++',
        extra_compile_args=['-std=c++11'],
    ),
]

setup(
    name='pyabcore',
    version='0.1',
    author='yujianke',
    description='alpha beta core for python',
    ext_modules=ext_modules,
    zip_safe=False,
)
