# ECE3413_Simulink_Library

This is the Matlab Simulink blocks created for Gear Motor with Encoder (https://www.pololu.com/product/2822), Dual MAX14870 Motor Driver Shield (https://www.pololu.com/product/2519), and DualVNH5019 MotorShield from Pololu (https://www.pololu.com/product/2507). It is used in a control course at Temple University. Please feel free to use for other projects.


However, channel A and B of an encoder cannot be connected to pins 2, 4, 6, 7, 8, 9, 10, 12 because they are used by the motor shield DualVNH5019. If you use Dual MAX14870 Motor Driver Shield, you need to avoid pins 4, 7, 8, 9, 10, 12 for the encoder.
