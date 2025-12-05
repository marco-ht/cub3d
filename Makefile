# Nome del progetto
NAME    = cub3D
NAMEB	= cub3D_bonus

# Compiler e flags
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra
LDLIBS   = -lm

# Directory dei sorgenti e degli oggetti
SRC_DIR = srcs
SRC_PARSE = $(SRC_DIR)/parsing
SRC_RAY = $(SRC_DIR)/raycasting
SRC_REND = $(SRC_DIR)/rendering
SRC_UTLS = $(SRC_DIR)/utils
SRC_GNL = $(SRC_DIR)/get_next_line
OBJ_DIR = objs

# Lista dei file sorgente e relativi oggetti
SRC     = $(SRC_DIR)/main.c $(SRC_PARSE)/parsing.c $(SRC_PARSE)/scene_check.c $(SRC_PARSE)/cases.c $(SRC_PARSE)/cases2.c $(SRC_UTLS)/utils.c $(SRC_GNL)/get_next_line_utils.c $(SRC_GNL)/get_next_line.c
OBJ     = $(OBJ_DIR)/main.o $(OBJ_DIR)/parsing.o $(OBJ_DIR)/scene_check.o $(OBJ_DIR)/cases.o $(OBJ_DIR)/cases2.o $(OBJ_DIR)/utils.o $(OBJ_DIR)/get_next_line_utils.o $(OBJ_DIR)/get_next_line.o

# Parametri per libft
LIBFT_DIR = libft
LIBFT    = $(LIBFT_DIR)/libft.a

# Comando di rimozione
RM      = rm -rf

# Target di default
all: $(NAME)

# Regola per creare l'eseguibile, dipendente da oggetti e dalla libft compilata
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LDLIBS)

bonus: $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAMEB) $(LDLIBS)

# Regola per compilare i file .c in file .o all'interno della directory obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_PARSE)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_UTLS)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_GNL)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Creazione della directory degli oggetti, se non esiste
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compilazione della libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

# Pulizia dei file oggetto (interni e di libft)
clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

# Pulizia completa: rimuove l'eseguibile, gli oggetti e la libft (file oggetto e libft.a)
fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAMEB)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Ricompilazione totale
re: fclean all
