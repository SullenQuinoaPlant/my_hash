ifndef ROOT
 ROOT := ..
 include $(ROOT)/Makefile
endif

TEST_SRCS := $(wildcard $(TEST_DIR)/*.test.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)
EXECUTION_STAMPS := $(TEST_OBJS:.o=.execution.stamp)

CFLAGS_UTEST = -fno-builtin -g
CFLAGS_UTEST += $(CFLAGS_MORE) #$(CFLAGS) were annoying the hell out of me

include $(AUX_DIR)/Makefile

TEST_DEPENDENCIES = libgetnextline libcmocka_shared libaux

##########
#TESTS ALL
.PHONY : tests_all
tests_all : build_test_dependencies build_tests run_tests


############
#BUILD TESTS
.PHONY : build_test_dependencies
build_test_dependencies : $(TEST_DEPENDENCIES)

.PHONY : libcmocka_shared
libcmocka_shared :
	$(MAKE) -C $(TEST_DIR)/cmocka/;\

.PHONY : build_tests
build_tests\
:\
set_utest_flags def\
test_prerequisites\
$(TEST_OBJS)


.PHONY : set_utest_flags
set_utest_flags :
	$(eval CFLAGS += $(CFLAGS_UTEST))


.PHONY : test_prerequisites
test_prerequisites : cmocka


.PHONY : cmocka
cmocka : 
	if $(CC) $(CFLAGS_UTEST)\
		-I $(LIBS_I) -L $(LIBS_L)\
	 	$(TEST_DIR)/cmocka/check_install.c\
		-lcmocka_shared -o test.o\
		-Wl,-rpath=$(LIBS_L)\
		&& ./test.o .;\
	then\
		echo "cmocka installed";\
	else\
		echo "cmocka not installed";\
	fi
	-@rm ./test.o


$(TEST_DIR)/%.test.o\
:\
$(TEST_DIR)/%.test.c\
$(LIBS_L)/$(LIBNAME).a
	$(CC) $(CFLAGS_UTEST)\
		-I $(LIBS_I) -I $(SRC_DIR) -I $(TEST_DIR)\
		$<\
		-L $(LIBS_L)\
		-lcmocka_shared -laux\
		-l$(NAME) -lgetnextline -lft\
		-lm\
		-o $@\
		-Wl,-rpath=$(LIBS_L)\


%.test.c : $(TEST_DIR)/cmocka/my_macro_overlay.h
	@:



############
#RUN TESTS :

.PHONY : tests
tests : list_tests build_tests run_tests

.PHONY : run_tests
run_tests : $(EXECUTION_STAMPS)

%.execution.stamp : %.o
	-./$*.o "$(TEST_DIR)" \
	&& touch $@
#argument used to be
#	"$$(readlink -e $(TEST_DIR))" \



###############
#MISCELLANEOUS:

.PHONY : clean-tests
clean-tests :
	-rm $(TEST_DIR)/*.o
	-rm $(TEST_DIR)/*.stamp


.PHONY : list_tests
list_tests :
	@echo "source dir is : $(SRC_DIR)"
	@echo "list of test sources:"
	@echo $(TEST_SRCS)
	@echo "list of test objects:"
	@echo $(TEST_OBJS)
