/*
  Force Feedback Joystick
  USB HID descriptors for a force feedback joystick.  
  Copyright 2012  Tero Loimuneva (tloimu [at] gmail [dot] com)
  Copyright 2016  Jaka Simonic (telesimke [at] gmail [dot] com)
  Copyright 2019  Hoan Tran (tranvanhoan206 [at] gmail [dot] com)
  MIT License.
  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.
  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/
#ifndef FFBWHEELDESCRIPTOR_H
#define FFBWHEELDESCRIPTOR_H

#define HID_REPORTID_WHEEL 0x01
static const uint8_t _hidReportDescriptor[] PROGMEM = {
	0x05, 0x01,	// USAGE_PAGE (Generic Desktop)
	0x09, 0x04,	// USAGE (Joystick) 
	0xA1, 0x01,	// COLLECTION (Application)
		//================================Input Report======================================//
		0x09, 0x01, // USAGE (Pointer)		
		// WheelReport
		0x85, HID_REPORTID_WHEEL,	// REPORT_ID (1)
		0xA1, 0x00, // COLLECTION (Physical)
			// Button for Shifter
			0x05, 0x09, // USAGE_PAGE  (Button) 
			0x19, 0x01,	// USAGE_MINIMUM (Button 1)
			0x29, 0x08, // USAGE_MAXIMUM (Button 8) 
			0x15, 0x00,	// LOGICAL_MINIMUM (0) 
			0x25, 0x01,	// LOGICAL_MAXIMUM (1)
			0x75, 0x01,	// REPORT_SIZE (1)
			0x95, 0x08,	// REPORT_COUNT (8)
			0x81, 0x02,	//INPUT (Data,Var,Abs)
			
			//6 Axis for steering wheel, accelerator, brake, clutch, handbrake and spare
			0x05, 0x01,	// USAGE_PAGE (Generic Desktop)
			0xa1, 0x00,	// COLLECTION (Physical)
				0x09, 0x30,	// USAGE (X)
				0x09, 0x31,	// USAGE (Y)
				0x09, 0x33,	// USAGE (Rx) 
				0x09, 0x34,	// USAGE (Ry) 
				0x09, 0x32,	// USAGE (Z)
				0x09, 0x35,	// USAGE (Rz) */
				0x16, 0x00, 0x80, //LOGICAL_MINIMUM (-32768)
				0x26, 0xFF, 0x7F, //LOGICAL_MAXIMUM (32767) 
				0x75, 0x10,	// REPORT_SIZE (16)
				0x95, 0x06,	// REPORT_COUNT (6)
				0x81, 0x02,	// INPUT (Data,Var,Abs) 
			0xc0, // END_COLLECTION */
		0xc0, // END_COLLECTION */
			
		// PIDStateReport			
		0x05,0x0F,	// USAGE_PAGE (Physical Interface)
		0x09,0x92,	// USAGE (PID State Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x02,	// REPORT_ID (02)
			0x09,0x9F,	// USAGE (Device Paused)
			0x09,0xA0,	// USAGE (Actuators Enabled)
			0x09,0xA4,	// USAGE (Safety Switch)
			0x09,0xA5,	// USAGE (Actuator Override Switch)
			0x09,0xA6,	// USAGE (Actuator Power)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x25,0x01,	// LOGICAL_MINIMUM (01)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x45,0x01,	// PHYSICAL_MAXIMUM (01)
			0x75,0x01,	// REPORT_SIZE (01)
			0x95,0x05,	// REPORT_COUNT (05)
			0x81,0x02,	// INPUT (Data,Var,Abs)
			0x95,0x03,	// REPORT_COUNT (03)
			0x81,0x03,	// INPUT (Constant,Var,Abs)
			0x09,0x94,	// USAGE (Effect Playing)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x25,0x01,	// LOGICAL_MAXIMUM (01)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x45,0x01,	// PHYSICAL_MAXIMUM (01)
			0x75,0x01,	// REPORT_SIZE (01)
			0x95,0x01,	// REPORT_COUNT (01)
			0x81,0x02,	// INPUT (Data,Var,Abs)
			0x09,0x22,	// USAGE (Effect Block Index)
			0x15,0x01,	// LOGICAL_MINIMUM (01)
			0x25,0x28,	// LOGICAL_MAXIMUM (28)
			0x35,0x01,	// PHYSICAL_MINIMUM (01)
			0x45,0x28,	// PHYSICAL_MAXIMUM (28)
			0x75,0x07,	// REPORT_SIZE (07)
			0x95,0x01,	// REPORT_COUNT (01)
			0x81,0x02,	// INPUT (Data,Var,Abs)
		0xC0,	// END COLLECTION ()
		
		//================================OutputReport======================================//
		
		// SetEffectReport
		0x09,0x21,	// USAGE (Set Effect Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x01,	// REPORT_ID (01)
			0x09,0x22,	// USAGE (Effect Block Index)
			0x15,0x01,	// LOGICAL_MINIMUM (01)
			0x25,0x28,	// LOGICAL_MAXIMUM (28)
			0x35,0x01,	// PHYSICAL_MINIMUM (01)
			0x45,0x28,	// PHYSICAL_MAXIMUM (28)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x25,	// USAGE (25)
			0xA1,0x02,	// COLLECTION (Logical)
				0x09,0x26,	// USAGE (26)
				0x09,0x27,	// USAGE (27)
				0x09,0x30,	// USAGE (30)
				0x09,0x31,	// USAGE (31)
				0x09,0x32,	// USAGE (32)
				0x09,0x33,	// USAGE (33)
				0x09,0x34,	// USAGE (34)
				0x09,0x40,	// USAGE (40)
				0x09,0x41,	// USAGE (41)
				0x09,0x42,	// USAGE (42)
				0x09,0x43,	// USAGE (43)
				0x09,0x28,	// USAGE (28)
				0x25,0x0C,	// LOGICAL_MAXIMUM (0C)
				0x15,0x01,	// LOGICAL_MINIMUM (01)
				0x35,0x01,	// PHYSICAL_MINIMUM (01)
				0x45,0x0C,	// PHYSICAL_MAXIMUM (0C)
				0x75,0x08,	// REPORT_SIZE (08)
				0x95,0x01,	// REPORT_COUNT (01)
				0x91,0x00,	// OUTPUT (Data)
			0xC0,	// END COLLECTION ()
			
			0x09,0x50,	// USAGE (Duration)
			0x09,0x54,	// USAGE (Trigger Repeat Interval)
			0x09,0x51,	// USAGE (Sample Period)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x26,0xFF,0x7F,	// LOGICAL_MAXIMUM (7F FF)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x46,0xFF,0x7F,	// PHYSICAL_MAXIMUM (7F FF)
			0x66,0x03,0x10,	// UNIT (Eng Lin:Time)
			0x55,0xFD,	// UNIT_EXPONENT (-3)
			0x75,0x10,	// REPORT_SIZE (10)
			0x95,0x03,	// REPORT_COUNT (03)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x55,0x00,	// UNIT_EXPONENT (00)
			0x66,0x00,0x00,	// UNIT (None)
			
			0x09,0x52,	// USAGE (Gain)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x26,0xFF,0x00,	// LOGICAL_MAXIMUM (00 FF)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x46,0x10,0x27,	// PHYSICAL_MAXIMUM (10000)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			
			0x09,0x53,	// USAGE (Trigger Button)
			0x15,0x01,	// LOGICAL_MINIMUM (01)
			0x25,0x08,	// LOGICAL_MAXIMUM (08)
			0x35,0x01,	// PHYSICAL_MINIMUM (01)
			0x45,0x08,	// PHYSICAL_MAXIMUM (08)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			
			0x09,0x55,	// USAGE (Axes Enable)
			0xA1,0x02,	// COLLECTION (Logical)
				0x05,0x01,	// USAGE_PAGE (Generic Desktop)
				0x09,0x30,	// USAGE (X)
				//0x09,0x31,	// USAGE (Y)
				0x15,0x00,	// LOGICAL_MINIMUM (00)
				0x25,0x01,	// LOGICAL_MAXIMUM (01)
				0x75,0x01,	// REPORT_SIZE (01)
				0x95,0x01,	// REPORT_COUNT (01)
				0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0xC0,	// END COLLECTION ()
			
			0x05,0x0F,	// USAGE_PAGE (Physical Interface)
			0x09,0x56,	// USAGE (Direction Enable)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x95,0x06,	// REPORT_COUNT (06)
			0x91,0x03,	// OUTPUT (Constant,Var,Abs)
			
			0x09,0x57,	// USAGE (Direction)
			0xA1,0x02,	// COLLECTION (Logical)
				0x0B,0x01,0x00,0x0A,0x00,
				0x0B,0x02,0x00,0x0A,0x00,
				0x66,0x14,0x00,	// UNIT (Eng Rot:Angular Pos)
				0x55,0xFE,	// UNIT_EXPONENT (FE)
				0x15,0x00,	// LOGICAL_MINIMUM (00)
				0x26,0xB4,0x00,	// LOGICAL_MAXIMUM (00 B4)
				0x35,0x00,	// PHYSICAL_MINIMUM (00)
				0x47,0xA0,0x8C,0x00,0x00,	// PHYSICAL_MAXIMUM (00 00 8C A0)
				0x66,0x00,0x00,	// UNIT (None)
				0x75,0x08,	// REPORT_SIZE (08)
				0x95,0x01,	// REPORT_COUNT (01)
				0x91,0x02,	// OUTPUT (Data,Var,Abs)
				0x55,0x00,	// UNIT_EXPONENT (00)
				0x66,0x00,0x00,	// UNIT (None)
			0xC0,	// END COLLECTION ()
			
			0x05,0x0F,	// USAGE_PAGE (Physical Interface)
	//		0x09,0xA7,	// USAGE (Start Delay)
			0x66,0x03,0x10,	// UNIT (Eng Lin:Time)
			0x55,0xFD,	// UNIT_EXPONENT (-3)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x26,0xFF,0x7F,	// LOGICAL_MAXIMUM (7F FF)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x46,0xFF,0x7F,	// PHYSICAL_MAXIMUM (7F FF)
			0x75,0x10,	// REPORT_SIZE (10)
			0x95,0x01,	// REPORT_COUNT (01)
	//		0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x66,0x00,0x00,	// UNIT (None)
			0x55,0x00,	// UNIT_EXPONENT (00)
		0xC0,	// END COLLECTION ()

		// SetEnvelopeReport	
		0x05,0x0F,	// USAGE_PAGE (Physical Interface)
		0x09,0x5A,	// USAGE (Set Envelope Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x02,	// REPORT_ID (02)
			0x09,0x22,	// USAGE (Effect Block Index)
			0x15,0x01,	// LOGICAL_MINIMUM (01)
			0x25,0x28,	// LOGICAL_MAXIMUM (28)
			0x35,0x01,	// PHYSICAL_MINIMUM (01)
			0x45,0x28,	// PHYSICAL_MAXIMUM (28)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x5B,	// USAGE (Attack Level)
			0x09,0x5D,	// USAGE (Fade Level)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x26,0xFF,0x00,	// LOGICAL_MAXIMUM (00 FF)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x46,0x10,0x27,	// PHYSICAL_MAXIMUM (10000)
			0x95,0x02,	// REPORT_COUNT (02)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x5C,	// USAGE (5C)
			0x09,0x5E,	// USAGE (5E)
			0x66,0x03,0x10,	// UNIT (Eng Lin:Time)
			0x55,0xFD,	// UNIT_EXPONENT (-3)
			0x26,0xFF,0x7F,	// LOGICAL_MAXIMUM (7F FF)
			0x46,0xFF,0x7F,	// PHYSICAL_MAXIMUM (7F FF)
			0x75,0x10,	// REPORT_SIZE (10)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x45,0x00,	// PHYSICAL_MAXIMUM (00)
			0x66,0x00,0x00,	// UNIT (None)
			0x55,0x00,	// UNIT_EXPONENT (00)
		0xC0,	// END COLLECTION ()
		
		// SetConditionReport
		0x09,0x5F,	// USAGE (Set Condition Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x03,	// REPORT_ID (03)
			0x09,0x22,	// USAGE (Effect Block Index)
			0x15,0x01,	// LOGICAL_MINIMUM (01)
			0x25,0x28,	// LOGICAL_MAXIMUM (28)
			0x35,0x01,	// PHYSICAL_MINIMUM (01)
			0x45,0x28,	// PHYSICAL_MAXIMUM (28)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x23,	// USAGE (Parameter Block Offset)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x25,0x01,	// LOGICAL_MAXIMUM (01)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x45,0x01,	// PHYSICAL_MAXIMUM (01)
			0x75,0x04,	// REPORT_SIZE (04)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x58,	// USAGE (Type Specific Block Offset)
			0xA1,0x02,	// COLLECTION (Logical)
				0x0B,0x01,0x00,0x0A,0x00,	// USAGE (Instance 1)
				0x0B,0x02,0x00,0x0A,0x00,	// USAGE (Instance 2)
				0x75,0x02,	// REPORT_SIZE (02)
				0x95,0x02,	// REPORT_COUNT (02)
				0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0xC0,	// END COLLECTION ()
			0x15,0x80,	// LOGICAL_MINIMUM (80)
			0x25,0x7F,	// LOGICAL_MAXIMUM (7F)
			0x36,0xF0,0xD8,	// PHYSICAL_MINIMUM (-10000)
			0x46,0x10,0x27,	// PHYSICAL_MAXIMUM (10000)
			0x09,0x60,	// USAGE (CP Offset)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x36,0xF0,0xD8,	// PHYSICAL_MINIMUM (-10000)
			0x46,0x10,0x27,	// PHYSICAL_MAXIMUM (10000)
			0x09,0x61,	// USAGE (Positive Coefficient)
			0x09,0x62,	// USAGE (Negative Coefficient)
			0x95,0x02,	// REPORT_COUNT (02)	
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x26,0xFF,0x00,	// LOGICAL_MAXIMUM (00 FF)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x46,0x10,0x27,	// PHYSICAL_MAXIMUM (10000)
			0x09,0x63,	// USAGE (Positive Saturation)
			0x09,0x64,	// USAGE (Negative Saturation)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x02,	// REPORT_COUNT (02)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x65,	// USAGE (Dead Band )
			0x46,0x10,0x27,	// PHYSICAL_MAXIMUM (10000)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
		0xC0,	// END COLLECTION ()	

		// SetPeriodicReport
		
		0x09,0x6E,	// USAGE (Set Periodic Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x04,	// REPORT_ID (04)
			0x09,0x22,	// USAGE (Effect Block Index)
			0x15,0x01,	// LOGICAL_MINIMUM (01)
			0x25,0x28,	// LOGICAL_MAXIMUM (28)
			0x35,0x01,	// PHYSICAL_MINIMUM (01)
			0x45,0x28,	// PHYSICAL_MAXIMUM (28)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x70,	// USAGE (Magnitude)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x26,0xFF,0x00,	// LOGICAL_MAXIMUM (00 FF)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x46,0x10,0x27,	// PHYSICAL_MAXIMUM (10000)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x6F,	// USAGE (Offset)
			0x15,0x80,	// LOGICAL_MINIMUM (80)
			0x25,0x7F,	// LOGICAL_MAXIMUM (7F)
			0x36,0xF0,0xD8,	// PHYSICAL_MINIMUM (-10000)
			0x46,0x10,0x27,	// PHYSICAL_MAXIMUM (10000)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x71,	// USAGE (Phase)
			0x66,0x14,0x00,	// UNIT (Eng Rot:Angular Pos)
			0x55,0xFE,	// UNIT_EXPONENT (FE)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x26,0xFF,0x00,	// LOGICAL_MAXIMUM (00 FF)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x47,0xA0,0x8C,0x00,0x00,	// PHYSICAL_MAXIMUM (00 00 8C A0)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x72,	// USAGE (Period)
			0x26,0xFF,0x7F,	// LOGICAL_MAXIMUM (7F FF)
			0x46,0xFF,0x7F,	// PHYSICAL_MAXIMUM (7F FF)
			0x66,0x03,0x10,	// UNIT (Eng Lin:Time)
			0x55,0xFD,	// UNIT_EXPONENT (-3)
			0x75,0x10,	// REPORT_SIZE (10)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x66,0x00,0x00,	// UNIT (None)
			0x55,0x00,	// UNIT_EXPONENT (00)
		0xC0,	// END COLLECTION ()
		
		// SetConstantForceReport
		0x09,0x73,	// USAGE (Set Constant Force Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x05,	// REPORT_ID (05)
			0x09,0x22,	// USAGE (Effect Block Index)
			0x15,0x01,	// LOGICAL_MINIMUM (01)
			0x25,0x28,	// LOGICAL_MAXIMUM (28)
			0x35,0x01,	// PHYSICAL_MINIMUM (01)
			0x45,0x28,	// PHYSICAL_MAXIMUM (28)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x70,	// USAGE (Magnitude)
			0x16,0x01,0xFF,	// LOGICAL_MINIMUM (-255)
			0x26,0xFF,0x00,	// LOGICAL_MAXIMUM (255)
			0x36,0xF0,0xD8,	// PHYSICAL_MINIMUM (-10000)
			0x46,0x10,0x27,	// PHYSICAL_MAXIMUM (10000)
			0x75,0x10,	// REPORT_SIZE (10)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
		0xC0,	// END COLLECTION ()
		
		// SetRampForceReport
		0x09,0x74,	// USAGE (Set Ramp Force Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x06,	// REPORT_ID (06)
			0x09,0x22,	// USAGE (Effect Block Index)
			0x15,0x01,	// LOGICAL_MINIMUM (01)
			0x25,0x28,	// LOGICAL_MAXIMUM (28)
			0x35,0x01,	// PHYSICAL_MINIMUM (01)
			0x45,0x28,	// PHYSICAL_MAXIMUM (28)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x75,	// USAGE (Ramp Start)
			0x09,0x76,	// USAGE (Ramp End)
			0x15,0x80,	// LOGICAL_MINIMUM (-128)
			0x25,0x7F,	// LOGICAL_MAXIMUM (127)
			0x36,0xF0,0xD8,	// PHYSICAL_MINIMUM (-10000)
			0x46,0x10,0x27,	// PHYSICAL_MAXIMUM (10000)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x02,	// REPORT_COUNT (02)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
		0xC0,	// END COLLECTION ()
		
		// CustomForceDataReport
		0x09,0x68,	// USAGE (Custom Force Data Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x07,	// REPORT_ID (07)
			0x09,0x22,	// USAGE (Effect Block Index)
			0x15,0x01,	// LOGICAL_MINIMUM (01)
			0x25,0x28,	// LOGICAL_MAXIMUM (28)
			0x35,0x01,	// PHYSICAL_MINIMUM (01)
			0x45,0x28,	// PHYSICAL_MAXIMUM (28)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x6C,	// USAGE (Custom Force Data Offset)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x26,0x10,0x27,	// LOGICAL_MAXIMUM (10000)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x46,0x10,0x27,	// PHYSICAL_MAXIMUM (10000)
			0x75,0x10,	// REPORT_SIZE (10)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x69,	// USAGE (Custom Force Data)
			0x15,0x81,	// LOGICAL_MINIMUM (-127)
			0x25,0x7F,	// LOGICAL_MAXIMUM (127)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x46,0xFF,0x00,	// PHYSICAL_MAXIMUM (255)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x0C,	// REPORT_COUNT (0C)
			0x92,0x02,0x01,	// OUTPUT ( Data,Var,Abs,Buf)
		0xC0,	// END COLLECTION ()
		
		// DownloadForceSample		
		0x09,0x66,	// USAGE (Download Force Sample)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x08,	// REPORT_ID (08)
			0x05,0x01,	// USAGE_PAGE (Generic Desktop)
			0x09,0x30,	// USAGE (X)
			0x09,0x31,	// USAGE (Y)
			0x15,0x81,	// LOGICAL_MINIMUM (-127)
			0x25,0x7F,	// LOGICAL_MAXIMUM (127)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x46,0xFF,0x00,	// PHYSICAL_MAXIMUM (255)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x02,	// REPORT_COUNT (02)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
		0xC0,	// END COLLECTION ()
		
		// EffectOperationReport
		0x05,0x0F,	// USAGE_PAGE (Physical Interface)
		0x09,0x77,	// USAGE (Effect Operation Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x0A,	// REPORT_ID (0A)
			0x09,0x22,	// USAGE (Effect Block Index)
			0x15,0x01,	// LOGICAL_MINIMUM (01)
			0x25,0x28,	// LOGICAL_MAXIMUM (28)
			0x35,0x01,	// PHYSICAL_MINIMUM (01)
			0x45,0x28,	// PHYSICAL_MAXIMUM (28)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x78,	// USAGE (78)
			0xA1,0x02,	// COLLECTION (Logical)
				0x09,0x79,	// USAGE (Op Effect Start)
				0x09,0x7A,	// USAGE (Op Effect Start Solo)
				0x09,0x7B,	// USAGE (Op Effect Stop)
				0x15,0x01,	// LOGICAL_MINIMUM (01)
				0x25,0x03,	// LOGICAL_MAXIMUM (03)
				0x75,0x08,	// REPORT_SIZE (08)
				0x95,0x01,	// REPORT_COUNT (01)
				0x91,0x00,	// OUTPUT (Data,Ary,Abs)
			0xC0,	// END COLLECTION ()
			0x09,0x7C,	// USAGE (Loop Count)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x26,0xFF,0x00,	// LOGICAL_MAXIMUM (00 FF)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x46,0xFF,0x00,	// PHYSICAL_MAXIMUM (00 FF)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
		0xC0,	// END COLLECTION ()
		
		// PIDBlockFreeReport 
		0x09,0x90,	// USAGE (PID Block Free Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x0B,	// REPORT_ID (0B)
			0x09,0x22,	// USAGE (Effect Block Index)
			0x25,0x28,	// LOGICAL_MAXIMUM (28)
			0x15,0x01,	// LOGICAL_MINIMUM (01)
			0x35,0x01,	// PHYSICAL_MINIMUM (01)
			0x45,0x28,	// PHYSICAL_MAXIMUM (28)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
		0xC0,	// END COLLECTION ()
		
		//PIDDeviceControl
		0x09,0x96,	// USAGE (PID Device Control)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x0C,	// REPORT_ID (0C)
			0x09,0x97,	// USAGE (DC Enable Actuators)
			0x09,0x98,	// USAGE (DC Disable Actuators)
			0x09,0x99,	// USAGE (DC Stop All Effects)
			0x09,0x9A,	// USAGE (DC Device Reset)
			0x09,0x9B,	// USAGE (DC Device Pause)
			0x09,0x9C,	// USAGE (DC Device Continue)
			0x15,0x01,	// LOGICAL_MINIMUM (01)
			0x25,0x06,	// LOGICAL_MAXIMUM (06)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x00,	// OUTPUT (Data)
		0xC0,	// END COLLECTION ()
		
		// DeviceGainReport
		0x09,0x7D,	// USAGE (Device Gain Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x0D,	// REPORT_ID (0D)
			0x09,0x7E,	// USAGE (Device Gain)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x26,0xFF,0x00,	// LOGICAL_MAXIMUM (00 FF)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x46,0x10,0x27,	// PHYSICAL_MAXIMUM (10000)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
		0xC0,	// END COLLECTION ()
		
		//SetCustomForceReport
		0x09,0x6B,	// USAGE (Set Custom Force Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x0E,	// REPORT_ID (0E)
			0x09,0x22,	// USAGE (Effect Block Index)
			0x15,0x01,	// LOGICAL_MINIMUM (01)
			0x25,0x28,	// LOGICAL_MAXIMUM (28)
			0x35,0x01,	// PHYSICAL_MINIMUM (01)
			0x45,0x28,	// PHYSICAL_MAXIMUM (28)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x6D,	// USAGE (Sample Count)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x26,0xFF,0x00,	// LOGICAL_MAXIMUM (00 FF)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x46,0xFF,0x00,	// PHYSICAL_MAXIMUM (00 FF)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x09,0x51,	// USAGE (Sample Period)
			0x66,0x03,0x10,	// UNIT (Eng Lin:Time)
			0x55,0xFD,	// UNIT_EXPONENT (-3)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x26,0xFF,0x7F,	// LOGICAL_MAXIMUM (32767)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x46,0xFF,0x7F,	// PHYSICAL_MAXIMUM (32767)
			0x75,0x10,	// REPORT_SIZE (10)
			0x95,0x01,	// REPORT_COUNT (01)
			0x91,0x02,	// OUTPUT (Data,Var,Abs)
			0x55,0x00,	// UNIT_EXPONENT (00)
			0x66,0x00,0x00,	// UNIT (None)
		0xC0,	// END COLLECTION ()
		
		//=========================================FeatureReport======================================//
		
		//CreateNewEffectReport
		0x09,0xAB,	// USAGE (Create New Effect Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x05,	// REPORT_ID (05)
			0x09,0x25,	// USAGE (Effect Type)
			0xA1,0x02,	// COLLECTION (Logical)
				0x09,0x26,	// USAGE (26)
				0x09,0x27,	// USAGE (27)
				0x09,0x30,	// USAGE (30)
				0x09,0x31,	// USAGE (31)
				0x09,0x32,	// USAGE (32)
				0x09,0x33,	// USAGE (33)
				0x09,0x34,	// USAGE (34)
				0x09,0x40,	// USAGE (40)
				0x09,0x41,	// USAGE (41)
				0x09,0x42,	// USAGE (42)
				0x09,0x43,	// USAGE (43)
				0x09,0x28,	// USAGE (28)
				0x25,0x0C,	// LOGICAL_MAXIMUM (0C)
				0x15,0x01,	// LOGICAL_MINIMUM (01)
				0x35,0x01,	// PHYSICAL_MINIMUM (01)
				0x45,0x0C,	// PHYSICAL_MAXIMUM (0C)
				0x75,0x08,	// REPORT_SIZE (08)
				0x95,0x01,	// REPORT_COUNT (01)
				0xB1,0x00,	// FEATURE (Data)
			0xC0,	// END COLLECTION ()
			0x05,0x01,	// USAGE_PAGE (Generic Desktop)
			0x09,0x3B,	// USAGE (Byte Count)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x26,0xFF,0x01,	// LOGICAL_MAXIMUM (511)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x46,0xFF,0x01,	// PHYSICAL_MAXIMUM (511)
			0x75,0x0A,	// REPORT_SIZE (0A)
			0x95,0x01,	// REPORT_COUNT (01)
			0xB1,0x02,	// FEATURE (Data,Var,Abs)
			0x75,0x06,	// REPORT_SIZE (06)
			0xB1,0x01,	// FEATURE (Constant,Ary,Abs)
		0xC0,	// END COLLECTION ()
		
		// PIDBlockLoadReport
		0x05,0x0F,	// USAGE_PAGE (Physical Interface)
		0x09,0x89,	// USAGE (PID Block Load Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x06,	// REPORT_ID (06)
			0x09,0x22,	// USAGE (Effect Block Index)
			0x25,0x28,	// LOGICAL_MAXIMUM (28)
			0x15,0x01,	// LOGICAL_MINIMUM (01)
			0x35,0x01,	// PHYSICAL_MINIMUM (01)
			0x45,0x28,	// PHYSICAL_MAXIMUM (28)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0xB1,0x02,	// FEATURE (Data,Var,Abs)
			0x09,0x8B,	// USAGE (Block Load Status)
			0xA1,0x02,	// COLLECTION (Logical)
				0x09,0x8C,	// USAGE (Block Load Success)
				0x09,0x8D,	// USAGE (Block Load Full)
				0x09,0x8E,	// USAGE (Block Load Error)
				0x25,0x03,	// LOGICAL_MAXIMUM (03)
				0x15,0x01,	// LOGICAL_MINIMUM (01)
				0x35,0x01,	// PHYSICAL_MINIMUM (01)
				0x45,0x03,	// PHYSICAL_MAXIMUM (03)
				0x75,0x08,	// REPORT_SIZE (08)
				0x95,0x01,	// REPORT_COUNT (01)
				0xB1,0x00,	// FEATURE (Data)
			0xC0,	// END COLLECTION ()
			0x09,0xAC,	// USAGE (RAM Pool Available)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x27,0xFF,0xFF,0x00,0x00,	// LOGICAL_MAXIMUM (00 00 FF FF)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x47,0xFF,0xFF,0x00,0x00,	// PHYSICAL_MAXIMUM (00 00 FF FF)
			0x75,0x10,	// REPORT_SIZE (10)
			0x95,0x01,	// REPORT_COUNT (01)
			0xB1,0x00,	// FEATURE (Data)
		0xC0,	// END COLLECTION ()
		
		// PIDPoolReport
		0x09,0x7F,	// USAGE (PID Pool Report)
		0xA1,0x02,	// COLLECTION (Logical)
			0x85,0x07,	// REPORT_ID (07)
			0x09,0x80,	// USAGE (RAM Pool Size)
			0x75,0x10,	// REPORT_SIZE (10)
			0x95,0x01,	// REPORT_COUNT (01)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x27,0xFF,0xFF,0x00,0x00,	// LOGICAL_MAXIMUM (00 00 FF FF)
			0x47,0xFF,0xFF,0x00,0x00,	// PHYSICAL_MAXIMUM (00 00 FF FF)
			0xB1,0x02,	// FEATURE (Data,Var,Abs)
			0x09,0x83,	// USAGE (Simultaneous Effects Max)
			0x26,0xFF,0x00,	// LOGICAL_MAXIMUM (00 FF)
			0x46,0xFF,0x00,	// PHYSICAL_MAXIMUM (00 FF)
			0x75,0x08,	// REPORT_SIZE (08)
			0x95,0x01,	// REPORT_COUNT (01)
			0xB1,0x02,	// FEATURE (Data,Var,Abs)
			0x09,0xA9,	// USAGE (Device Managed Pool)
			0x09,0xAA,	// USAGE (Shared Parameter Blocks)
			0x75,0x01,	// REPORT_SIZE (01)
			0x95,0x02,	// REPORT_COUNT (02)
			0x15,0x00,	// LOGICAL_MINIMUM (00)
			0x25,0x01,	// LOGICAL_MAXIMUM (01)
			0x35,0x00,	// PHYSICAL_MINIMUM (00)
			0x45,0x01,	// PHYSICAL_MAXIMUM (01)
			0xB1,0x02,	// FEATURE (Data,Var,Abs)
			0x75,0x06,	// REPORT_SIZE (06)
			0x95,0x01,	// REPORT_COUNT (01)
			0xB1,0x03,	// FEATURE ( Cnst,Var,Abs)
		0xC0,	// END COLLECTION ()
	0xC0,	// END COLLECTION () 			
};

#endif
