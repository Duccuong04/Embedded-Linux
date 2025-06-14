.PHONY: build clean

# Đường dẫn
PATH_OUTPUT := output
PRO_DIR := 

# Thư mục chứa file .h
INCLUDE_DIRS := $(PRO_DIR)/include

# Mục tiêu chính
build: main.o sum.o
	gcc output/main.o output/sum.o -o $(PATH_OUTPUT)/app.exe
	./$(PATH_OUTPUT)/app.exe

# Compile main.c thành main.o
main.o:
	gcc -I$(INCLUDE_DIRS) -c source/main.c -o $(PATH_OUTPUT)/$@

# Compile sum.c thành sum.o
sum.o:
	gcc -I$(INCLUDE_DIRS) -c source/sum.c -o $(PATH_OUTPUT)/$@

# Clean: xóa tất cả file trong output/
clean:
	rm -rf $(PATH_OUTPUT)/*
