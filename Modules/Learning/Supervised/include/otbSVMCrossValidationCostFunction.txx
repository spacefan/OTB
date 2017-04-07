/*
 * Copyright (C) 2005-2017 Centre National d'Etudes Spatiales (CNES)
 *
 * This file is part of Orfeo Toolbox
 *
 *     https://www.orfeo-toolbox.org/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef otbSVMCrossValidationCostFunction_txx
#define otbSVMCrossValidationCostFunction_txx

#include "otbSVMCrossValidationCostFunction.h"

namespace otb
{
template<class TModel>
SVMCrossValidationCostFunction<TModel>
::SVMCrossValidationCostFunction() : m_Model(), m_DerivativeStep(0.001)
{}
template<class TModel>
SVMCrossValidationCostFunction<TModel>
::~SVMCrossValidationCostFunction()
{}
template<class TModel>
typename SVMCrossValidationCostFunction<TModel>
::MeasureType
SVMCrossValidationCostFunction<TModel>
::GetValue(const ParametersType& parameters) const
{
  // Check the input model
  if (!m_Model)
    {
    itkExceptionMacro(<< "Model is null, can not evaluate accuracy.");
    }

  // Check for a positive and non-null C
  if (parameters[0] <= 0)
    {
    return 0;
    }

  // Updates vm_parameters according to current parameters
  this->UpdateParameters(parameters);

  return m_Model->CrossValidation();
}

template<class TModel>
void
SVMCrossValidationCostFunction<TModel>
::GetDerivative(const ParametersType& parameters, DerivativeType& derivative) const
{
  // Set derivative size
  derivative.SetSize(parameters.Size());
  derivative.Fill(itk::NumericTraits<ParametersValueType>::Zero);

  for (unsigned int i = 0; i < parameters.Size(); ++i)
    {
    MeasureType    y1, y2;
    ParametersType x1, x2;

    x1 = parameters;
    x1[i] -= m_DerivativeStep;
    y1 = this->GetValue(x1);

    x2 = parameters;
    x2[i] += m_DerivativeStep;
    y2 = this->GetValue(x2);

    derivative[i] = (y2 - y1) / (2 * m_DerivativeStep);
    otbMsgDevMacro( << "x1= " << x1 << " x2= " << x2 << ", y1= " << y1 << ", y2= " << y2 );
    }
  otbMsgDevMacro( "Position: " << parameters << ", Value: " << this->GetValue(parameters)
                  << ", Derivatives: " << derivative );
}

template<class TModel>
unsigned int
SVMCrossValidationCostFunction<TModel>
::GetNumberOfParameters(void) const
{
  if (!m_Model)
    {
    itkExceptionMacro(<< "Model is null, can not evaluate number of parameters.");
    }

  switch (m_Model->GetKernelType())
    {
    case LINEAR:
      // C
      return 1;

    case POLY:
      // C, gamma and coef0
      return 3;

    case RBF:
      // C and gamma
      return 2;

    case SIGMOID:
      // C, gamma and coef0
      return 3;

    default:
      // C
      return 1;
    }
}

template<class TModel>
void
SVMCrossValidationCostFunction<TModel>
::UpdateParameters(struct svm_parameter& svm_parameters, const ParametersType& parameters) const
{
  switch (m_Model->GetKernelType())
    {
    case LINEAR:
      // C
      m_Model->SetC(parameters[0]);
      break;

    case POLY:
      // C, gamma and coef0
      m_Model->SetC(parameters[0]);
      m_Model->SetKernelGamma(parameters[1]);
      m_Model->SetKernelCoef0(parameters[2]);
      break;

    case RBF:
      // C and gamma
      m_Model->SetC(parameters[0]);
      m_Model->SetKernelGamma(parameters[1]);
      break;

    case SIGMOID:
      // C, gamma and coef0
      m_Model->SetC(parameters[0]);
      m_Model->SetKernelGamma(parameters[1]);
      m_Model->SetKernelCoef0(parameters[2]);
      break;

    default:
      m_Model->SetC(parameters[0]);
      break;
    }
}

} // namespace otb

#endif
