/* Plus42Wire GAL Equations
 * Copyright 2024 SukkoPera <software@sukkology.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/* These equations can be turned into a JED file through the WinCUPL software.
 * Too bad it's Windows-only and full of bugs...
 */

/** Inputs **/
Pin 1 = a15;
Pin 3 = a12;
Pin 4 = a11;
Pin 5 = a10;
Pin 6 = a9;
Pin 7 = a8;
Pin 8 = a6;
Pin 9 = a4;
Pin 10 = a2;
Pin 11 = a0;
Pin 14 = a1;
Pin 15 = a3;
Pin 16 = a5;
Pin 17 = a7;
Pin 21 = a13;
Pin 22 = a14;

Pin 13 = phi2;
Pin 23 = rw;
Pin 2 = ba;					// High when Bus Available

/** Outputs **/
Pin 18 = rd8584;			// Active-low
Pin 19 = cs8584;			// Active-low
Pin 20 = wr8584;			// Active-low

/** Declarations and Intermediate Variable Definitions **/
Field addr = [a15..2];

/** Logic Equations **/
_addressed = addr:[FE04..FE05];
rd8584 = !(_addressed & phi2 & rw & ba);
wr8584 = !(_addressed & phi2 & !rw);
cs8584 = !_addressed;		// The gotcha with this chip is that /CS must go down *before* /RD and /WR, in 80xx bus style
//~ cs8584 = !(_addressed & (!phi2 # !rd8255 # !wr8255));
