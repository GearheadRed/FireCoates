FireCoates
==========
Firmware for the jacket module and bike module. The rest of the project can be found on hackaday.io at http://hackaday.io/project/1163-FireCoates

BikeModule.ino contains firmware for determining which signal lights are illuminated on the bike, and sending that information to the jacket module.
	Written using an Arduino Nano v3 and Virtuabotix BT2S-M Bluetooth to Serial Master
JacketModule.ino contains the firmware for receiving input from the bike module and for jacket light signalling.
	Written using an Arduino Fio and SainSmart Bee Bluetooth Slave
	
BikeModuleWiring.jpg is a very basic diagram for how to wire up the bike module.
JacketModuleWiring.jpg is a very basic diagram for how to wire up the jacket module.

BasicJacketModuleCase Directory
	JacketModuleBase.stl bottom portion of a basic 3d printed case for the jacket module
	JacketModuleTop.stl top cover for the 3d printed jacket module case

To do:
	Bike module:
		Split light channels into individual lines for left, right, and brake, eliminate signal processing
		Improve code for efficiency
	Jacket module:
		Expand code to handle left, right, and brake channels and logic to determine what output channels are set high and low instead of bike module
		Add additional outputs for multicolor processing.
		Improve code for efficiency and battery life management.
