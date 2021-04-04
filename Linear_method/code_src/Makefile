CFLAGS=-c -g -std=gnu99
LDFLAGS=-lm

essai1: essai1.o pgm.o
	gcc $(LDFLAGS)  $^  -o $@

essai2: essai2.o pgm.o fft.o
	gcc $(LDFLAGS)  $^  -o $@

gaussien: gaussien.o pgm.o fft.o
	gcc $(LDFLAGS)  $^  -o $@

gaussienspatial: gaussienspatial.o pgm.o fft.o
	gcc $(LDFLAGS)  $^  -o $@
%.o:%.c
	gcc $(CFLAGS) $<

laplacien: laplacien.o pgm.o fft.o
	gcc $(LDFLAGS)  $^  -o $@

contour: contour1.o pgm.o fft.o
	gcc $(LDFLAGS)  $^  -o $@

contour2: contour2.o pgm.o fft.o
    gcc $(LDFLAGS)  $^  -o $@

complexite: complexite.o pgm.o fft.o
    gcc $(LDFLAGS)  $^  -o $@

test_contour2: test_contour2.o pgm.o fft.o
    gcc $(LDFLAGS)  $^  -o $@

test_contour1: test_contour1.o pgm.o fft.o
    gcc $(LDFLAGS)  $^  -o $@

test_gaussien: test_gaussien.o pgm.o fft.o
    gcc $(LDFLAGS)  $^  -o $@

test_gaussien_spatial: test_gaussien_spatial.o pgm.o fft.o
    gcc $(LDFLAGS)  $^  -o $@