/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2000 by Systems in Motion. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  version 2.1 as published by the Free Software Foundation. See the
 *  file LICENSE.LGPL at the root directory of the distribution for
 *  more details.
 *
 *  If you want to use Coin for applications not compatible with the
 *  LGPL, please contact SIM to acquire a Professional Edition license.
 *
 *  Systems in Motion, Prof Brochs gate 6, 7030 Trondheim, NORWAY
 *  http://www.sim.no support@sim.no Voice: +47 22114160 Fax: +47 22207097
 *
\**************************************************************************/

/*!
  \class SoViewingMatrixElement Inventor/elements/SoViewingMatrixElement.h
  \brief The SoViewingMatrixElement class is yet to be documented.

  FIXME: write doc.
*/

#include <Inventor/elements/SoViewingMatrixElement.h>
#include <assert.h>

/*!
  \fn SoViewingMatrixElement::viewingMatrix

  FIXME: write doc.
*/

SO_ELEMENT_SOURCE(SoViewingMatrixElement);

/*!
  This static method initializes static data for the SoViewingMatrixElement
  class.
*/

void
SoViewingMatrixElement::initClass(void)
{
  SO_ELEMENT_INIT_CLASS(SoViewingMatrixElement, inherited);
}

/*!
  The destructor.
*/

SoViewingMatrixElement::~SoViewingMatrixElement(void)
{
}

//! FIXME: write doc.

void
SoViewingMatrixElement::set(SoState * const state,
                            SoNode * const node,
                            const SbMatrix & viewingMatrix)
{
  SoViewingMatrixElement * element = (SoViewingMatrixElement *)
    SoReplacedElement::getElement(state, classStackIndex, node);
  element->setElt(viewingMatrix);
}

//! FIXME: write doc.

const SbMatrix &
SoViewingMatrixElement::get(SoState * const state)
{
  SoViewingMatrixElement * element = (SoViewingMatrixElement *)
    SoElement::getConstElement(state, classStackIndex);
  return element->viewingMatrix;
}

//! FIXME: write doc.

void
SoViewingMatrixElement::init(SoState * state)
{
  inherited::init(state);
  viewingMatrix.makeIdentity();
#if 0 // debug
  SoDebugError::postInfo("SoViewingMatrixElement::init",
                         "matrix set to identity");
#endif // debug
}

//! FIXME: write doc.

void
SoViewingMatrixElement::setElt(const SbMatrix &matrix)
{
  this->viewingMatrix = matrix;
#if 0 // debug
  SoDebugError::postInfo("SoViewingMatrixElement::setElt",
                         "viewingmatrix:");
  matrix.print(stdout);
#endif // debug
}
