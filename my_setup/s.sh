g++ gen.cpp -o gen
g++ brute.cpp -o brute
g++ c.cpp -o c

for((i = 1; ; ++i)); do
	echo $i
	./gen $i > in1
	./c < in1 > out1
	./brute < in1 > out2
	diff -w out1 out2 || break
done

echo "case:"
cat in1
echo "expected:"
cat out2
echo "got:"
cat out1
