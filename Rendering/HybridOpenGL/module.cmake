vtk_module(vtkRenderingHybridOpenGL
  GROUPS
    Rendering
  DEPENDS
    vtkIOGeometry
    vtkImagingSources
    vtkImagingHybrid
    vtkRenderingOpenGL
  TEST_DEPENDS
    vtkIOGeometry
    vtkIOXML
    vtkTestingCore
    vtkTestingRendering
  )