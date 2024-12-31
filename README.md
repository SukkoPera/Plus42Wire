# Plus42Wire
Plus42Wire is an I<sup>2</sup>C (Inter-Integrated Circuit, sometimes known as *2-Wire*) interface for the Commodore 16, 116 and Plus/4.

![Board](https://raw.githubusercontent.com/SukkoPera/Plus42Wire/master/img/render-top.png)

## Summary
I<sup>2</sup>C is a standard bus that is widely used for attaching lower-speed peripherals to processors, such as temperature/humidity/pressure sensors, real-time clocks, accelerometers, EEPROMs, ADCs and many more.

Plus42Wire is based on the PCF8584 chips by Philips/NXP, featuring both master and slave capabilities and communication speeds up to 90 kHz.

The board features both 5V and 3.3V bus connectors with different pinouts for maximum compatibility with devices and has built-in slots for an EEPROM and a real-time clock (RTC). Address decoding is performed by a GAL for easy reconfigurability (both GAL20 and GAL22 are supported).

## Assembly
The PCF8584 and all the other chips can all be bought supercheap on AliExpress & similar sites. There are only a couple of other components, making this board very affordable to build for everyone.

Be careful with the Q1/Q2 MOSFETs: these **MUST** be TN2106, get them from a reputable supplier. You can skip them if you are only interested in the 5V bus.

JP1 sets the built-in EEPROM to read-only mode when closed.

JP2 grounds pin 1 of the oscillator: most oscillators don't need this, so leave it open unless the datasheet of your oscillator says differently.

JP3/4/5 control the I<sup>2</sup>C address of the built-in EEPROM: most EEPROMs respond to 0x50 by default, but this address can be altered through these jumpers. Set them all to 0 to use the default.

JP6 connects the PCF8584 IRQ signal to the system IRQ signal: these two work differently so you **MUST** leave this jumper open. It is only provided for experimentation.

The battery is only needed by the RTC so that it keeps time while the board is unplugged. Speaking of the RTC, be careful if you get these from China as some of them just don't work at all.

Many different EEPROM chips are supported in the built-in slot: just make sure that the pinout matches and adapt your software.

## Programming
The board is generic and can be used for a multitude of purposes, but in all cases you will have to write some software on the computer side in order to interact with the devices.

The board exposes the two 8255 registers at $FE04/5. Interaction with these registers is a bit tricky and requires careful examination of the [datasheet](doc/PCF8584.pdf).

Some example code for interaction with the board, RTC and EEPROM is provided on the [Wiki](https://github.com/SukkoPera/Plus42Wire/wiki).

## Releases
If you want to get this board produced, you are recommended to get [the latest release](https://github.com/SukkoPera/Plus42Wire/releases) rather than the current git version, as the latter might be under development and is not guaranteed to be working.

Every release is accompanied by its Bill Of Materials (BOM) file and any relevant notes about it, which you are recommended to read carefully.

## License
The Plus42Wire documentation, including the design itself, is copyright &copy; SukkoPera 2024 and is licensed under the [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](https://creativecommons.org/licenses/by-nc-sa/4.0/).

This documentation is distributed *as is* and WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES whatsoever with respect to its functionality, operability or use, including, without limitation, any implied warranties OF MERCHANTABILITY, SATISFACTORY QUALITY, FITNESS FOR A PARTICULAR PURPOSE or infringement. We expressly disclaim any liability whatsoever for any direct, indirect, consequential, incidental or special damages, including, without limitation, lost revenues, lost profits, losses resulting from business interruption or loss of data, regardless of the form of action or legal theory under which the liability may be asserted, even if advised of the possibility or likelihood of such damages.

## Support the Project
If you want to get some boards manufactured, you can get them from PCBWay through this link:

[![PCB from PCBWay](https://www.pcbway.com/project/img/images/frompcbway.png)](https://www.pcbway.com/project/shareproject/Plus42Wire_V2_Intel_8255_Interface_for_the_Commodore_16_116_and_Plus_4_7e3afe66.html)

You get my gratitude and cheap, professionally-made and good quality PCBs, I get some credit that will help with this and [other projects](https://www.pcbway.com/project/member/shareproject/?bmbid=41100). You won't even have to worry about the various PCB options, it's all pre-configured for you!

Also, if you still have to register, [you can use this link](https://www.pcbway.com/setinvite.aspx?inviteid=41100) to get some bonus initial credit (and yield me some more).

You can also buy me a coffee if you want:

<a href='https://ko-fi.com/L3L0U18L' target='_blank'><img height='36' style='border:0px;height:36px;' src='https://az743702.vo.msecnd.net/cdn/kofi2.png?v=2' border='0' alt='Buy Me a Coffee at ko-fi.com' /></a>

## Thanks
* Chequered Ink for the [Helicopta](https://www.fontspace.com/helicopta-font-f27740) font used in the logo.
