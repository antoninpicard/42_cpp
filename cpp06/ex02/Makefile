# ============================================================
#  Configuration
# ============================================================

NAME        := identify
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -g3 -std=c++98 -MMD -MP -Iinc

DIR_OBJS    := .objs
DIR_DEPS    := .deps

CORE_DIR = core

CORE        := $(CORE_DIR)/main.cpp $(CORE_DIR)/Base.cpp

OBJS        := $(addprefix $(DIR_OBJS)/, $(CORE:.cpp=.o))
DEPS        := $(addprefix $(DIR_DEPS)/, $(CORE:.cpp=.d))

# ============================================================
#  Rules
# ============================================================

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@echo "Linked: $@"

$(DIR_OBJS) $(DIR_DEPS):
	@mkdir -p $@

$(DIR_OBJS)/$(CORE_DIR)/%.o: $(CORE_DIR)/%.cpp Makefile | $(DIR_OBJS) $(DIR_DEPS)
	@mkdir -p $(dir $@) $(patsubst $(DIR_OBJS)/%,$(DIR_DEPS)/%,$(dir $@))
	@$(CXX) $(CXXFLAGS) -MF $(patsubst $(DIR_OBJS)/%.o,$(DIR_DEPS)/%.d,$@) -c $< -o $@
	@echo "Compiled: $<"

-include $(DEPS)

# ============================================================
#  Cleaner
# ============================================================

clean:
	@if [ -d $(DIR_OBJS) ] || [ -d $(DIR_DEPS) ]; then \
		rm -rf $(DIR_OBJS) $(DIR_DEPS); \
		echo "Cleaned: $(DIR_OBJS) $(DIR_DEPS)"; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		echo "Cleaned: $(NAME)"; \
	fi

re: fclean all