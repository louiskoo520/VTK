/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkDisplayListPainter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkDisplayListPainter - abstract superclass for painter that
// builds/uses display lists.

#ifndef __vtkDisplayListPainter_h
#define __vtkDisplayListPainter_h

#include "vtkRenderingCoreModule.h" // For export macro
#include "vtkPainter.h"

class vtkInformationIntegerKey;

class VTKRENDERINGCORE_EXPORT vtkDisplayListPainter : public vtkPainter
{
public:
  static vtkDisplayListPainter* New();
  vtkTypeMacro(vtkDisplayListPainter, vtkPainter);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Turn on/off flag to control whether data is rendered using
  // immediate mode or note. Immediate mode rendering
  // tends to be slower but it can handle larger datasets.
  // The default value is immediate mode off. If you are
  // having problems rendering a large dataset you might
  // want to consider using immediate more rendering.
  static vtkInformationIntegerKey* IMMEDIATE_MODE_RENDERING();

  // Description:
  // Get the time required to draw the geometry last time it was rendered.
  // Overridden to avoid adding of delegate rendering time
  // when Display Lists are used.
  virtual double GetTimeToDraw();

protected:
  vtkDisplayListPainter();
  ~vtkDisplayListPainter();

  // Description:
  // Called before RenderInternal() if the Information has been changed
  // since the last time this method was called.
  virtual void ProcessInformation(vtkInformation*);


  // These methods set the ivars. These are purposefully protected.
  // The only means to affect them should be using information object.
  vtkSetMacro(ImmediateModeRendering,int);

  int ImmediateModeRendering;

private:
  vtkDisplayListPainter(const vtkDisplayListPainter&); // Not implemented.
  void operator=(const vtkDisplayListPainter&); // Not implemented.
};

#endif
