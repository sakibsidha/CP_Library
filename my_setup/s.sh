for((i = 1; ; ++i)); do
	echo $i
	./gen $i > in1
	./c < in1 > out1
	./brute < in1 > out2
	diff -w out1 out2 || break
done
