# CPSC-380-Assignment7
 
 * Some ideas I had are from the slides. Basically the scheduling algorithm is the disk arm going back and forth to access the cylinders. 

 * There are some great visuals of this on the slides here: https://canvas.chapman.edu/courses/44406/files/4171907?module_item_id=1505005 (this is ch11)

* Store all of the values from cylinders.txt in an array (size is the number of requests, this will be the queue)

* The value we are calculating is how far we travel when we move across a cylinder for example going from 156 to 136 is 20 cylinders moved
* I have already completed FCFS so it should be on there

* For the rest of the algorithms it is not as simple:
* We will need to create a method to sort the queue from least to greatest
* Once we have accessed a value, probably set that cylinder to -1 and to check if a cylinder request has been fulfilled, check if the cylinder is -1 (efficiency is not a requirement lol) (this applies to ssjf, scan, and c-scan in which we may pass over a cylinder that has been accessed)
