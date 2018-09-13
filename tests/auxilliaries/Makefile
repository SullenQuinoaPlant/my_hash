ifndef ROOT
	ROOT = ../..
	include $(ROOT)/Makefile
endif

AUX_SRCS := $(wildcard $(AUX_DIR)/*.c)
AUX_OBJS := $(patsubst %.c,%.o,$(AUX_SRCS))

.PHONY : libaux
libaux : $(AUX_OBJS)
	ar rcs $(LIBS_L)/$@.a $(AUX_OBJS)
	cp $(AUX_DIR)/auxilliaries.h $(LIBS_I)/libaux.h

$(AUX_DIR)/%.o : $(AUX_DIR)/%.c
	$(CC) $(CFLAGS) $(CFLAGS_UTEST)\
		-I $(LIBS_I)\
		-c $<\
		-o $@

.PHONY : clean-libaux 
clean-libaux :
	-rm $(AUX_OBJS)
	-rm $(LIBS_I)/libaux.h
	-rm $(LIBS_L)/libaux.a
