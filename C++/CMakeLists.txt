project(hermes_tutorial)
	cmake_minimum_required(VERSION 2.6)

	set(CMAKE_MODULE_PATH ${CMAKE_HOME_DIRECTORY}/cmake)
	
	# --- OPTIONS
	#
	# Where to look for the static libraries (may be overriden by CMake.vars).
	set(HERMES_DIRECTORY "/usr/local/lib")
	set(HERMES_INCLUDE_PATH "/usr/local/include")
	set(DEP_INCLUDE_PATHS "/usr/local/include")

	# Trilinos
	# Enable support for Trilinos solvers.
	set(WITH_TRILINOS           NO)
				
	# Include debugging symbols.
	set(DEBUG_VERSION           YES)
	
	# Allow to override the default values in CMake.vars:
	include(CMake.vars OPTIONAL)

        set(TARGET_ROOT             /usr/local) 
        #default installation path for the library will be /usr/local/lib
        #for include files /usr/local/include



  # --- DEPENDENCIES
  #
	find_package(PTHREAD REQUIRED)

	if(WITH_TRILINOS)
		find_package(TRILINOS REQUIRED)
		include_directories(${TRILINOS_INCLUDE_DIR})
	endif(WITH_TRILINOS)
	
	if(WITH_MPI)
		if(NOT MPI_INCLUDE_PATH)
			find_package(MPI REQUIRED)
		endif(NOT MPI_INCLUDE_PATH)
		include_directories(${MPI_INCLUDE_PATH})
	endif(WITH_MPI)
	
	set(HERMES2D_INCLUDE_PATH ${HERMES_INCLUDE_PATH}/hermes2d)
	set(HERMES_COMMON_INCLUDE_PATH ${HERMES_INCLUDE_PATH}/hermes_common)
	
	find_package(HERMES_COMMON REQUIRED)

	include_directories(${HERMES_COMMON_INCLUDE_PATH})
	include_directories(${HERMES2D_INCLUDE_PATH})
	include_directories(${DEP_INCLUDE_PATHS})

  add_subdirectory(Common)
  add_subdirectory(01-Poisson)
