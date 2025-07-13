# LPC2148 ADC UART LCD Display Project

This project demonstrates how to read ADC values using the LPC2148 microcontroller, send the values over UART, and display the data on a 16x2 LCD using 4-bit mode. It includes the use of UART interrupts for efficient data handling.

---

## 🔧 Features

- Reads analog input using the internal ADC
- Sends ADC data over UART serial communication
- Receives ADC data using UART interrupt
- Displays real-time ADC values on 16x2 LCD
- Uses 4-bit mode for LCD interfacing
- Includes PLL configuration for setting up the system clock

---

## 📁 Folder Structure

.
├── main_tx.c # Transmitter code (reads ADC and sends via UART)
├── main_rx.c # Receiver code (reads UART and displays on LCD)
├── ADC.h # ADC initialization and read functions
├── UART.h # UART init and transmission
├── Lcd_4bit.h # 4-bit LCD control and display functions
├── PLL.h # PLL setup for 60MHz clock
└── README.md # This file


---

## 📡 Hardware Requirements

- LPC2148 Development Board
- 16x2 LCD display
- Potentiometer or analog sensor (connected to ADC channel)
- UART-to-USB converter (for serial monitoring)
- Power supply or USB

---

## 🔌 Pin Connections

| Peripheral | LPC2148 Pin     | Description                |
|------------|------------------|----------------------------|
| LCD        | P0.0 - P0.7      | Data + Control Pins        |
| ADC        | P0.28 (AD0.2)    | Analog Input               |
| UART       | P0.0, P0.1       | UART0 TX and RX            |

---

## ⚙️ How It Works

- **Transmitter (`main_tx.c`)**:
  - Initializes ADC, UART, PLL, and LCD.
  - Reads analog voltage from ADC channel AD0.2.
  - Converts the ADC value to a 4-digit number.
  - Sends ADC data over UART with a header character (e.g., `':'`).
  
- **Receiver (`main_rx.c`)**:
  - Uses UART interrupt to read incoming ADC data.
  - Stores and converts the received string to integer.
  - Displays the result on an LCD screen.




---

## 📜 License

This project is open-source and free to use for academic and personal learning purposes.

---

## 🙌 Credits

Developed by Sanket Mali  
Microcontroller: NXP LPC2148 (ARM7TDMI-S)

