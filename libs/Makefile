ifndef ROOT
	ROOT = ..
	include $(ROOT)/Makefile
endif


.PHONY : build_dependencies
build_dependencies : $(DEPENDENCIES)
	@echo "$(DEPENDENCIES)"

define BUILD_LIB
	$(MAKE) -C $@/ 
	cp $@/$@.a $(LIBS_L)
	cp $@/$@.h $(LIBS_I) || cp $@/includes/$@.h $(LIBS_I)
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


.PHONY : clean-lib*
clean-lib% :
	-rm -rf $(LIB_DIR)/lib$*
	-rm $(LIBS_I)/lib$*.h
	-rm $(LIBS_L)/lib$*.a

.PHONY : re-lib*
re-lib% : clean-lib% lib%
	@:
