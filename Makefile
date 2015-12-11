all: gera trab4 doc

all-nodoc: gera trab4

sorts: sorts.c
	gcc -Wall -c sorts.c

trab4: sorts.o main.c
	gcc -Wall -o trab4 sorts.o main.c

gera: gera.c
	gcc -Wall -o gera gera.c

doc: artigo.tex
	latexmk -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make artigo.tex

clean-nodoc:
	rm *.o gera trab4
	
clean:
	rm *.o gera trab4 artigo.pdf artigo.log artigo.fls artigo.aux artigo.fdb_latexmk artigo.idx artigo.ilg artigo.ind

