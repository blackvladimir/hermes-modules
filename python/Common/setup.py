from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

setup(
    cmdclass = {'build_ext': build_ext},
    ext_modules = [Extension("hermes_module", [
    "hermes_module.pyx",
    "hermes_module.pxd",
    "hermes_module.pxi",
    "hermes_module_common.pxd"
    ],language="c++",libraries=["hermes_module"])]
)
