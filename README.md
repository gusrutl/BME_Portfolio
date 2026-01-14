
## About Me

I'm a junior Biomedical Engineering Student in the Lampe Joint Department of Biomedical Engineering at UNC and NCSU. 

- Specializing in Medical Microdevices and Rehabilitation Engineering
- Minoring in Neuroscience
- Researching neural engineering to generate artificial sensations with spinal cord stimulation



## Projects

### 1. Electromyogram Device
<div style="display: flex; flex-wrap: wrap; gap: 10px;">
  <img src="./EMG_Presentation.png" width="45%">
  <img src="./EMG_PCB.png" width="45%">
  <img src="./EMGSchematic.png" width="45%">
  <img src="./EMGCircuit.png" width="45%">
</div>

- This circuit is responsible for reading the voltage across my bicep muscle, allowing the attached microcontroller to close or splay the prosthetic fingers depending on the strength of muscle contraction
- C++ code for scaling EMG circuit output to control prosthetic hand movement:
  - [Download Code](./EMGSignalProcessing.ino)

- The circuit contains:
  -  two differential amplifier op-amp circuits with a total gain of ~1500 
  -  a bandpass filter to remove unnecessary noise from the biosignals
  -  a rectifier to convert the noisy AC signal to DC
  - a final lowpass filter to smooth the output signal sent to the microcontroller
  - Voltage output to a microcontroller between 0-2.5 V 
    

### 2. Modeling Medtronic Spinal Cord Stimulator
<img src="./Medtronic External SCS.png" alt="Project Screenshot" width="500">

#### Attached File:
[Download External Spinal Cord Stimulator Model](./External%20Spinal%20Cord%20Stimulator.step)

### 3. Modeling Endotracheal Tube
<img src="./Endotracheal Tube.png" alt="Project Screenshot" width="500">

#### Attached File:
[Download Endotracheal Tube Model](./Endotracheal%20Tube.step)



## Contact

Feel free to reach out at:

- Email: gus.e.rutledge@gmail.com | gusrutl@unc.edu
- LinkedIn: www.linkedin.com/in/gus-rutledge-2a171b23b


