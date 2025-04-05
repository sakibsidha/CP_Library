echo -e "Welcome to OS Lab Calculator! \n"

for ((i = 1; ; ++i)); do
	echo "Type of Operation:"
	echo " 1. Addition"
	echo " 2. Substraction"
	echo " 3. Multiplication"
	echo " 4. Division"
	echo -e " 5. Close \n"
	read n
	if ((n == 5)); then
		break
	fi
	echo -e "Enter 2 numbers: "
	read a b
	if ((n == 1)); then
		echo -e "Result: $((a + b)) \n"
	elif ((n == 2)); then 
		echo -e "Result: $((a - b)) \n"
	elif ((n == 3)); then
		echo -e "Result: $((a * b)) \n"
	elif ((n == 4)); then
		echo -e "Result: $((a / b)) \n"
	else
		echo -e "Invalid Choice. \n"
	fi	
done	
