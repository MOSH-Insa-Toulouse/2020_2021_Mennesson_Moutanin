# Kicad Practical TP / Communicating gas sensor

## KiCad - Shield for Arduino

### TODO Kicad

- [x] Create Kicad project
- [x] Design the circuit board
- [x] Assign the components footprints
- [x] Design of the pcb
- [x] Component placement
- [x] Routing

### Diagram
![image](https://github.com/MOSH-Insa-Toulouse/2020_2021_Mennesson_Moutanin/blob/main/KiCad/Illustrations/schematic.png)

### Placement and Routing
![image](https://github.com/MOSH-Insa-Toulouse/2020_2021_Mennesson_Moutanin/blob/main/KiCad/Illustrations/placement.png)
![image](https://github.com/MOSH-Insa-Toulouse/2020_2021_Mennesson_Moutanin/blob/main/KiCad/Illustrations/routingback.png)
![image](https://github.com/MOSH-Insa-Toulouse/2020_2021_Mennesson_Moutanin/blob/main/KiCad/Illustrations/routingfront.png)

### 3D View
![image](https://github.com/MOSH-Insa-Toulouse/2020_2021_Mennesson_Moutanin/blob/main/KiCad/Illustrations/viewfront.png)
![image](https://github.com/MOSH-Insa-Toulouse/2020_2021_Mennesson_Moutanin/blob/main/KiCad/Illustrations/viewback.png)

## Manufacturing and integration of nano-technology sensors

You'll find a datasheet related to the sensor we integrated under >A.I.M.E

## Analog Electronic Labs

The goal of this part was to simulate our sensor and its associated electronic diagram thanks to LTSpice. In order to obtain the cutoff frequencies of the different steps and observe the noise attenuations at 50kHz and at the Nyquist frequency.

### Electronic Diagram

![image](https://github.com/MOSH-Insa-Toulouse/2020_2021_Mennesson_Moutanin/blob/main/Analog_Electronic_LABs/Illustrations/diagram.png)

### Gas Sensor

![image](https://github.com/MOSH-Insa-Toulouse/2020_2021_Mennesson_Moutanin/blob/main/Analog_Electronic_LABs/Illustrations/sensor1.png)
![image](https://github.com/MOSH-Insa-Toulouse/2020_2021_Mennesson_Moutanin/blob/main/Analog_Electronic_LABs/Illustrations/sensor2.png)


### Characteristics

![image](https://github.com/MOSH-Insa-Toulouse/2020_2021_Mennesson_Moutanin/blob/main/Analog_Electronic_LABs/Illustrations/attenuation.png)


## Analog Electronic Labs

This part was focused on exploiting the data from the gas sensor. The idea was to interconnect several technologies; recover the data from the sensor using an arduino, process this data with the Arduino software, send it over the LoRa network, retrieve it on The Things Network, and finally display it on a dashboard thanks to a Node-Red flow.  

You'll find all the related files under >MOSH>LoRa_Small_Project

### Node-Red Flow Example (Temperature Data)

![image](https://github.com/MOSH-Insa-Toulouse/2020_2021_Mennesson_Moutanin/blob/main/MOSH/Illustrations/flow.png)

### Dashboard Example (Temperature Data)

![image](https://github.com/MOSH-Insa-Toulouse/2020_2021_Mennesson_Moutanin/blob/main/MOSH/Illustrations/Dashboard.png)

## Contribution

### Students 

* Baptiste MENNESSON
* Brice MOUTANIN

### Tutors

* Jérémie GRISOLIA
* Arnauld BIGANZOLI 
* Benjamin MESTRE