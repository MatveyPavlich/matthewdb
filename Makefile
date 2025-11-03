SRC_DIR = src
BUILD_DIR = build
LAB_DIR = lab

main: 
	gcc -std=c99 -Wall -Werror -I./$(SRC_DIR)/inft ./$(SRC_DIR)/impl/storage/main.c -o ./$(BUILD_DIR)/main
	# gcc -std=c99 -Wall -Werror ./$(LAB_DIR)/main.c -o ./$(BUILD_DIR)/main


clean:
	rm -rf $(BUILD_DIR)/*

run:
	$(BUILD_DIR)/main

debug:
	@gdb -q \
		-iex 'set auto-load local-gdbinit on' \
		-iex 'set auto-load safe-path $$debugdir:$$datadir/auto-load:$(PWD)' \
		./$(BUILD_DIR)/main


