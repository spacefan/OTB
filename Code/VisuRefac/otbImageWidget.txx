/*=========================================================================

Program:   ORFEO Toolbox
Language:  C++
Date:      $Date$
Version:   $Revision$


Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
See OTBCopyright.txt for details.


This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __otbImageWidget_txx
#define __otbImageWidget_txx

#include "otbImageWidget.h"
#include "itkImageRegionConstIteratorWithIndex.h"

namespace otb
{
template <class TInputImage>
ImageWidget<TInputImage>
::ImageWidget() : m_IsotropicZoom(1.0), m_OpenGlBuffer(NULL), m_OpenGlBufferedRegion(),
		 m_Rectangle(),m_DisplayRectangle(false),m_RectangleColor(), m_Extent(), 
		  m_SubsamplingRate(1), m_ImageToScreenTransform(),m_ScreenToImageTransform(),
		  m_GlComponents()
{
  // Default color for rectangle
  m_RectangleColor.Fill(0.);
  m_RectangleColor[0]=1.0;
  m_RectangleColor[3]=1.0;
  
  // Initialize space to screen transform and inverse
  m_ImageToScreenTransform = AffineTransformType::New();
  m_ScreenToImageTransform = AffineTransformType::New();

  // Initialize the components list
  m_GlComponents = GlComponentListType::New();
}

template <class TInputImage>
ImageWidget<TInputImage>
::~ImageWidget()
{
  // Delete OpenGl buffer if needed
  if(m_OpenGlBuffer!=NULL)
    {
    delete [] m_OpenGlBuffer;
    m_OpenGlBuffer = NULL;
    }
}

template <class TInputImage>
void
ImageWidget<TInputImage>
::PrintSelf(std::ostream& os, itk::Indent indent) const
{
  // Call the superclass implementation
  Superclass::PrintSelf(os,indent);

  if(m_OpenGlBuffer == NULL)
    {
    os<<indent<<indent<<"OpenGl buffer is not allocated."<<std::endl;
    }
  else
    {
    os<<indent<<indent<<"OpenGl buffer is allocated with size "<<m_OpenGlBufferedRegion.GetSize()<<"."<<std::endl;
    }
  os<<indent<<indent<<"OpenGl isotropic zoom is "<<m_IsotropicZoom<<"."<<std::endl;
}



template <class TInputImage>
void
ImageWidget<TInputImage>
::ReadBuffer(const InputImageType * image, const RegionType & region)
{
  // Before doing anything, check if region is inside the buffered
  // region of image
  if(!image->GetBufferedRegion().IsInside(region))
    {
    itkExceptionMacro(<<"Region to read is oustside of the buffered region.");
    }
  // Delete previous buffer if needed
  if(m_OpenGlBuffer != NULL)
    {
    delete [] m_OpenGlBuffer;
    m_OpenGlBuffer = NULL;
    }
  // Allocate new memory
  m_OpenGlBuffer = new unsigned char[3*region.GetNumberOfPixels()];

  // Declare the iterator
  itk::ImageRegionConstIteratorWithIndex<InputImageType> it(image,region);

  // Go to begin
  it.GoToBegin();

  while(!it.IsAtEnd())
    {
    // Fill the buffer
    unsigned int index = 0;
    if(!this->GetUseGlAcceleration())
      {
      // compute the linear index (buffer is flipped around X axis
      // when gl acceleration is disabled
      index = ComputeXAxisFlippedBufferIndex(it.GetIndex(),region);
      }
    else
      {
      // Conpute the linear index
      index = ComputeBufferIndex(it.GetIndex(),region);
      }

    // Fill the buffer
    m_OpenGlBuffer[index]  =it.Get()[0];
    m_OpenGlBuffer[index+1]=it.Get()[1];
    m_OpenGlBuffer[index+2]=it.Get()[2];
    ++it;
    }
  // Last, updating buffer size
  m_OpenGlBufferedRegion = region;
}

template <class TInputImage>
void
ImageWidget<TInputImage>
::UpdateTransforms()
{
  assert(m_IsotropicZoom>0 && "Isotropic zoom should be non null positive.");

  typename RegionType::IndexType index;
  typename RegionType::SizeType  size;
  // Update image extent
  size[0]= static_cast<unsigned int>(m_IsotropicZoom*static_cast<double>(m_OpenGlBufferedRegion.GetSize()[0]));
  size[1]= static_cast<unsigned int>(m_IsotropicZoom*static_cast<double>(m_OpenGlBufferedRegion.GetSize()[1]));
  index[0] = (this->w()-size[0])/2;
  index[1] = (this->h()-size[1])/2;
  m_Extent.SetIndex(index);
  m_Extent.SetSize(size);

  // Image to screen matrix
  typename AffineTransformType::MatrixType s2iMatrix;
  s2iMatrix.Fill(0);
  const double s2iSpacing =(m_SubsamplingRate)/m_IsotropicZoom;
  s2iMatrix(0,0)=s2iSpacing;
  s2iMatrix(1,1)=s2iSpacing;
  m_ScreenToImageTransform->SetMatrix(s2iMatrix);

  // Image to screen translation
  typename AffineTransformType::OutputVectorType translation;
  translation[0]= m_SubsamplingRate * (m_OpenGlBufferedRegion.GetIndex()[0]-m_Extent.GetIndex()[0]/m_IsotropicZoom);
  translation[1]= m_SubsamplingRate * (m_OpenGlBufferedRegion.GetIndex()[0]-m_Extent.GetIndex()[0]/m_IsotropicZoom);
  m_ScreenToImageTransform->SetTranslation(translation);

  // Compute the inverse transform
  m_ScreenToImageTransform->GetInverse(m_ImageToScreenTransform);
}

template <class TInputImage>
void
ImageWidget<TInputImage>
::draw()
{
  // perform checks from superclass and gl initialisation
  Superclass::draw();

  glDisable(GL_BLEND);
  // Check if there is somthing to draw
  if(m_OpenGlBuffer == NULL)
    {
    return;
    }

  // Update transforms
  this->UpdateTransforms();


  if(!this->GetUseGlAcceleration())
    {
    // Set the pixel Zoom
    glRasterPos2f(m_Extent.GetIndex()[0],m_Extent.GetIndex()[1]);
    glPixelZoom(m_IsotropicZoom,m_IsotropicZoom);

    // display the image
    glDrawPixels(m_OpenGlBufferedRegion.GetSize()[0],
		 m_OpenGlBufferedRegion.GetSize()[1],
		 GL_RGB,
		 GL_UNSIGNED_BYTE,
		 m_OpenGlBuffer);
    }
  else
    {
    glEnable(GL_TEXTURE_2D);
    glColor4f(1.0,1.0,1.0,0.0);
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, m_OpenGlBufferedRegion.GetSize()[0], m_OpenGlBufferedRegion.GetSize()[1], 0, GL_RGB, GL_UNSIGNED_BYTE, m_OpenGlBuffer);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);  // Linear Filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);  // Linear Filtering
    glBindTexture (GL_TEXTURE_2D, texture);
    glBegin (GL_QUADS);
    glTexCoord2f (0.0, 1.0);
    glVertex3f (m_Extent.GetIndex()[0],m_Extent.GetIndex()[1], 0.0);
    glTexCoord2f (1.0, 1.0);
    glVertex3f (m_Extent.GetIndex()[0]+m_Extent.GetSize()[0], m_Extent.GetIndex()[1], 0.0);
    glTexCoord2f (1.0, 0.0);
    glVertex3f (m_Extent.GetIndex()[0]+m_Extent.GetSize()[0],m_Extent.GetIndex()[1]+m_Extent.GetSize()[1], 0.0);
    glTexCoord2f (0.0, 0.0);
    glVertex3f (m_Extent.GetIndex()[0],m_Extent.GetIndex()[1]+m_Extent.GetSize()[1], 0.0);
    glEnd ();
    glDisable(GL_TEXTURE_2D);
    }

  // Render additionnal GlComponents
  for(GlComponentIteratorType it = m_GlComponents->Begin();
      it!=m_GlComponents->End();++it)
    {
    if(it.Get()->GetVisible())
      {
      it.Get()->Render(m_Extent,m_ImageToScreenTransform);
      }
    }

//   // Draw the rectangle if necessary
//   if(m_DisplayRectangle)
//     {
//     typename RegionType::IndexType index;
//     typename RegionType::SizeType  size;

//     index = m_Rectangle.GetIndex();
//     // UL left in image space is LR in opengl space, so we need to get
//     // the real upper left
//     index[1]+=m_Rectangle.GetSize()[1];
//     index = ImageIndexToScreenIndex(index);
    
//     size[0]=  static_cast<unsigned int>(static_cast<double>(m_Rectangle.GetSize()[0]/m_SubsamplingRate)*m_IsotropicZoom);
//     size[1] = static_cast<unsigned int>(static_cast<double>(m_Rectangle.GetSize()[1]/m_SubsamplingRate)*m_IsotropicZoom);
    

//     glEnable(GL_BLEND);
//     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);   
//     glColor4f(m_RectangleColor[0],m_RectangleColor[1],m_RectangleColor[2],m_RectangleColor[3]);
//     glBegin(GL_LINE_LOOP);
//     gl_rect(index[0],index[1],size[0],size[1]);
//     glEnd();
//     glDisable(GL_BLEND);
//     }
}
}
#endif
