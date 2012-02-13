HERMES_DIR="/usr/local"
HERMES_WRAPPERS_DIR="/home/lukas/hpfem/hermes/l-korous/hermes-python"
cd Common
python setup.py build_ext --inplace --include-dirs="../../C++/Common/:$HERMES_DIR/include/hermes_common/:$HERMES_DIR/include/hermes2d/:$HERMES_WRAPPERS_DIR/hermes2d/:$HERMES_WRAPPERS_DIR/hermes_common" --library-dirs="../../C++/Common/:$HERMES_DIR/lib" --pyrex-include-dirs="$HERMES_WRAPPERS_DIR/hermes2d/:$HERMES_WRAPPERS_DIR/hermes_common" 
