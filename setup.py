from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext
import pybind11
import sys
import platform

# Define the extension module
ext_modules = [
    Pybind11Extension(
        "fastsort.fastsort",
        ["fastsort/fastsort.cpp"],
        include_dirs=[
            # Path to pybind11 headers
            pybind11.get_include(),
            pybind11.get_include(user=True)
        ],
        extra_compile_args=['-std=c++11'],
        cxx_std=11,
    ),
]

setup(
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
)
import pybind11

ext_modules = [
    Extension(
        "fastsort.fastsort",
        ["fastsort/fastsort.cpp"],
        include_dirs=[pybind11.get_include()],
        language='c++'
    ),
]

setup(
    ext_modules=ext_modules,
    zip_safe=False,
)
