# Pressure-sensor-26PC05SMT


<h2>The needed parts:</h2>

  * LM393P OpAmp    x1
  * 56Kohm resistor x2
  * 1Kohm resistor  x2
  * 20pF capacitor  x2
  * 100nF capacitor x1
  
<h2>How the code works:</h2>

 First, you have to set the analog offset of the circuit output from here when there no pressure on the sensor,
 Upload the code and open the serial monitor, watch the analog value until you see a stable number then copy it here:

```
  #define Pressure_Offset     21     //Analog reading value 
```

After that, you need to calibrate the sensor output depending on the pressure sensor that you have. 
In my case, I have a gauge pressure sensor that measures in mmHg, then connect both of the sensors to a pressure source like a small ball or a gas(AIR) gar or a compressor, For me, I've used an old gas gar that I already put a 1Bar of air inside it using a car compressor, Then you should apply a certain amount of pressure to both of the pressure sensors, Here I applied 100mmHg of pressure, while the pressure is increasing watch the serial monitor and the pressure sensor then get the voltage that the Arduino has measured(In my case 0.48v) and the applied pressure(In my case 100mmHg) then divide the pressure(100mmHg) by the measured voltage(0.48v) and replace the answer that you get here:
My result is:  100 / 0.48 = 208.33

```
  #define Pressure_Calib     208.33  //Calibration value depending on 100 mmHg readings from pressure sensor and the Arduino readings
```

<h2> Here the PCB of the circuit:</h2>
  
![3D view](SchematicPressureSensor/Circuit3DView.jpg)

<h2> Here the circuit schematic: </h2>
  
![SchematicPressureSensor](SchematicPressureSensor/Schematic_PressureCircuit_2020-06-06_21-59-30.png)
