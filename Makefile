# Nome del progetto
NAME    = cub3D
NAMEB	= cub3D_bonus

# Compiler e flags
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra -Iminilibx-linux
LDLIBS   = -lm

# Directory dei sorgenti e degli oggetti
SRC_DIR = srcs
SRC_PARSE = $(SRC_DIR)/parsing
SRC_RAY = $(SRC_DIR)/raycasting
SRC_REND = $(SRC_DIR)/rendering
SRC_UTLS = $(SRC_DIR)/utils
SRC_GNL = $(SRC_DIR)/get_next_line

SRCB_DIR = srcs_bonus
SRCB_PARSE = $(SRCB_DIR)/parsing
SRCB_RAY = $(SRCB_DIR)/raycasting
SRCB_REND = $(SRCB_DIR)/rendering
SRCB_UTLS = $(SRCB_DIR)/utils
SRCB_GNL = $(SRCB_DIR)/get_next_line

TXT_DIR = textures
MAP_DIR = maps
OBJ_DIR = objs

# Lista dei file sorgente e relativi oggetti
SRC     = $(SRC_DIR)/main.c $(SRC_PARSE)/parsing.c $(SRC_PARSE)/parsefields.c $(SRC_PARSE)/scene_check.c $(SRC_PARSE)/scene_check_2.c $(SRC_PARSE)/cases.c $(SRC_PARSE)/cases2.c $(SRC_PARSE)/parsemap.c $(SRC_PARSE)/checkmap.c $(SRC_PARSE)/sqrmap.c $(SRC_REND)/rendering.c $(SRC_REND)/init_player.c $(SRC_REND)/rendering_loop.c $(SRC_REND)/rendering_texture.c $(SRC_REND)/rendering_pixel.c $(SRC_REND)/rendering_utils.c $(SRC_REND)/rendering_utils2.c $(SRC_REND)/fps.c $(SRC_REND)/move_player.c $(SRC_REND)/debug_mode.c $(SRC_RAY)/raycasting.c $(SRC_UTLS)/utils.c $(SRC_UTLS)/utils2.c $(SRC_GNL)/get_next_line_utils.c $(SRC_GNL)/get_next_line.c
OBJ     = $(OBJ_DIR)/main.o $(OBJ_DIR)/parsing.o $(OBJ_DIR)/parsefields.o $(OBJ_DIR)/scene_check.o $(OBJ_DIR)/scene_check_2.o $(OBJ_DIR)/cases.o $(OBJ_DIR)/cases2.o $(OBJ_DIR)/parsemap.o $(OBJ_DIR)/checkmap.o $(OBJ_DIR)/sqrmap.o $(OBJ_DIR)/rendering.o $(OBJ_DIR)/init_player.o $(OBJ_DIR)/rendering_loop.o $(OBJ_DIR)/rendering_texture.o $(OBJ_DIR)/rendering_pixel.o $(OBJ_DIR)/rendering_utils.o $(OBJ_DIR)/rendering_utils2.o $(OBJ_DIR)/fps.o $(OBJ_DIR)/move_player.o $(OBJ_DIR)/debug_mode.o $(OBJ_DIR)/raycasting.o $(OBJ_DIR)/utils.o $(OBJ_DIR)/utils2.o $(OBJ_DIR)/get_next_line_utils.o $(OBJ_DIR)/get_next_line.o
SRCB     = $(SRCB_DIR)/main_bonus.c $(SRCB_PARSE)/parsing_bonus.c $(SRCB_PARSE)/parsefields_bonus.c $(SRCB_PARSE)/scene_check_bonus.c $(SRCB_PARSE)/scene_check_2_bonus.c $(SRCB_PARSE)/cases_bonus.c $(SRCB_PARSE)/cases2_bonus.c $(SRCB_PARSE)/parsemap_bonus.c $(SRCB_PARSE)/checkmap_bonus.c $(SRCB_PARSE)/sqrmap_bonus.c $(SRCB_REND)/rendering_bonus.c $(SRCB_REND)/init_player_bonus.c $(SRCB_REND)/rendering_loop_bonus.c $(SRCB_REND)/rendering_texture_bonus.c $(SRCB_REND)/rendering_pixel_bonus.c $(SRCB_REND)/rendering_utils_bonus.c $(SRCB_REND)/rendering_utils2_bonus.c $(SRCB_REND)/fps_bonus.c $(SRCB_REND)/move_player_bonus.c $(SRCB_REND)/render_map_bonus.c $(SRCB_REND)/debug_mode_bonus.c $(SRCB_RAY)/raycasting_bonus.c $(SRCB_UTLS)/utils_bonus.c $(SRCB_UTLS)/utils2_bonus.c $(SRCB_GNL)/get_next_line_utils.c $(SRCB_GNL)/get_next_line.c
OBJB     = $(OBJ_DIR)/main_bonus.o $(OBJ_DIR)/parsing_bonus.o $(OBJ_DIR)/parsefields_bonus.o $(OBJ_DIR)/scene_check_bonus.o $(OBJ_DIR)/scene_check_2_bonus.o $(OBJ_DIR)/cases_bonus.o $(OBJ_DIR)/cases2_bonus.o $(OBJ_DIR)/parsemap_bonus.o $(OBJ_DIR)/checkmap_bonus.o $(OBJ_DIR)/sqrmap_bonus.o $(OBJ_DIR)/rendering_bonus.o $(OBJ_DIR)/init_player_bonus.o $(OBJ_DIR)/rendering_loop_bonus.o $(OBJ_DIR)/rendering_texture_bonus.o $(OBJ_DIR)/rendering_pixel_bonus.o $(OBJ_DIR)/rendering_utils_bonus.o $(OBJ_DIR)/rendering_utils2_bonus.o $(OBJ_DIR)/fps_bonus.o $(OBJ_DIR)/move_player_bonus.o $(OBJ_DIR)/debug_mode_bonus.o $(OBJ_DIR)/render_map_bonus.o $(OBJ_DIR)/raycasting_bonus.o $(OBJ_DIR)/utils_bonus.o $(OBJ_DIR)/utils2_bonus.o $(OBJ_DIR)/get_next_line_utils.o $(OBJ_DIR)/get_next_line.o

