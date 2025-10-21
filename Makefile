SRC_DIR = src
BUILD_DIR = build

main: 
	gcc -std=c99 -Wall -Werror ./$(SRC_DIR)/storage/main.c -o ./$(BUILD_DIR)/main


clean:
	rm -rf $(BUILD_DIR)/*

run:
	$(BUILD_DIR)/main

debug:
	@gdb -q \
		-iex 'set auto-load local-gdbinit on' \
		-iex 'set auto-load safe-path $$debugdir:$$datadir/auto-load:$(PWD)' \
		./$(BUILD_DIR)/main


