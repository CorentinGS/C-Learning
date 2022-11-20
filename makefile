# **************************************************************************** #
#																			   #
#				  							  ______   _______      _______.   #
#	Makefile	  							 /      | /  _____|    /       |   #
#				  							|  ,----'|  |  __     |   (----`   #
#	By: CorentinGS 							|  |     |  | |_ |     \   \ 	   #
#	<c.giaufersaubert@outlook.com>			|  `----.|  |__| | .----)   | 	   #
#				  							 \______| \______| |_______/ 	   #
#   Created: 2022/11/05 by CorentinGS                                          #
#   LICENCE: MIT                          									   #
#																			   #
# **************************************************************************** #

# Inspired by https://github.com/tmatis/42make
# ASCII art from https://patorjk.com/software/taag/#p=display&f=Star%20Wars&t=CGS

################################################################################
#                                     CONFIG                                   #
################################################################################

# Name of the executable
NAME	= C

# Name of the compiler
CC 		= clang

# Flags for the compiler
CFLAGS	= -Wall -std=c99 -pedantic
# CFLAGS	+= -funroll-loops -fsanitize=address,undefined -fno-omit-frame-pointer -fno-optimize-sibling-calls -fvisibility=hidden
CFLAGS  += -Werror -Os -g
CFLAGS  += -Wextra -Wno-unused-parameter -Wno-unused-variable -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wstrict-prototypes -Wwrite-strings -Waggregate-return -Wunreachable-code
DFLAGS	= -MMD -MF $(@:.o=.d)

# MISC
AUTHOR  = "CorentinGS"
VERSION = "1.0"
DATE    = "2022-11-05"
OS 		= $(shell uname -s)

# TTY Fix
ifndef NOVISU
	NOVISU = 0
endif

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SEARCHPATH += src src/ds_td src/benchmark src/exercices src/linked_list src/sort src/tests src/utils
SEARCHPATH += src/tests/ds_td src/tests/linked_list src/tests/sort src/tests/utils src/tests/exercices
vpath %.c $(SEARCHPATH)
vpath %.h $(SEARCHPATH)

FILE_EXTENSION	= .c

SRCS_PATH		= ./src

INCLUDE_PATH	= ./src

SRCS			= utils.c linked_list.c counting_sort.c sdd_2019.c td3.c
SRCS 			+= td1.c merge_sort.c pyramide.c sort.c heap_sort.c matrix_sort.c
SRCS 			+= utils_test.c tests.c linked_list_test.c td1_test.c merge_sort_test.c pyramide_test.c
SRCS 			+= sort_test.c sort_benchmark.c

_OBJS += $(SRCS:.c=.o)

OBJS = $(patsubst %,objs/%,$(_OBJS))


HEADERS 		= common.h utils/enum.h  utils/colors.h

MAIN			= main.c


################################################################################
#                                  Makefile  objs                              #
################################################################################

SHELL := /bin/bash

#OBJS				= $(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.o})
OBJ_MAIN			= $(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.o})
DEPS				= $(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.d})
DEPS_MAIN			= $(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.d})

################################################################################
#                                 Makefile logic                               #
################################################################################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

COM_STRING   = "compiling"


RUN_CMD = script -q -e -c "$(1)" $@.log > /dev/null; \
			RESULT=$$?; \
			sed -i '1d' $@.log; \
			sed -i "$$(($$(wc -l < $@.log)-1)),\$$d" $@.log


define run_and_test
printf "%b%-46b" "$(COM_COLOR)$(COM_STRING) " "$(OBJ_COLOR)$(@F)$(NO_COLOR)"; \
$(RUN_CMD); \
if [ $$RESULT -ne 0 ]; then \
	printf "%b\n" "$(ERROR_COLOR)[✖]$(NO_COLOR)"; \
	rm -rf .files_changed; \
	if [ $(NOVISU) -eq 0 ]; then \
		echo; \
	fi; \
elif [ -s $@.log ]; then \
	printf "%b\n" "$(WARN_COLOR)[⚠]$(NO_COLOR)"; \
else  \
	printf "%b\n" "$(OK_COLOR)[✓]$(NO_COLOR)"; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef

define save_files_changed
	FILE_CPP=`echo $(SRCS) $(MAIN)`; \
	FILE_OBJ=`find objs -type f -name '*.o' 2>/dev/null | sed 's/objs\///'`; \
	TO_COMPILE=`echo $$FILE_CPP | wc -w`; \
	for FILE in $$FILE_CPP; do \
		for OBJ in $$FILE_OBJ; do \
			if [ $${FILE%$(FILE_EXTENSION)} = $${OBJ%.o} ]; then \
				if [ $(SRCS_PATH)/$$FILE -ot objs/$$OBJ ]; then \
					FILE_DEP=`echo objs/$$OBJ | sed 's/\.o/\.d/'`; \
					HEAD_FILES=`< $$FILE_DEP xargs | grep -oh "\w*.h\w*"`; \
					RECOMPILE=0; \
					for HEAD in $$HEAD_FILES; do \
						if [ $(SRCS_PATH)/$$HEAD -nt objs/$$OBJ ]; then \
							RECOMPILE=1; \
							break; \
						fi; \
					done; \
					if [ $$RECOMPILE -eq 0 ]; then \
						((TO_COMPILE=$$TO_COMPILE-1)); \
					fi;\
				fi; \
			fi; \
		done; \
	done; \
	echo 0/$$TO_COMPILE > .files_changed
