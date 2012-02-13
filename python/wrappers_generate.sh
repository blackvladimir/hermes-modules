HERMES_DIR="/usr/local/"
cd Common
python setup.py build_ext --inplace --include-dirs="../C++/Common/:$HERMES_DIR/include/hermes_common/:$HERMES_DIR/include/hermes2d" --library-dirs="$../C++/Common/:$HERMES_DIR/lib"
cd ../01-Poisson
python setup.py build_ext --inplace --include-dirs="$../C++/01-Poisson/:$HERMES_DIR/include/hermes_common/:$HERMES_DIR/include/hermes2d" --library-dirs="../C++/01-Poisson/:$HERMES_DIR/lib"
