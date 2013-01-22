/*=========================================================================

  Program:   Monteverdi2
  Language:  C++


  Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
  See Copyright.txt for details.

  Monteverdi2 is distributed under the CeCILL licence version 2. See
  Licence_CeCILL_V2-en.txt or
  http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt for more details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include "mvdDatasetModel.h"

//
// Qt includes (sorted by alphabetic order)
//// Must be included before system/custom includes.

//
// System includes (sorted by alphabetic order)

//
// ITK includes (sorted by alphabetic order)

//
// OTB includes (sorted by alphabetic order)

//
// Monteverdi includes (sorted by alphabetic order)
#include "mvdVectorImageModel.h"

namespace mvd
{
/*
  TRANSLATOR mvd::DatasetModel

  Necessary for lupdate to be aware of C++ namespaces.

  Context comment for translator.
*/

/*******************************************************************************/
DatasetModel
::DatasetModel( QObject* parent ) :
  AbstractModel( parent )
{
}

/*******************************************************************************/
DatasetModel
::~DatasetModel()
{
}

/*******************************************************************************/
void
DatasetModel
::ImportImage( const QString& filename )
{
  // 1. Instanciate local image model.
  VectorImageModel* vectorImageModel = new VectorImageModel();

  vectorImageModel->setObjectName(
    "mvd::VectorImageModel('" + filename + "')"
  );

  // 2. Safely load data from file.
  try
    {
    // 2.1. Information.
    vectorImageModel->LoadFile( filename );

    // 2.2. Generate cached data.
    // TODO: generate image-model cached data (quicklook,
    // histogram-list etc.)
    vectorImageModel->GenerateCachedData();
    }
  catch( std::exception& exc )
    {
    // Release local memory allocation.
    delete vectorImageModel;
    vectorImageModel = NULL;

    // Forward exception to upper level (GUI).
    throw;
    }

  // If everything has gone well, parent image model to dataset model.
  vectorImageModel->setParent( this );
}

/*******************************************************************************/
/* SLOTS                                                                       */
/*******************************************************************************/

/*******************************************************************************/

} // end namespace 'mvd'
