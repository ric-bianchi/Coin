/**************************************************************************\
 *
 *  Copyright (C) 1998-2000 by Systems in Motion.  All rights reserved.
 *
 *  This file is part of the Coin library.
 *
 *  This file may be distributed under the terms of the Q Public License
 *  as defined by Troll Tech AS of Norway and appearing in the file
 *  LICENSE.QPL included in the packaging of this file.
 *
 *  If you want to use Coin in applications not covered by licenses
 *  compatible with the QPL, you can contact SIM to aquire a
 *  Professional Edition license for Coin.
 *
 *  Systems in Motion AS, Prof. Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ sales@sim.no Voice: +47 22114160 Fax: +47 67172912
 *
\**************************************************************************/

/*!
  \class SoMatrixTransform SoMatrixTransform.h Inventor/nodes/SoMatrixTransform.h
  \brief The SoMatrixTransform class is a transformation node.
  \ingroup nodes

  This class is the most flexible transformation node, as you can use
  it to accumulate any kind of transformation matrix on top of the
  current model transformation matrix.

  \sa SoTransform
*/

#include <Inventor/nodes/SoMatrixTransform.h>

#include <Inventor/actions/SoGetMatrixAction.h>
#include <Inventor/actions/SoGLRenderAction.h>
#include <Inventor/elements/SoGLNormalizeElement.h>
#include <Inventor/elements/SoModelMatrixElement.h>

/*!
  \var SoSFMatrix SoMatrixTransform::matrix
  The transformation matrix. Defaults to the identity matrix.
*/


// *************************************************************************

SO_NODE_SOURCE(SoMatrixTransform);

/*!
  Constructor.
*/
SoMatrixTransform::SoMatrixTransform(void)
{
  SO_NODE_INTERNAL_CONSTRUCTOR(SoMatrixTransform);

  SO_NODE_ADD_FIELD(matrix, (SbMatrix::identity()));
}

/*!
  Destructor.
*/
SoMatrixTransform::~SoMatrixTransform()
{
}

// Doc from superclass.
void
SoMatrixTransform::initClass(void)
{
  SO_NODE_INTERNAL_INIT_CLASS(SoMatrixTransform);
}

// Doc from superclass.
void
SoMatrixTransform::doAction(SoAction * action)
{
  if (!this->matrix.isIgnored()) {
    SoModelMatrixElement::mult(action->getState(), this,
                               this->matrix.getValue());
  }
}

// Doc from superclass.
void
SoMatrixTransform::GLRender(SoGLRenderAction * action)
{
  // We should only need to activate the OpenGL unit vector
  // normalization if the matrix contains an "active" scale component,
  // but as checking for this will take some time, we always activate.
  //
  // An optimization for this node could be to cache the scale
  // component whenever the matrix is set, and then check the scale
  // factor component here before possibly activating the OpenGL
  // normalize code.
  SoGLNormalizeElement::setMatrixState(action->getState(), FALSE);

  SoMatrixTransform::doAction((SoAction *)action);
}

// Doc from superclass.
void
SoMatrixTransform::getBoundingBox(SoGetBoundingBoxAction * action)
{
  SoMatrixTransform::doAction((SoAction *)action);
}

// Doc from superclass.
void
SoMatrixTransform::callback(SoCallbackAction * action)
{
  SoMatrixTransform::doAction((SoAction *)action);
}

// Doc from superclass.
void
SoMatrixTransform::getMatrix(SoGetMatrixAction * action)
{
  SbMatrix m = this->matrix.getValue();
  action->getMatrix().multLeft(m);

  SbMatrix mi = m.inverse();
  action->getInverse().multRight(mi);
}

// Doc from superclass.
void
SoMatrixTransform::pick(SoPickAction * action)
{
  SoMatrixTransform::doAction((SoAction *)action);
}

// Doc from superclass.
void
SoMatrixTransform::getPrimitiveCount(SoGetPrimitiveCountAction * action)
{
  SoMatrixTransform::doAction((SoAction *)action);
}
