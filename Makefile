## Default formatting values for the printing tools below
DEBUG_DEFAULT_HDR_WIDTH:=130
DEBUG_DEFAULT_HDR_FG:=32
DEBUG_DEFAULT_HDR_CHAR:==


## Print bold header, n chars
## e.g.
##    ==============================================================================
##    | DB Vars
##    ==============================================================================
##
## https://misc.flogisoft.com/bash/tip_colors_and_formatting for bash format details
##
## e.g. $(call dump_header, $(DEBUG_DEFAULT_HDR_WIDTH), "SOME HEADER", $(DEBUG_DEFAULT_HDR_CHAR), $(DEBUG_DEFAULT_HDR_FG))
define dump_header
	@$(eval HDR_WIDTH:=$(1))
	@$(eval HDR_MSG:=$(2))
	@$(eval HDR_CHAR:=$(3))
	@$(eval HDR_FG:=$(4))
	@printf "\e[$(HDR_FG)m%0.s$(HDR_CHAR)\e[0m" {1..$(HDR_WIDTH)}
	@printf "\n"
	@printf "\e[1;$(HDR_FG)m| %s \e[0m" $(HDR_MSG)
	@printf "\n"
	@printf "\e[$(HDR_FG)m%0.s$(HDR_CHAR)\e[0m" {1..$(HDR_WIDTH)}
	@echo ""
endef


CC= clang
CFLAGS= 
LIBS=

AR= ar -r
RM= rm -f

strings.o: strings.c
	$(CC) $(CFLAGS) -c strings.c

test: build_test_header build_test run_test_header run_test

build_test_header:
	$(call dump_header, $(DEBUG_DEFAULT_HDR_WIDTH), "Build", $(DEBUG_DEFAULT_HDR_CHAR), $(DEBUG_DEFAULT_HDR_FG))

build_test: strings_test

run_test_header:
	$(call dump_header, $(DEBUG_DEFAULT_HDR_WIDTH), "Run Tests", $(DEBUG_DEFAULT_HDR_CHAR), $(DEBUG_DEFAULT_HDR_FG))

run_test:
	./tests/strings_test

strings_test: strings.o tests/strings_test.c
	$(CC) -o tests/strings_test strings.o tests/strings_test.c

clean:
	$(RM) $(NATURE_O) $(NATURE_A)
	rm -rf ./tests/string_test
