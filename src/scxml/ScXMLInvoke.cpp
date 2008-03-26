/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2008 by Kongsberg SIM.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Kongsberg SIM about acquiring
 *  a Coin Professional Edition License.
 *
 *  See http://www.coin3d.org/ for more information.
 *
 *  Kongsberg SIM, Postboks 1283, Pirsenteret, 7462 Trondheim, NORWAY.
 *  http://www.sim.no/  sales@sim.no  coin-support@coin3d.org
 *
\**************************************************************************/

#include <Inventor/scxml/ScXMLInvoke.h>

#include <assert.h>
#include <string.h>

SCXML_OBJECT_ABSTRACT_SOURCE(ScXMLInvoke);

void
ScXMLInvoke::initClass(void)
{
  SCXML_OBJECT_INIT_ABSTRACT_CLASS(ScXMLInvoke, ScXMLObject);
}

ScXMLInvoke::ScXMLInvoke(void)
  : targettype(NULL), src(NULL), srcexpr(NULL)
{
}

ScXMLInvoke::~ScXMLInvoke(void)
{
  this->setTargetTypeXMLAttr(NULL);
  this->setSrcXMLAttr(NULL);
  this->setSrcExprXMLAttr(NULL);
}

void
ScXMLInvoke::setTargetTypeXMLAttr(const char * targettypestr)
{
  if (this->targettype &&
      this->targettype != this->getAttribute("targettype")) {
    delete [] const_cast<char *>(this->targettype);
  }
  this->targettype = NULL;
  if (targettypestr) {
    char * buffer = new char [ strlen(targettypestr) + 1 ];
    strcpy(buffer, targettypestr);
    this->targettype = buffer;
  }
}

// const char * ScXMLInvoke::getTargetTypeXMLAttr(void) const

void
ScXMLInvoke::setSrcXMLAttr(const char * srcstr)
{
  if (this->src && this->src != this->getAttribute("src")) {
    delete [] const_cast<char *>(this->src);
  }
  this->src = NULL;
  if (srcstr) {
    char * buffer = new char [ strlen(srcstr) + 1 ];
    strcpy(buffer, srcstr);
    this->src = buffer;
  }
}

// const char * ScXMLInvoke::getSrcXMLAttr(void) const

void
ScXMLInvoke::setSrcExprXMLAttr(const char * srcexprstr)
{
  if (this->srcexpr && this->srcexpr != this->getAttribute("srcexpr")) {
    delete [] const_cast<char *>(this->srcexpr);
  }
  this->srcexpr = NULL;
  if (srcexprstr) {
    char * buffer = new char [ strlen(srcexprstr) + 1 ];
    strcpy(buffer, srcexprstr);
    this->srcexpr = buffer;
  }
}

// const char * ScXMLInvoke::getSrcExprXMLAttr(void) const

SbBool
ScXMLInvoke::handleXMLAttributes(void)
{
  if (!inherited::handleXMLAttributes()) return FALSE;

  this->targettype = this->getAttribute("targettype");
  this->src = this->getAttribute("src");
  this->srcexpr = this->getAttribute("srcexpr");

  if (!this->targettype) { return FALSE; }

  return TRUE;
}
