from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

setup(
    cmdclass = {'build_ext': build_ext},
    ext_modules = [Extension("hermes_modulePoisson", [
    "hermes_modulePoisson.pyx",
    "hermes_modulePoisson.pxi",
    "hermes_modulePoisson.pxd"
    ],language="c++",libraries=["hermes_modulePoisson"])]
)
