


-4/10/2024
While creating a 2d array through this method still helps use the index that i'm used to, which is a very big plus.
This creates a bigger issue; for instance, the amount of memory being occupied in dynamic memory in order to create
up to ten seperate arrays. There's also the amount of workload in order to access each index breaking down gameBoard[x][y]:
the compiler first evaluates gameBoard[x] to an array in position x and then given that array it evaluates arrayX[y] at location y.
This is a lot more tedious than what we usually deal with by using array objects. We also have to delete each row individually
once we are done instead of just deleting a single array. Of course since its just a simple game played in the terminal
this wont be terribly killing the laptop, but I would like to know a more efficient way of doing this for large scale problems. 