# Parametri per libft
LIBFT_DIR = libft
LIBFT    = $(LIBFT_DIR)/libft.a

# MinilibX
MLX_DIR = minilibx-linux

# Comando di rimozione
RM      = rm -rf

# Target di default
all: $(NAME)

# Compila MinilibX se presente
$(MLX_DIR)/libmlx_Linux.a:
	@if [ -d "$(MLX_DIR)" ]; then \
		if [ -f "$(MLX_DIR)/configure" ]; then \
			chmod +x "$(MLX_DIR)/configure" || true; \
		fi; \
		if [ -f "$(TXT_DIR)/no_perm.xpm" ]; then \
			chmod -r "$(TXT_DIR)/no_perm.xpm" || true; \
		fi; \
		if [ -f "$(MAP_DIR)/no_perm.cub" ]; then \
			chmod -r "$(MAP_DIR)/no_perm.cub" || true; \
		fi; \
		$(MAKE) -C $(MLX_DIR); \
	else \
		echo "Error: mlx directory '$(MLX_DIR)' not found."; \
	fi

# Regola per creare l'eseguibile, dipendente da oggetti e dalla libft compilata
$(NAME): $(OBJ) $(LIBFT) $(MLX_DIR)/libmlx_Linux.a
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz -lbsd -o $(NAME) $(LDLIBS)

bonus: $(OBJB) $(LIBFT) $(MLX_DIR)/libmlx_Linux.a
	$(CC) $(CFLAGS) $(OBJB) $(LIBFT) -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz -lbsd -o $(NAMEB) $(LDLIBS)

# Regola per compilare i file .c in file .o all'interno della directory obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_PARSE)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_RAY)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_REND)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_UTLS)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_GNL)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regola per compilare i file _bonus.c in file _bonus.o all'interno della directory obj
$(OBJ_DIR)/%.o: $(SRCB_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRCB_PARSE)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRCB_RAY)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRCB_REND)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRCB_UTLS)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRCB_GNL)/%.c | $(OBJ_DIR)
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
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR) clean || true; fi
	@if [ -f "$(TXT_DIR)/no_perm.xpm" ]; then chmod +r "$(TXT_DIR)/no_perm.xpm" || true; fi
	@if [ -f "$(MAP_DIR)/no_perm.cub" ]; then chmod +r "$(MAP_DIR)/no_perm.cub" || true; fi

# Pulizia completa: rimuove l'eseguibile, gli oggetti e la libft (file oggetto e libft.a)
fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAMEB)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@if [ -f "$(MLX_DIR)/libmlx_Linux.a" ]; then rm -f $(MLX_DIR)/libmlx_Linux.a; fi

# Ricompilazione totale
re: fclean all
