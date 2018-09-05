ifndef ROOT
	ROOT = ../..
	include $(ROOT)/Makefile
endef

AUX_DIR = $(TEST_DIR)/auxilliaries
AUX_OBJS := $(wildcard $(AUX_DIR)/*.c)

libaux :
	ar rcs $@ $(AUX_OBJS)
	mv $@ $(LIBS_L)
	cp $(AUX_DIR)/libaux.h $(LIBS_I)

$(AUX_DIR)/%.o : $(AUX_DIR)/%.c
	$(CC) $(CFLAGS) $(CFLAGS_UTEST)\
		-I $(LIBS_I) -L $(LIBS_L)\
		$<\
		-lgetnextline -lm\
		-o $@
