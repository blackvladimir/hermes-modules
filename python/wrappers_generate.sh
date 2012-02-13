cd Common
python setup.py build_ext --inplace --include-dirs="../C++/Common" --library-dirs="$../C++/Common"
cd ../01-Poisson
python setup.py build_ext --inplace --include-dirs="$../C++/01-Poisson" --library-dirs="../C++/01-Poisson"
