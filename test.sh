

make all

./sorter &
SERVER_PID=$!
echo Start server pid=$SERVER_PID

echo Testing ...

echo "5 4 3 2 1" > data.txt
./front_end

echo "10 9 8 7 6 5" > data.txt
./front_end

kill -s 9 $SERVER_PID