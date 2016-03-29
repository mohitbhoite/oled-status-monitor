# OLED Status monitor for the Particle Electron

Sometimes it's nice to monitor the status of your Electron without having to loop that information through the interwebs.This example shows you how to use an OLED screen (available with the Particle maker-kit) to display this information. You can monitor things like:

 - Battery Voltage
 - State of Charge
 - Signal Strength

### Things you'll need:

 - Electron
 - OLED Display
 - Breadboard
 - Breadboard Wires
 - USB power source and/or LiPo battery

### Setup:

Hook up the OLED to the Electron as shown below. We are using the OLED in the SPI mode, but this should also work for displays that support I2C mode.

### Software:

The firmware uses Adafruit's SSD1306 display library. Since Electron is a data sensitive device, this example assumes offline development. Here is a link to how to compile and flash your source code locally to the Electron.

Checkout the develop branch of the Particle firmware repository and create a new folder under `firmware/user/applications/`. Let us name it oled. Now navigate to `firmware/modules` and use the following command to rebuild your code base:

(this command assumes you are in the develop branch on the particle firmware repository.)

```bash
make clean all PLATFORM=electron APP=oled DEBUG_BUILD=y DEBUG=1 PARTICLE_DEVELOP=1 program-dfu
```

**Note:** Before executing the above command, make sure your Electron is in DFU mode and connected to your computer!

This command will rebuild the entire source code and flash the binaries in three chunks, system part 1, system part 2 and the user app. In subsequent builds, you don't have to recompile everything. Simply navigate to firmware/main and use the same command - this will only flash the user app binary.
