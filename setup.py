from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        "fastsort.fastsort",
        ["fastsort/fastsort.cpp"],
        include_dirs=[pybind11.get_include()],
        extra_compile_args=['-std=c++11'],
        language='c++'
    ),
]

setup(
    name="fastsort",
    version="0.1.0",
    author="Your Name",
    description="Fast insertion sort implementations in C++",
    packages=["fastsort"],
    ext_modules=ext_modules,
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
