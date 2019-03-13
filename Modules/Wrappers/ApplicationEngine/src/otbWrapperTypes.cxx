/*
 * Copyright (C) 2005-2019 Centre National d'Etudes Spatiales (CNES)
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

#include "otbWrapperTypes.h"

namespace otb
{
namespace Wrapper
{

std::string ParameterTypeToString(ParameterType type)
{
  for (auto p : parameterTypesStrings)
  {
    if (type == p.first)
    {
      return std::string(p.second);
    }
  }
  itkGenericExceptionMacro("Cannot convert parameter type to string.");
}

ParameterType ParameterStringToType(const std::string& str)
{
  for (auto p : parameterTypesStrings)
  {
    if (str == p.second)
    {
      return p.first;
    }
  }
  itkGenericExceptionMacro("Cannot convert string '" << str << "' to parameter type.");
}
} // namespace Wrapper
} // namespace otb