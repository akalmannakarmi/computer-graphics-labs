
build:
	gcc -o bin/$(name) $(name).c -lgraph -lm

run: build
	./$(name)

clean:
	rm