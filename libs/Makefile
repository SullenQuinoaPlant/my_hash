ifndef ROOT
	ROOT = ..
	include $(ROOT)/Makefile
endif


.PHONY : build-dependencies
build-dependencies : $(DEPENDENCIES)
	@echo "$(DEPENDENCIES)"

define BUILD_LIB
	$(MAKE) -C $@/ 
	cp $@/$@.a $(LIBS_L)
	cp $@/$@.h $(LIBS_I) || cp $@/includes/$@.h $(LIBS_I)
	rm -rf $@
	touch $(LIB_DIR)/$@
endef
	
libft :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/Libft.git \
		--depth 1 \
		$@/
	$(BUILD_LIB)

libgetnextline :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/get_next_line.git \
		--depth 1 \
		$@/
	$(BUILD_LIB)


.PHONY : clean-*
clean-% :
	-rm $(LIB_DIR)/$*
	-rm $(LIBS_I)/$*.h
	-rm $(LIBS_L)/$*.a
