for ((i = 0; i < 5; i++)); do
    echo "Iteration $i"
done
----------
count=0
while [ $count -lt 5 ]; do
    echo "Count is $count"
    ((count++))
done
-----------
num=0
until [ $num -ge 5 ]; do
    echo "Number is $num"
    ((num++))
done
