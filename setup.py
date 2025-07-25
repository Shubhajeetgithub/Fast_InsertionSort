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
    name="fastsort",
    version="0.1.0",
    author="Shubhajeet",
    description="High-Performance Insertion Sort Variations",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    python_requires=">=3.7",
)
