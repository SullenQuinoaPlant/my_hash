.PHONY : def
def : targets
	$(MAKE) all


############
#VARIABLES :

ifndef ROOT
 ROOT := .
endif
include $(ROOT)/make_vars.mk


#######
#CORE :

include $(ROOT)/core.mk


########################
#TARGETS & DEPENDENCIES:

include $(SRC_DIR)/Makefile

#######
#LIBS :

include $(LIB_DIR)/Makefile

########
#TESTS :
	
include $(TEST_DIR)/Makefile



##########
#RELEASE :

RELEASE_DIR = release_$(NAME)

.PHONY : release
release :
	if [ -d $(RELEASE_DIR) ];\
	then rm -rf $(RELEASE_DIR)/;\
	fi
	git clone \
		--single-branch \
		-b release \
		$(GIT_REPO) \
		$(RELEASE_DIR)
	cd $(RELEASE_DIR) && git rm -rf *
	cp auteur $(RELEASE_DIR)/
	mkdir $(RELEASE_DIR)/sources
	cp -r $(SRC_DIR)/*.c $(RELEASE_DIR)/sources
	cp $(INC_DIR)/inner.h $(RELEASE_DIR)/sources
	cp core.mk $(RELEASE_DIR)/Makefile
	cp targets.mk $(RELEASE_DIR)/make_vars.mk
	cat release_vars.mk >> $(RELEASE_DIR)/make_vars.mk
	mkdir $(RELEASE_DIR)/includes
	cp $(patsubst %,$(LIBS_I)/%.h,$(DEPENDENCIES)) \
		$(RELEASE_DIR)/includes
	cd $(RELEASE_DIR) && \
		git add * && \
		git commit -m make_release && \
		git push origin release


################
#MISCELLANEOUS :

.PHONY : gcp
gcp :
	git commit -a -m i; git push;

.PHONY : grm
grm :
	git reset --hard && make CFLAGS_MORE=-g
