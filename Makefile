
test: test.c src/term.c
	$(CC) $^ -o $@

.PHONY: test