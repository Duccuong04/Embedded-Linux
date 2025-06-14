#!/bin/bash

# Tên thư mục cần kiểm tra/ tạo
FOLDER_NAME="myfolder"
FULL_PATH="$HOME/$FOLDER_NAME"

# Kiểm tra xem folder tồn tại chưa
if [ -d "$FULL_PATH" ]; then
    echo "Đã tồn tại"
else
    mkdir "$FULL_PATH"
    echo "Đã tạo thư mục '$FULL_PATH'"
fi
