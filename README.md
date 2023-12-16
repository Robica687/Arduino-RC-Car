# Arduino-RC-Car
RC car that uses mecanum wheels and wireless connections

This project uses three arduino boards (tho unos for the car and one nano for the remote), two l298n motor drivers, 4 dc motors, three nrf24l01 trans-receivers, some buttons, baterry holders and wires. 

The two boards that are placed on the car are controlling two motors, the "receiver1" controls the front motors and the "receiver2" controls the back motors.
The nano board is using buttons to get the command that is transmitted to both of the boards in the car, in total i got 10 differend commands, each command transmitted to the car's boards makes the motors spin or stay inactive in different cases.

There are some physical problems with the code, such as the car is not very stable because it is plastic and maybe the weight is not evenly distributed, and some motors tend to not touch the ground as much as some others, also i got some problems on the wire connections, because i just started to use the letcon and i have some more to learn about how to use it correctly. Also, another problem is in the code, because i firstly used a cardnoard made chasis to support the electronics of the car, and i changed it to a plastic box, and so i inverted some wires and the code says that, for example, the pin x is for going forward but in reality is going backwards, and i fixed it by experimenting with the car connected and changing the code a bit (changing the high and low input) to make it work normally.

This is my first "bigger" project that uses some wireless connections and motor drivers, and i am happy with how it turned out, even if is not really perfect.
