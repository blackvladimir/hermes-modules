HERMES_DIR="/usr/local"
HERMES_WRAPPERS_DIR="/home/lukas/hpfem/hermes/l-korous/hermes-python"
cd hermes_module
python setup.py build_ext --inplace --include-dirs="../../C++/hermes_module/:$HERMES_DIR/include/hermes_common/:$HERMES_DIR/include/hermes2d/:$HERMES_WRAPPERS_DIR/hermes2d/:$HERMES_WRAPPERS_DIR/hermes_common" --library-dirs="../../C++/hermes_module/:$HERMES_DIR/lib" --pyrex-include-dirs="$HERMES_WRAPPERS_DIR/hermes2d/:$HERMES_WRAPPERS_DIR/hermes_common"
cd ../hermes_modulePoisson
python setup.py build_ext --inplace --include-dirs="../../C++/hermes_modulePoisson/:$HERMES_DIR/include/hermes_common/:$HERMES_DIR/include/hermes2d/:$HERMES_WRAPPERS_DIR/hermes2d/:$HERMES_WRAPPERS_DIR/hermes_common/:../../C++/hermes_module/" --library-dirs="../../C++/hermes_modulePoisson/:$HERMES_DIR/lib/:../hermes_module/" --pyrex-include-dirs="$HERMES_WRAPPERS_DIR/hermes2d/:$HERMES_WRAPPERS_DIR/hermes_common/:../hermes_module/"
