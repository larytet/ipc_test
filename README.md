
A simple server client with fielsystem based token.

A client application (front_end) opens file data.txt, reads integers, sends the integers to the server (sorter), creates a file "token".
The client wait for the sorter to remove the token file. The client prins the sorted data.
  
Sorter waits for a token file, reads the integers, sorts the integers, sends the sorted list back to the client, removes the token.


Build & run 


       ./test.sh