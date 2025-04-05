> output.txt

while read line; do
	result=$(echo "$line" | bc)
	echo "$result" >> output.txt
done < input.txt
