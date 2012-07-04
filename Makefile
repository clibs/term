
test: test.c src/term.c
	$(CC) $^ -o $@

example: example.c src/term.c
	$(CC) -std=c99 $^ -o $@

.PHONY: test example