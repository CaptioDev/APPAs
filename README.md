# Air Pressurized Particle Accelerator Simulator (APPAs)

## Overview
APPAs is an Air Pressurized Particle Accelerator simulator program written in C. It allows you to simulate the behavior of a particle accelerator, including adjusting particle energy, monitoring various properties, and visualizing the accelerator's status. This README provides instructions for building and running the simulator on your system.

### Table of Contents
- [Prerequisites](#prerequisites)
- [Building the Simulator](#building-the-simulator)
- [Running the Simulator](#running-the-simulator)
- [Usage](#usage)
- [File Permissions on Linux](#file-permissions-on-linux)
- [ASCII Representation](#ascii-representation)

## Prerequisites
Before running the simulator, make sure you have the following prerequisites installed on your system:
- C compiler (e.g., GCC)
- Make utility (optional but recommended)

## Building the Simulator
To build the simulator, follow these steps:
1. Open your terminal.
2. Navigate to the directory containing the source code files (e.g., `main.c`).
3. Run the following command to compile the simulator:
   ```shell
    gcc main.c -o accelerator_simulator.out -lm
This command will generate an executable file named accelerator_simulator.out.

Running the Simulator
To run the simulator, use the following command:

./accelerator_simulator.out

## Usage
Once the simulator is running, you can interact with it using various commands:

changeEnergy: Change the particle energy and type.
simulate: Simulate a time step for accelerator components.
status: View the current status of the accelerator.
exit: Exit the simulator.
File Permissions on Linux
If you encounter file permission issues when trying to run the simulator on Linux, you may need to change the file permissions using the chmod command. For example, to make the APPAs executable, use the following command:

chmod +x accelerator_simulator.out

## ASCII Representation
The simulator includes an ASCII representation of the APPA. You can find it in the source code file (main.c) within the printAPPA() function. Customize it as needed.

## Credits
This simulator was created by [PQAR].

## License
This simulator is open-source and released under the [PQAR Open-Source] license. See the LICENSE file for details.
