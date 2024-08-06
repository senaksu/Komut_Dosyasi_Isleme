# Derleyici ve derleme bayrakları
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Dizinler
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
LIB_DIR = lib

# Kaynak dosyaları
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o,$(SRC_FILES))

# Kütüphane dosyası
LIB_FILE = $(LIB_DIR)/libfdr.a

# Yürütülebilir dosya
EXEC = $(BIN_DIR)/sistem

# Yürütülebilir dosyayı oluştur
$(EXEC): $(OBJ_FILES) | $(LIB_FILE) $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -lfdr

# Kaynak dosyalarını derle
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Dizinleri oluştur
$(BIN_DIR) $(LIB_DIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -rf $(BIN_DIR) $(LIB_FILE)
