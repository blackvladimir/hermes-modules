HERMES_DIR="/usr/local"
HERMES_WRAPPERS_DIR="/home/lukas/hpfem/hermes/l-korous/hermes-python"
MODULES_DIR="/usr/local"
cd Common
python setup.py build_ext --include-dirs="$MODULES_DIR/include/hermes_module/:$HERMES_DIR/include/hermes_common/:$HERMES_DIR/include/hermes2d/:$HERMES_WRAPPERS_DIR/hermes2d/:$HERMES_WRAPPERS_DIR/hermes_common" --library-dirs="$MODULES_DIR/lib/:$HERMES_DIR/lib" --pyrex-include-dirs="$HERMES_WRAPPERS_DIR/hermes2d/:$HERMES_WRAPPERS_DIR/hermes_common" install_lib
cd ../01-Poisson
python setup.py build_ext --include-dirs="$MODULES_DIR/include/hermes_module/:$HERMES_DIR/include/hermes_common/:$HERMES_DIR/include/hermes2d/:$HERMES_WRAPPERS_DIR/hermes2d/:$HERMES_WRAPPERS_DIR/hermes_common/:$MODULES_DIR/include/hermes_modulePoisson/" --library-dirs="$MODULES_DIR/lib/:$HERMES_DIR/lib/" --pyrex-include-dirs="$HERMES_WRAPPERS_DIR/hermes2d/:$HERMES_WRAPPERS_DIR/hermes_common/:../Common/" install_lib