endef

define draw_bar
	FILE_TOTAL=`bash -c 'cat .files_changed | cut -d"/" -f2'`; \
	FILE_DONE=`bash -c 'cat .files_changed | cut -d"/" -f1'`; \
	if [ $$FILE_TOTAL -eq 0 ]; then \
		FILE_TOTAL=1; \
		FILE_DONE=1; \
	fi; \
	RES=`echo "scale=2; $$FILE_DONE/$$FILE_TOTAL*48" | bc`; \
	RES=`echo $${RES%%.*}`; \
	printf "$(OBJ_COLOR)[$(NO_COLOR)"; \
	i=0; \
	while [ $$i -lt 48 ]; do \
		if [ $$i -lt $$RES ]; then \
			printf "$(OK_COLOR)█$(NO_COLOR)"; \
		else \
			printf "$(COM_COLOR)▒$(NO_COLOR)"; \
		fi; \
		((i=$$i+1)); \
	done; \
	printf "$(OBJ_COLOR)]$(NO_COLOR)"; \
	printf " ($(COM_COLOR)$$FILE_DONE$(NO_COLOR)/$(COM_COLOR)$$FILE_TOTAL$(NO_COLOR))"; \
	printf " "; \
	((FILE_DONE=$$FILE_DONE+1)); \
	echo $$FILE_DONE/$$FILE_TOTAL > .files_changed;
endef

define display_progress_bar
	if [ $(NOVISU) -eq 0 ]; then \
		line=`bash -c 'oldstty=$$(stty -g); stty raw -echo min 0; tput u7 > /dev/tty; IFS=";" read -r -d R -a pos; stty $$oldstty; row=$$(($${pos[0]:2} - 1)); echo $$row'`; \
		max_line=`tput lines`; \
		((max_line=$$max_line-2));\
		new_line=0; \
		tput sc; \
		i=0; \
		while [ $$i -lt 60 ]; do \
			printf " "; \
			((i=$$i+1)); \
		done; \
		tput rc; \
		if [ $$line -gt $$max_line ]; then \
			new_line=1; \
			echo ; \
		else \
			((line=$$line+1));\
		fi; \
		tput sc; \
		tput cup $$line; \
		$(draw_bar) \
		if [ $$new_line -eq 1 ]; then \
			((line=$$line-1));\
			tput cup $$line; \
		else \
			tput rc; \
		fi; \
	fi
endef

################################################################################
#                                 Makefile rules                             #
################################################################################

all: header setup $(NAME)
	@rm -rf .files_changed

header:
		@printf "%-10b" "$(OK_COLOR)"
		@echo "                       "
		@echo "   _____ _____  _____ "
		@echo "  / ____/ ____|/ ____|"
		@echo " | |   | |  __| (___  "
		@echo " | |   | | |_ |\___ \ "
		@echo " | |___| |__| |____) |"
		@echo "  \_____\_____|_____/ "
		@echo "                      "
		@echo
		# ASCII art from https://patorjk.com/software/taag/#p=display&f=Big&t=TP1
		@echo
		@printf "%-20b%b" "$(OBJ_COLOR)Name:" "$(WARN_COLOR)$(NAME)\n$(NO_COLOR)"
		@printf "%-20b%b" "$(OBJ_COLOR)Author:" "$(WARN_COLOR)$(AUTHOR)\n$(NO_COLOR)"
		@printf "%-20b%b" "$(OBJ_COLOR)Date:" "$(WARN_COLOR)$(DATE)\n$(NO_COLOR)"
		@printf "%-20b%b" "$(OBJ_COLOR)Version:" "$(WARN_COLOR)$(VERSION)\n$(NO_COLOR)"
		@printf "%-20b%b" "$(OBJ_COLOR)CC:" "$(WARN_COLOR)$(CC)\n$(NO_COLOR)"
		@printf "%-20b%b" "$(OBJ_COLOR)Flags:" "$(WARN_COLOR)$(CFLAGS)\n$(NO_COLOR)"
		@echo


-include $(DEPS) $(DEPS_MAIN)
$(NAME):	${OBJS} ${OBJ_MAIN}
			@$(call display_progress_bar)
			@$(call run_and_test,$(CC) $(CFLAGS) $(DFLAGS) -I$(INCLUDE_PATH) -o $@ ${OBJS} ${OBJ_MAIN})

setup:
	@$(call save_files_changed)

objs/%.o: 	%$(FILE_EXTENSION) $(HEADERS)
			@mkdir -p $(dir $@)
			@$(call display_progress_bar)
			@$(call run_and_test,$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I$(INCLUDE_PATH))

clean:		header
			@rm -rf objs objs_tests
			@printf "%-53b%b" "$(COM_COLOR)clean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

fclean:		header clean
			@rm -rf $(NAME)
			@printf "%-53b%b" "$(COM_COLOR)fclean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

re:			fclean all

.PHONY:		all clean fclean re header