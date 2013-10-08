AUTOMAKE_OPTIONS = subdir-objects no-dependencies
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

bin_PROGRAMS = telephone
telephone_SOURCES = main.cpp src/contact/Contact.h src/contact/Contact.cpp \
                    src/core/Core.h src/core/Core.cpp \
                    src/log/Logger.h src/log/Logger.cpp \
                    src/parser/Parser.h src/parser/Parser.cpp \
                    src/verifier/Verifier.h src/verifier/Verifier.cpp \
                    src/list/List.h src/list/List.cpp

#dist_noinst_SCRIPTS = autogen.sh
