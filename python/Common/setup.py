from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

setup(
    cmdclass = {'build_ext': build_ext},
    ext_modules = [Extension("hermes_module", [
    "hermes-module.pyx",
    "hermes-module.pxd",
    "../translate_exceptions/translate_exception.cpp",
    "../translate_exceptions/raise_exception.pxd",
    "../translate_exceptions/raise_exception.pxi"
    ],language="c++",libraries=["hermes_module"])]
)
