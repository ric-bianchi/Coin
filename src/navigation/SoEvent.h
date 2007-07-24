#ifndef SO_SOEVENT_H
#define SO_SOEVENT_H

/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2007 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See http://www.coin3d.org/ for more information.
 *
 *  Systems in Motion, Postboks 1283, Pirsenteret, 7462 Trondheim, NORWAY.
 *  http://www.sim.no/  sales@sim.no  coin-support@coin3d.org
 *
\**************************************************************************/

#ifndef COIN_INTERNAL
#error Inventor/navigation/SoEvent.h is a private/internal header file!
#endif // !COIN_INTERNAL

#include <stdio.h>
#include <Inventor/SbBasic.h>

class SoEvent;

SbBool SoEvent_Equals(const SoEvent * ev1, const SoEvent * ev2);
SoEvent * SoEvent_Clone(const SoEvent * ev);
void SoEvent_Dump(FILE * stream, const SoEvent * ev);

#endif // !SO_SOEVENT_H