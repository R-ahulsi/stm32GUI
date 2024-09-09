This project is a C++ GUI application developed using the Qt framework and Qt Creator to interface with my STM32 microcontroller via UART and the STM32 command line interface. It is designed to help with the development and testing of my RTOS project.

**Motivation:**

The motivation behind this project was to create a tool for interfacing with my RTOS running on the STM32 microcontroller. Traditional serial terminal programs like RealTerm provided basic communication but lacked the tailored features required for a more integrated development and debugging process. This GUI application bridges that gap by enabling communication and flashing of the board.

**Project Overview:**

- Customized Serial Interface: The GUI acts as a customized alternative to serial terminal programs like RealTerm, allowing communication with the STM32 board through UART.

- File Upload and Programming: Integrates file upload capabilities with the STM32 command line interface, enabling users to easily transfer binaries for programming and debugging the board.

- Real-Time Logging: Provides a real-time logging interface that displays data received from the board via UART, aiding in monitoring and debugging during RTOS development.

- Dynamic Configuration: Allows dynamic configuration of the baud rate and serial port, providing flexibility in communication settings.

**Key Features:**

- Real-Time Data Logging: Displays real-time data from the STM32 board's UART, helping developers monitor the system's performance and debug issues effectively.

- File Upload Capability: Easily upload binary or ELF files to the STM32 board directly through the GUI, leveraging the STM32 command line interface for programming and debugging.

- Flexible Communication Settings: Configure baud rate and serial ports dynamically to match the specific needs of your STM32 setup.

- User-Friendly Interface: Built with Qt for a clean, intuitive user experience, reducing the learning curve for new users.

**Getting Started:**

Prerequisites: STM32_Programmer_CLI, needed for interacting with STM32 boards.

- Open Qt Creator and select the CMakeLists.txt file from the project directory to load the project.
- Build the Project: Use Qt Creator's build tools to compile the project.
- Run the Application: Once built, run the application directly from Qt Creator or as a standalone executable.

**Usage Instructions:**

- Selecting Serial Port: Use the dropdown menu to select the available serial port connected to your STM32 board.
- Configuring Baud Rate: Dynamically adjust the baud rate for communication as needed.
- Uploading Files: Navigate to the upload section to select and upload a binary or ELF file to the STM32 board.
- Monitoring Logs: View real-time logs in the dedicated logging area to monitor UART data and system messages.

**Future Work:**

- Enhanced Debugging Tools: Plan to display RTOS CPU utilization.
- Extended Compatibility: Broaden support for other microcontroller families and programming environments.
