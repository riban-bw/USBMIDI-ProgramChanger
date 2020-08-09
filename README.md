# USBMIDI-ProgramChanger

This project implements a class-compliant USB MIDI device that sends MIDI Progream Change to the host device, e.g. PC when a button is pressed. The button may be illuminated to indicate the last selected program. The low cost STM32F103C microcontroller.

Proposed features:

Feature | Status
------- | ------
USB MIDI interface | Implemented
Class complient MIDI interface | Implemented
Push button to send Program Change | Implemented
Indicate last selected program |TODO
Support multiple MIDI channels | TODO
Configure button action | TODO
Banks of buttons | TODO

Development is performed within the simple to use Arduino development environment with Roger Clark’s Arduino STM32 libraries. Installation is described [here](https://github.com/rogerclarkmelbourne/Arduino_STM32/wiki/Installation).

A LeafLabs MapleLeaf STM32 development board makes things easy to install but I use a Bluepill (or similar) development board which does not have the bootloader installed so must manually add a boot loader to ease development. This involves using an application to push firmware (or bootloader) to the STM32 whilst it is in DFU mode via a serial port. I am currently on a Windows laptop so used Flash Loader Demo which is available direct from ST (requiring free account) or other places on web host it.

- Download a bootloader firmware, e.g. https://github.com/TheKikGen/stm32-tkg-hid-bootloader/blob/master/F1/bootloader_only_binaries/tkg_hid_generic_pc13.bin
- Connect USB UART GND to STM32 GND
- Connect USB UART 3.3V to STM32 3.3V
- Connect USB UART Rx to STM32 A9
- Connect USB UART Tx to STM32 A10
- Set BOOT0 jumper
- Connect USB UART to PC
- Start “Flash Loader Demo”
  - Select USB UART port, 115200, Next
  - “Target is readable. Please click “Next” to proceed”, Next
  - Select correct Target, Next
  - Select “Download to device”, “Download from file”, @8000000, Next
- Clear BOOT0 jumper

Using this examples bootloader the Arduino configuration is:

- Follow these instructions to install Arduino IDE and Roger Clark’s Arduino STM32
(https://github.com/rogerclarkmelbourne/Arduino_STM32/wiki/Installation)
- Start Arduino IDE and select menu configurations:
  - Board: Generic STM32F103C series
  - Variant: STM32F103C8 (20k RAM. 64k Flash)
  - Upload method: HID bootloader 2.0

To upload firmware the STM32F103C must be in its bootloader stage. This occurs just after reset / powerup.
