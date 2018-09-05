ifndef ROOT
	ROOT = ../..
	include $(ROOT)/Makefile
endef

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
