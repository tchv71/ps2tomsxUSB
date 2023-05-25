/** @addtogroup 05 dbasemgt Database Management
 *
 * @file database.c Database definition file input.
 *
 * @brief <b>Database definition, check and maintenance routines.</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2022
 * Evandro Souza <evandro.r.souza@gmail.com>
 *
 * @date 25 September 2022
 *
 * This library executes functions to interface and control a PS/2 keyboard, like:
 * power control of a PS/2 key, general interface to read events and write commands to PS/2
 * keyboard, including interrupt service routines on the STM32F4 and STM32F1 series of ARM
 * Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms ref lgpl_license
 */

/*
 * This file is part of the PS/2 to MSX Keyboard converter enviroment:
 * PS/2 to MSX keyboard Converter and MSX Keyboard Subsystem Emulator
 * designs, based on libopencm3 project.
 *
 * Copyright (C) 2022 Evandro Souza <evandro.r.souza@gmail.com>
 *
 * This original SW is compiled to a Sharp/Epcom MSX HB-8000 and a brazilian ABNT2 PS/2 keyboard (ID=275)
 * But it is possible to update the table sending a Intel Hex File through serial or USB
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

//Use Tab width=2



const uint8_t 
#if MCU == STM32F103
__attribute__((section("MSXDATABASE"))) 
#endif  //#if MCU == STM32F103
DEFAULT_MSX_KEYB_DATABASE_CONVERSION[(uint16_t)N_DATABASE_REGISTERS][(uint8_t)DB_NUM_COLS] =
//Paste here the generated excel Conversion Database to make it as a default.
//Colar aqui Base de Dados de conversao gerada pelo excel para compilar como uma tabela default.
{
    {1, 0, 255, 255, 255, 255, 255, 255},
    {1, 0, 0, 244, 144, 6, 255, 255},
    {3, 0, 0, 244, 7, 255, 255, 255},
    {4, 0, 0, 244, 5, 255, 255, 255},
    {5, 0, 0, 244, 3, 255, 255, 255},
    {6, 0, 0, 244, 4, 255, 255, 255},
    {9, 0, 0, 244, 144, 7, 255, 255},
    {10, 0, 0, 244, 144, 5, 255, 255},
    {11, 0, 0, 244, 144, 3, 255, 255},
    {12, 0, 0, 244, 6, 255, 255, 255},
    {13, 0, 0, 244, 16, 255, 255, 255},
    {14, 0, 0, 246, 144, 39, 96, 6},
    {18, 0, 0, 244, 144, 255, 255, 255},
    {20, 0, 0, 244, 128, 255, 255, 255},
    {21, 0, 0, 244, 97, 255, 255, 255},
    {22, 0, 0, 244, 33, 255, 255, 255},
    {26, 0, 0, 244, 114, 255, 255, 255},
    {27, 0, 0, 244, 99, 255, 255, 255},
    {28, 0, 0, 244, 65, 255, 255, 255},
    {29, 0, 0, 244, 103, 255, 255, 255},
    {30, 0, 0, 254, 34, 255, 152, 64},
    {33, 0, 0, 244, 67, 255, 255, 255},
    {34, 0, 0, 244, 112, 255, 255, 255},
    {35, 0, 0, 244, 68, 255, 255, 255},
    {36, 0, 0, 244, 69, 255, 255, 255},
    {37, 0, 0, 244, 36, 255, 255, 255},
    {38, 0, 0, 244, 35, 255, 255, 255},
    {41, 0, 0, 244, 119, 255, 255, 255},
    {42, 0, 0, 244, 102, 255, 255, 255},
    {43, 0, 0, 244, 70, 255, 255, 255},
    {44, 0, 0, 244, 100, 255, 255, 255},
    {45, 0, 0, 244, 98, 255, 255, 255},
    {46, 0, 0, 244, 37, 255, 255, 255},
    {49, 0, 0, 244, 86, 255, 255, 255},
    {50, 0, 0, 244, 66, 255, 255, 255},
    {51, 0, 0, 244, 80, 255, 255, 255},
    {52, 0, 0, 244, 71, 255, 255, 255},
    {53, 0, 0, 244, 113, 255, 255, 255},
    {54, 0, 0, 254, 38, 255, 152, 118},
    {58, 0, 0, 244, 85, 255, 255, 255},
    {59, 0, 0, 244, 82, 255, 255, 255},
    {60, 0, 0, 244, 101, 255, 255, 255},
    {61, 0, 0, 254, 39, 255, 38, 255},
    {62, 0, 0, 254, 48, 255, 50, 255},
    {65, 0, 0, 244, 52, 255, 255, 255},
    {66, 0, 0, 244, 83, 255, 255, 255},
    {67, 0, 0, 244, 81, 255, 255, 255},
    {68, 0, 0, 244, 87, 255, 255, 255},
    {69, 0, 0, 254, 32, 255, 49, 255},
    {70, 0, 0, 254, 49, 255, 48, 255},
    {73, 0, 0, 244, 54, 255, 255, 255},
    {74, 0, 0, 244, 55, 255, 255, 255},
    {75, 0, 0, 244, 84, 255, 255, 255},
    {76, 0, 0, 254, 51, 255, 152, 50},
    {77, 0, 0, 244, 96, 255, 255, 255},
    {78, 0, 0, 254, 53, 255, 32, 255},
    {82, 0, 0, 244, 144, 34, 255, 255},
    {84, 0, 0, 244, 115, 255, 255, 255},
    {85, 0, 0, 254, 144, 53, 51, 255},
    {88, 0, 0, 244, 160, 255, 255, 255},
    {89, 0, 0, 244, 144, 255, 255, 255},
    {90, 0, 0, 244, 18, 255, 255, 255},
    {91, 0, 0, 246, 117, 255, 255, 255},
    {93, 0, 0, 244, 116, 255, 255, 255},
    {102, 0, 0, 244, 19, 255, 255, 255},
    {105, 0, 0, 244, 33, 255, 255, 255},
    {107, 0, 0, 253, 36, 255, 20, 255},
    {108, 0, 0, 253, 39, 255, 0, 255},
    {109, 0, 0, 244, 35, 255, 255, 255},
    {112, 0, 0, 253, 32, 255, 255, 255},
    {113, 0, 0, 253, 54, 255, 255, 255},
    {114, 0, 0, 253, 34, 255, 23, 255},
    {115, 0, 0, 244, 37, 255, 37, 255},
    {116, 0, 0, 253, 38, 255, 23, 255},
    {117, 0, 0, 253, 48, 255, 21, 255},
    {118, 0, 0, 244, 2, 255, 255, 255},
    {121, 0, 0, 244, 144, 51, 255, 255},
    {122, 0, 0, 244, 35, 255, 255, 255},
    {123, 0, 0, 244, 53, 255, 255, 255},
    {124, 0, 0, 244, 144, 50, 255, 255},
    {125, 0, 0, 244, 49, 255, 255, 255},
    {224, 20, 0, 244, 128, 255, 255, 255},
    {224, 74, 0, 244, 55, 255, 255, 255},
    {224, 90, 0, 244, 18, 255, 255, 255},
    {224, 107, 0, 244, 20, 255, 255, 255},
    {224, 108, 0, 244, 0, 255, 255, 255},
    {224, 112, 0, 244, 5, 255, 255, 255},
    {224, 113, 0, 244, 6, 255, 255, 255},
    {224, 114, 0, 244, 23, 255, 255, 255},
    {224, 116, 0, 244, 22, 255, 255, 255},
    {224, 117, 0, 244, 21, 255, 255, 255},
    {224, 122, 0, 244, 8, 23, 255, 255},
    {224, 125, 0, 244, 8, 21, 255, 255},
    {224, 240, 20, 244, 136, 255, 255, 255},
    {224, 240, 74, 244, 63, 255, 255, 255},
    {224, 240, 90, 244, 26, 255, 255, 255},
    {224, 240, 107, 244, 28, 255, 255, 255},
    {224, 240, 108, 244, 8, 255, 255, 255},
    {224, 240, 112, 244, 13, 255, 255, 255},
    {224, 240, 113, 244, 14, 255, 255, 255},
    {224, 240, 114, 244, 31, 255, 255, 255},
    {224, 240, 116, 244, 30, 255, 255, 255},
    {224, 240, 117, 244, 29, 255, 255, 255},
    {224, 240, 122, 244, 31, 24, 255, 255},
    {224, 240, 125, 244, 29, 24, 255, 255},
    {240, 1, 0, 244, 14, 152, 255, 255},
    {240, 3, 0, 244, 15, 255, 255, 255},
    {240, 4, 0, 244, 13, 255, 255, 255},
    {240, 5, 0, 244, 11, 255, 255, 255},
    {240, 6, 0, 244, 12, 255, 255, 255},
    {240, 9, 0, 244, 15, 152, 255, 255},
    {240, 10, 0, 244, 13, 152, 255, 255},
    {240, 11, 0, 244, 11, 152, 255, 255},
    {240, 12, 0, 244, 14, 255, 255, 255},
    {240, 13, 0, 244, 24, 255, 255, 255},
    {240, 14, 0, 246, 47, 152, 14, 104},
    {240, 18, 0, 244, 152, 255, 255, 255},
    {240, 20, 0, 244, 136, 255, 255, 255},
    {240, 21, 0, 244, 105, 255, 255, 255},
    {240, 22, 0, 244, 41, 255, 255, 255},
    {240, 26, 0, 244, 122, 255, 255, 255},
    {240, 27, 0, 244, 107, 255, 255, 255},
    {240, 28, 0, 244, 73, 255, 255, 255},
    {240, 29, 0, 244, 111, 255, 255, 255},
    {240, 30, 0, 254, 42, 255, 72, 144},
    {240, 33, 0, 244, 75, 255, 255, 255},
    {240, 34, 0, 244, 120, 255, 255, 255},
    {240, 35, 0, 244, 76, 255, 255, 255},
    {240, 36, 0, 244, 77, 255, 255, 255},
    {240, 37, 0, 244, 44, 255, 255, 255},
    {240, 38, 0, 244, 43, 255, 255, 255},
    {240, 41, 0, 244, 127, 255, 255, 255},
    {240, 42, 0, 244, 110, 255, 255, 255},
    {240, 43, 0, 244, 78, 255, 255, 255},
    {240, 44, 0, 244, 108, 255, 255, 255},
    {240, 45, 0, 244, 106, 255, 255, 255},
    {240, 46, 0, 244, 45, 255, 255, 255},
    {240, 49, 0, 244, 94, 255, 255, 255},
    {240, 50, 0, 244, 74, 255, 255, 255},
    {240, 51, 0, 244, 88, 255, 255, 255},
    {240, 52, 0, 244, 79, 255, 255, 255},
    {240, 53, 0, 244, 121, 255, 255, 255},
    {240, 54, 0, 254, 46, 255, 126, 144},
    {240, 58, 0, 244, 93, 255, 255, 255},
    {240, 59, 0, 244, 90, 255, 255, 255},
    {240, 60, 0, 244, 109, 255, 255, 255},
    {240, 61, 0, 254, 47, 255, 46, 255},
    {240, 62, 0, 254, 56, 255, 58, 255},
    {240, 65, 0, 244, 60, 255, 255, 255},
    {240, 66, 0, 244, 91, 255, 255, 255},
    {240, 67, 0, 244, 89, 255, 255, 255},
    {240, 68, 0, 244, 95, 255, 255, 255},
    {240, 69, 0, 254, 40, 255, 57, 255},
    {240, 70, 0, 254, 57, 255, 56, 255},
    {240, 73, 0, 244, 62, 255, 255, 255},
    {240, 74, 0, 244, 63, 255, 255, 255},
    {240, 75, 0, 244, 92, 255, 255, 255},
    {240, 76, 0, 254, 59, 255, 58, 144},
    {240, 77, 0, 244, 104, 255, 255, 255},
    {240, 78, 0, 254, 61, 255, 40, 255},
    {240, 82, 0, 244, 42, 152, 255, 255},
    {240, 84, 0, 244, 123, 255, 255, 255},
    {240, 85, 0, 254, 61, 152, 59, 255},
    {240, 88, 0, 244, 168, 255, 255, 255},
    {240, 89, 0, 244, 152, 255, 255, 255},
    {240, 90, 0, 244, 26, 255, 255, 255},
    {240, 91, 0, 246, 125, 255, 255, 255},
    {240, 93, 0, 244, 124, 255, 255, 255},
    {240, 102, 0, 244, 27, 255, 255, 255},
    {240, 105, 0, 244, 41, 255, 255, 255},
    {240, 107, 0, 253, 44, 255, 28, 255},
    {240, 108, 0, 253, 47, 255, 8, 255},
    {240, 109, 0, 244, 43, 255, 255, 255},
    {240, 112, 0, 253, 40, 255, 255, 255},
    {240, 113, 0, 253, 62, 255, 255, 255},
    {240, 114, 0, 253, 42, 255, 31, 255},
    {240, 115, 0, 244, 45, 255, 45, 255},
    {240, 116, 0, 253, 46, 255, 31, 255},
    {240, 117, 0, 253, 56, 255, 29, 255},
    {240, 118, 0, 244, 10, 255, 255, 255},
    {240, 121, 0, 244, 59, 152, 255, 255},
    {240, 122, 0, 244, 43, 255, 255, 255},
    {240, 123, 0, 244, 61, 255, 255, 255},
    {240, 124, 0, 244, 58, 152, 255, 255},
    {240, 125, 0, 244, 57, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 9, 237}
};
