# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    core.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 06:02:10 by nmauvari          #+#    #+#              #
#    Updated: 2018/09/10 06:15:11 by nmauvari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef ROOT
 ROOT := .
 include $(ROOT)/make_vars.mk
endif


OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

.PHONY : all
all : $(NAME) header

.PHONY : $(NAME)
$(NAME) : $(OUT_DIR_LIB)/$(LIBNAME).a

.PHONY : header
header : $(OUT_DIR_H)/$(LIBNAME).h

$(OUT_DIR_H)/$(LIBNAME).h : $(INC_DIR)/$(NAME).h 
	sed \
		-e'4s@\($(NAME)\.h\)   @lib\1@' \
		-e'13s@ @ LIB@' \
		-e'14s@\( define \)@\1LIB@' \
		$(INC_DIR)/$(NAME).h > \
		$(OUT_DIR_H)/$(LIBNAME).h

$(OUT_DIR_LIB)/$(LIBNAME).a : $(OBJS)
	-ar rcs $@ $^


#compilation :
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS)\
		-I $(LIBS_I)\
		-o $@ -c $<

.PHONY : re fclean clean all
clean :
	-rm $(OBJS)

fclean : clean
	-rm $(OUT_DIR_LIB)/$(LIBNAME).a
	-rm $(OUT_DIR_H)/$(LIBNAME).h

re : fclean all
